#define WAYNE_WINAPI 1

#include "widgetinstall.h"
#include "ui_widgetinstall.h"

#include "viewmanager.h"

#include "../Info/infomanager.h"
#include "../View/viewmanager.h"

#include <QMessageBox>
#include <QDir>
#include <QDirIterator>
#include <QStringList>
#include "formatusb.h"


WidgetInstall::WidgetInstall(QWidget *parent) : QWidget(parent),ui(new Ui::WidgetInstall)
{
    ui->setupUi(this);
	// ~ Added by LEE Jeun@wayne-inc.com
	idx = 0, cnt = 0, p = 0;
	//display = "Downloading Files";
	connect(ViewManager::GetInstance()->timer, SIGNAL(timeout()), this, SLOT(setDynamic()));
	//ViewManager::GetInstance()->timer->start(500);
	// Added by LEE Jeun@wayne-inc.com
	status = STATUS_IDLE;
	ui->progressBar->reset();
	hVolume = INVALID_HANDLE_VALUE;
	hFile = INVALID_HANDLE_VALUE;
	hRawDisk = INVALID_HANDLE_VALUE;
	sectorData = NULL;
	sectorsize = 0ul;
}

WidgetInstall::~WidgetInstall()
{
    delete ui;
}
Ui::WidgetInstall* WidgetInstall::getUI()
{
	return ui;
}
void WidgetInstall::on_btnNext_clicked()
{
	ViewManager::GetInstance()->SetViewByIndex(ViewManager::WIDGET_COMPLETE);

}


void WidgetInstall::startInstall()
{
	DWORD size;
	BOOL bResult = FALSE;
	char driveName[4];
	char volumeName[MAX_PATH];
	status = STATUS_WRITING;
	// ~ Added by LEE Jeun@wayne-inc.com
	ViewManager::GetInstance()->timer->stop();
	ViewManager::GetInstance()->flag = ViewManager::GetInstance()->INSTALL;
	// Added by LEE Jeun@wayne-inc.com

    #if WAYNE_WINAPI
	double mbpersec;
	unsigned long long i, lasti, availablesectors, numsectors;
	/////////////////////////////Lee Test
	//Ui::WidgetSelectDisk *widget_select_disk_ui;
	
	//
	//int volumeID = cboxDevice->currentText().at(1).toAscii() - 'A';
	/*********************************************************/
	//Lee Test, After ¼öÁ¤
	//int volumeID = InfoManager::GetInstance()->mVolumeId;
	int deviceID = InfoManager::GetInstance()->mDeviceId;

	hRawDisk = getHandleOnDevice(deviceID, GENERIC_WRITE | GENERIC_READ);

	if (hRawDisk == INVALID_HANDLE_VALUE)
	{
		qDebug("Could not get handle from device!");
		status = STATUS_EXIT;
		return;
	}

	/*if (!getLockOnVolume(hRawDisk))
	{
		qDebug("Could not lock volume on device!");
		status = STATUS_EXIT;
		CloseHandle(hRawDisk);
		hRawDisk = INVALID_HANDLE_VALUE;
		return;
	}*/

	bResult = DeviceIoControl(hRawDisk, IOCTL_DISK_UPDATE_PROPERTIES, NULL, 0, NULL, 0, &size, NULL);
	//QMessageBox::information(NULL, "ID info123", QString("volumeID = %1, deviceID = %2").arg(volumeID).arg(deviceID));
	/***************************************************************/
	//////////////////////////////////////////////////////////
	//hVolume = getHandleOnVolume(volumeID, GENERIC_WRITE);
	//volume_name = getLogicalName(deviceID, 0, TRUE);
	volume_name = AltGetLogicalName(deviceID, 0, TRUE);
	memset(volumeName, 0, sizeof(volumeName));

	if (volume_name.empty())
	{
		qDebug("Could not find volume GUID!");
		CloseHandle(hRawDisk);
		hRawDisk = INVALID_HANDLE_VALUE;
		status = STATUS_EXIT;
		return;
	}

	strncpy(volumeName, volume_name.c_str(), volume_name.size());
	volumeName[strlen(volumeName) - 1] = 0;
	hVolume = CreateFileA(volumeName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, 0, NULL);

	if (hVolume == INVALID_HANDLE_VALUE)
	{
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		CloseHandle(hRawDisk);
		hRawDisk = INVALID_HANDLE_VALUE;
		return;
	}
	if (!getLockOnVolume(hVolume))
	{
		CloseHandle(hRawDisk);
		CloseHandle(hVolume);
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		hRawDisk = INVALID_HANDLE_VALUE;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	if (!unmountVolume(hVolume))
	{
		removeLockOnVolume(hVolume);
		CloseHandle(hRawDisk);
		CloseHandle(hVolume);
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		hRawDisk = INVALID_HANDLE_VALUE;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	
	// ~ Added by LEE Jeun jeun@wayne-inc.com
	//QString extracted = HttpManager::GetInstance()->httpThread.getFileName();
	//extracted.chop(4);
	//extracted += ".bin";
	QDir dir;
	QString path = dir.absoluteFilePath(QString("updStatus/"));
	QString withoutExtension = HttpManager::GetInstance()->httpThread.getFileName();
	withoutExtension.chop(4);
	//QString extracted;
	QDirIterator it(path, QDirIterator::Subdirectories);
	while (it.hasNext())
	{
		qDebug() << it.next();
		if (it.fileName().toStdString().find("zip") == std::string::npos && it.fileName().toStdString().find(withoutExtension.toStdString()) != std::string::npos)
		{
			qDebug() << "OS File : " << it.fileName();
			//extracted = it.fileName();
			path = dir.absoluteFilePath(it.filePath());
			break;
		}
	}
	// Added by LEE Jeun jeun@wayne-inc.com

	//QDir dir;
	//path = dir.absoluteFilePath(QString("updStatus/") + QString(extracted.toStdString().c_str())); // ~ Modified by LEE Jeun jeun@wayne-inc.com
	
	QByteArray charPath = path.toLocal8Bit();

	if (HttpManager::GetInstance()->httpThread.getFileName() != "dummy.img") // Modified by LEE Jeun jeun@wayne-inc.com
	{
		hFile = getHandleOnFile(charPath.data(), GENERIC_READ);
		//hFile = getHandleOnFile("wayneUpdateFile", GENERIC_READ);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			removeLockOnVolume(hVolume);
			CloseHandle(hRawDisk);
			CloseHandle(hVolume);
			//status = STATUS_IDLE;
			status = STATUS_EXIT;
			hRawDisk = INVALID_HANDLE_VALUE;
			hVolume = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			return;
		}
		/*hRawDisk = getHandleOnDevice(deviceID, GENERIC_WRITE);
		if (hRawDisk == INVALID_HANDLE_VALUE)
		{
			removeLockOnVolume(hVolume);
			CloseHandle(hRawDisk);
			CloseHandle(hFile);
			CloseHandle(hVolume);
			//status = STATUS_IDLE;
			status = STATUS_EXIT;
			hRawDisk = INVALID_HANDLE_VALUE;
			hVolume = INVALID_HANDLE_VALUE;
			hFile = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			
			return;
		}*/
		availablesectors = getNumberOfSectors(hRawDisk, &sectorsize);
		numsectors = getFileSizeInSectors(hFile, sectorsize);
		if (numsectors > availablesectors)
		{
			QMessageBox::critical(NULL, "Write Error", QString::fromLocal8Bit("Not enough space on disk: Size: %1 sectors  Available: %2 sectors  Sector size: %3").arg(numsectors).arg(availablesectors).arg(sectorsize));
			removeLockOnVolume(hVolume);
			CloseHandle(hRawDisk);
			CloseHandle(hFile);
			CloseHandle(hVolume);
			//status = STATUS_IDLE;
			status = STATUS_EXIT;
			hVolume = INVALID_HANDLE_VALUE;
			hFile = INVALID_HANDLE_VALUE;
			hRawDisk = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			return;
		}

		ui->progressBar->setRange(0, (numsectors == 0ul) ? 100 : (int)numsectors);
		lasti = 0ul;
		timer.start();
		// ~ Added by LEE Jeun@wayne-inc.com
		ViewManager::GetInstance()->timer->start(500);
		display = "Installing";
		ui->labelStatus->setText(display);
		// Added by LEE Jeun@wayne-inc.com ~
		for (i = 0ul; i < numsectors && status == STATUS_WRITING && ViewManager::GetInstance()->flag == ViewManager::GetInstance()->INSTALL; i += 1024ul)
		{
			QCoreApplication::processEvents();

			sectorData = readSectorDataFromHandle(hFile, i, (numsectors - i >= 1024ul) ? 1024ul : (numsectors - i), sectorsize);
			if (sectorData == NULL)
			{
				delete sectorData;
				removeLockOnVolume(hVolume);
				CloseHandle(hRawDisk);
				CloseHandle(hFile);
				CloseHandle(hVolume);
				//status = STATUS_IDLE;
				status = STATUS_EXIT;
				sectorData = NULL;
				hRawDisk = INVALID_HANDLE_VALUE;
				hFile = INVALID_HANDLE_VALUE;
				hVolume = INVALID_HANDLE_VALUE;
				//btnCancel->setEnabled(false);
				//setReadWriteButtonState();
				return;
			}
			if (!writeSectorDataToHandle(hRawDisk, sectorData, i, (numsectors - i >= 1024ul) ? 1024ul : (numsectors - i), sectorsize))
			{
				delete sectorData;
				removeLockOnVolume(hVolume);
				CloseHandle(hRawDisk);
				CloseHandle(hFile);
				CloseHandle(hVolume);
				//status = STATUS_IDLE;
				status = STATUS_EXIT;
				sectorData = NULL;
				hRawDisk = INVALID_HANDLE_VALUE;
				hFile = INVALID_HANDLE_VALUE;
				hVolume = INVALID_HANDLE_VALUE;
				//btnCancel->setEnabled(false);
				//setReadWriteButtonState();
				return;
			}
			delete sectorData;
			sectorData = NULL;
			if (timer.elapsed() >= 1000)
			{
				mbpersec = (((double)sectorsize * (i - lasti)) * (1000.0 / timer.elapsed())) / 1024.0 / 1024.0;
				//after make
		  //statusbar->showMessage(QString("%1MB/s").arg(mbpersec));
				timer.start();
				lasti = i;
			}
			ui->progressBar->setValue(i);
		}

		bResult = DeviceIoControl(hRawDisk, IOCTL_DISK_UPDATE_PROPERTIES, NULL, 0, NULL, 0, &size, NULL);

		removeLockOnVolume(hVolume);
		CloseHandle(hVolume);
		CloseHandle(hRawDisk);
		hVolume = INVALID_HANDLE_VALUE;
		hRawDisk = INVALID_HANDLE_VALUE;
		Sleep(200);

		volume_name = getLogicalName(deviceID, 0, TRUE);
		//volume_name = AltGetLogicalName(deviceID, 0, TRUE);
		memset(volumeName, 0, sizeof(volumeName));
		strncpy(volumeName, volume_name.c_str(), volume_name.size());
		memset(driveName, 0, sizeof(driveName));
		strncpy(driveName, drive_name.c_str(), drive_name.size());
		bResult = MountVolume(driveName, volumeName);

		if (bResult)
		{
			qDebug("volume mounted as %s", driveName);
		}

		else
		{
			qDebug("Installation is completed but unable to mount volume: Could not get volume GUID!");
			QMessageBox::warning(NULL, "warning", "Installation is completed but unable to mount volume: Could not get volume GUID!");
		}
		
		//removeLockOnVolume(hVolume);
		//CloseHandle(hRawDisk);
		CloseHandle(hFile);
		//CloseHandle(hVolume);
		sectorData = NULL;
		//hRawDisk = INVALID_HANDLE_VALUE;
		hFile = INVALID_HANDLE_VALUE;
		//hVolume = INVALID_HANDLE_VALUE;

		ViewManager::GetInstance()->timer->stop(); // Added by LEE Jeun jeun@wayne-inc.com
		ui->progressBar->reset();
	}
	///////////////////
    #endif
	
	if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->EXIT_EVENT)
	{
		QCoreApplication::exit();
	}

	// ~ Modified and Added by LEE jeun jeun@wayne-inc.com
	ui->progressBar->hide();
	ui->label_3->hide();
	ui->label_4->hide();
	ui->label_5->hide();
	ui->labelStatus->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	ui->labelStatus->setFont(QFont("Aharoni", 13, QFont::Bold, false));
	ui->labelStatus->setText(QString::fromLocal8Bit("Installation Complete!!"));
	// Modified and Added by LEE jeun jeun@wayne-inc.com ~
	this->CompleteUpdateFileDelete();
	ui->btnNext->setEnabled(true);
	
	/*if (status == STATUS_EXIT)
	{
		close();
		
	}*/
	status = STATUS_IDLE;
}


void WidgetInstall::RequestServerData()
{
	ui->btnNext->setEnabled(false);
	// ~ Added by LEE Jeun jeun@wayne-inc.com
	p = 0;
	ViewManager::GetInstance()->timer->start(500);
	// Added by LEE JEun jeun@wayne-inc.com ~
	QObject::connect(&(HttpManager::GetInstance()->httpThread), SIGNAL(DonwloadStatus(int, int)), this, SLOT(DonwloadStatus(int, int)));
	HttpManager::GetInstance()->RequestOSData();
}

// ~ Modified by LEE Jeun@wayne-inc.com
//from Http Thread
void WidgetInstall::DonwloadStatus(int index, int count)
{
	if (index < count)
	{
		idx = index;
		cnt = count;
		//QString status = "Downloading Files... " + QString::number(index) + " / " + QString::number(count);
		display = "Downloading Files " + QString::number(idx) + " / " + QString::number(cnt);
		switch (p)
		{
		case 1:
			display += " . ";
			break;
		case 2:
			display += " . . ";
			break;
		case 3:
			display += " . . . ";
			break;
		}
		ui->progressBar->setValue(index * 100 / count);
		//ui->labelStatus->setText(status);
		ui->labelStatus->setText(display);
	}
	else if (index == count)
	{
		qDebug() << "FileDownload End";
		//QString status = "Installing...";
		//ui->labelStatus->setText(display);
		//Write logic call...
		// ~ Added by LEE Jeun jeun@wayne-inc.com

		display = "Extracting";
		ui->labelStatus->setText(display);

		QString filename = HttpManager::GetInstance()->httpThread.getFileName();

		if (filename == "dummy.img")
		{
			try
			{
				this->startInstall();
			}
			catch (std::exception & e)
			{
				qDebug() << "install Fail!";
				this->CompleteUpdateFileDelete();
				status = STATUS_EXIT;
			}
		}

		else
		{
			int result = extract(filename);

			if (result == -1)
			{
				QMessageBox::critical(NULL, "Error", "can not extract downloaded file!");
				//QApplication::exit(-1);
				status = STATUS_EXIT;
			}
			// Added by LEE Jeun jeun@wayne-inc.com ~
			
			else if (result == 1)
			{
				this->CompleteUpdateFileDelete();

				QCoreApplication::exit();
			}

			else
			{
				try
				{
					int deviceId = InfoManager::GetInstance()->mDeviceId;

					display = "Format USB...";
					ui->labelStatus->setText(display);
					ViewManager::GetInstance()->flag = ViewManager::GetInstance()->FORMAT;
					ui->progressBar->reset();

					if (getVds(deviceId, drive_name) == -1)
					{
						QMessageBox::critical(NULL, "error", "Could not format USB!");
						status = STATUS_EXIT;
					}

					this->startInstall();
				}
				catch (std::exception & e)
				{
					qDebug() << "install Fail!";
					this->CompleteUpdateFileDelete();
					status = STATUS_EXIT;
				}
			}
		}
	}

	if (status == STATUS_EXIT)
	{
		QMessageBox::critical(NULL, "error", "error occured while installing!");
		QCoreApplication::exit(-1);
	}
}
// Modified by LEE Jeun jeun@wayne-inc.com

void WidgetInstall::CompleteUpdateFileDelete()
{
	if (QFile::exists("updStatus"))
	{
		qDebug() << "file exists..and delete";
		QDir dir("updStatus");
		dir.removeRecursively();

	}
}

// ~ Added by LEE Jeun jeun@wayne-inc.com
void
WidgetInstall::setDynamic()
{
	if (p < 3)
	{
		display += " . ";
		++p;
		ui->labelStatus->setText(display);
	}

	else
	{
		if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->DOWNLOAD)
		{
			display = "Downloading Files " 
				+ QString::number(idx) + " / " + QString::number(cnt);
		}

		else if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->INSTALL)
		{
			display = "Installing";
		}

		else if(ViewManager::GetInstance()->flag == ViewManager::GetInstance()->EXTRACT)
		{
			display = "Extracting";
		}

		else
		{
			display = "Format USB";
		}

		p = 0;
		ui->labelStatus->setText(display);
	}
}

int WidgetInstall::extract(const QString& filename) // this is for extracting .zip files.
{
	ViewManager::GetInstance()->flag = ViewManager::GetInstance()->EXTRACT;

	p = 0;

	ui->progressBar->reset();
	ui->progressBar->setRange(0, 100);

	unsigned long long totalSz = 0;

	QDir dir;
	QString path = dir.absoluteFilePath("updStatus/" + filename);
	QByteArray charpath = path.toLocal8Bit();

	unzFile uf = unzOpen(charpath.toStdString().c_str());

	if (uf == NULL)
	{
		qDebug() << "failed to open .zip file!";
		unzClose(uf);

		return -1;
	}

	if (unzGoToFirstFile(uf) != UNZ_OK)
	{
		qDebug() << "error occured!";
		unzClose(uf);

		return -1;
	}

	const int MAX_FILENAME = 256;
	//const int MAX_COMMENT = 256;

	unsigned long long curTot = 0;

	char oriFileName[MAX_FILENAME];
	//char comment[MAX_COMMENT];

	unz_file_info64 info = { 0, };
	unzGetCurrentFileInfo64(uf, &info, oriFileName, MAX_FILENAME, NULL, 0, NULL, 0);

	totalSz = info.uncompressed_size;

	qDebug() << "filename : " << oriFileName;
	//qDebug() << "comment : " << comment;
	qDebug() << "compressed size : " << info.compressed_size << " bytes";
	qDebug() << "uncompressed size : " << info.uncompressed_size << " bytes";

	QString uzFilename = oriFileName;

	QFile uzf("updStatus/" + uzFilename);
	uzf.open(QIODevice::WriteOnly);

	if (unzOpenCurrentFile(uf) != UNZ_OK)
	{
		qDebug() << "error occured!";

		uzf.close();
		unzClose(uf);

		return -1;
	}

	const int BUFSIZE = 204800;
	Bytef in[BUFSIZE];
	unsigned long long readSz = 0;

	while (readSz = unzReadCurrentFile(uf, in, BUFSIZE))
	{
		QCoreApplication::processEvents();

		if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->EXIT_EVENT)
		{
			qDebug() << "detect clicking exit button!";

			unzCloseCurrentFile(uf);
			uzf.close();
			unzClose(uf);

			return 1;
		}

		if (readSz < 0)
		{
			qDebug() << "error occured!";

			unzCloseCurrentFile(uf);
			uzf.close();
			unzClose(uf);

			return -1;
		}

		uzf.write((const char*)in, readSz);

		curTot += readSz;

		qDebug() << curTot << "/" << totalSz << " completed...";

		ui->progressBar->setValue((100 * curTot) / totalSz);
	}

	qDebug() << "decompression completed : " << filename << " - > " << uzFilename;

	unzCloseCurrentFile(uf);
	uzf.close();
	unzClose(uf);

	return 0;
}
// Added by LEE Jeun jeun@wayne-inc.com ~
