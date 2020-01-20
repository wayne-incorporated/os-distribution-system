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


WidgetInstall::WidgetInstall(QWidget *parent) : QWidget(parent),ui(new Ui::WidgetInstall)
{
    ui->setupUi(this);
	// ~ Added by LEE Jeun@wayne-inc.com
	idx = 0, cnt = 0, p = 0;
	display = "Downloading Files";
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

// Merging extract function into installation function. 
// extract and read a partial file, write it on a hard disk, read and write this partial file on USB, and delete a partial file from a hard disk. this is one cycle of this function.
// ~ Modified by LEE Jeun jeun@wayne-inc.com
void WidgetInstall::startInstall()
{
	status = STATUS_WRITING;
	// ~ Added by LEE Jeun@wayne-inc.com
	ViewManager::GetInstance()->timer->stop();
	ViewManager::GetInstance()->flag = ViewManager::GetInstance()->INSTALL;
	ViewManager::GetInstance()->timer->start(500);
	display = "Installing";
	ui->labelStatus->setText(display);

    #if WAYNE_WINAPI
	double mbpersec;
	unsigned long long i, lasti, availablesectors, numsectors;
	/////////////////////////////Lee Test
	//Ui::WidgetSelectDisk *widget_select_disk_ui;
	
	//
	//int volumeID = cboxDevice->currentText().at(1).toAscii() - 'A';
	/*********************************************************/
	//Lee Test, After ¼öÁ¤
	int volumeID = InfoManager::GetInstance()->mVolumeId;
	int deviceID = InfoManager::GetInstance()->mDeviceId;
	//QMessageBox::information(NULL, "ID info123", QString("volumeID = %1, deviceID = %2").arg(volumeID).arg(deviceID));
	/***************************************************************/
	//////////////////////////////////////////////////////////
	hVolume = getHandleOnVolume(volumeID, GENERIC_WRITE);
	if (hVolume == INVALID_HANDLE_VALUE)
	{
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	if (!getLockOnVolume(hVolume))
	{
		CloseHandle(hVolume);
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	if (!unmountVolume(hVolume))
	{
		removeLockOnVolume(hVolume);
		CloseHandle(hVolume);
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	
	hRawDisk = getHandleOnDevice(deviceID, GENERIC_WRITE);
	if (hRawDisk == INVALID_HANDLE_VALUE)
	{
		removeLockOnVolume(hVolume);
		//CloseHandle(hFile);
		CloseHandle(hVolume);
		//status = STATUS_IDLE;
		status = STATUS_EXIT;
		hVolume = INVALID_HANDLE_VALUE;
		//hFile = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}

	i = 0ul, lasti = 0ul;
	availablesectors = getNumberOfSectors(hRawDisk, &sectorsize);
	ui->progressBar->reset();

	unsigned long long totalSz = 0;

	QDir dir;
	QString path = dir.absoluteFilePath("updStatus/" + HttpManager::GetInstance()->httpThread.getFileName());
	QByteArray charPath = path.toLocal8Bit();

	unzFile uf = unzOpen(charPath.toStdString().c_str());

	if (uf == NULL)
	{
		qDebug() << "failed to open .zip file!";

		unzClose(uf);

		status = STATUS_EXIT;

		return;
	}

	if (unzGoToFirstFile(uf) != UNZ_OK)
	{
		qDebug() << "error occured!";

		unzClose(uf);

		status = STATUS_EXIT;

		return;
	}

	unsigned long long curTot = 0;
	
	unz_file_info64 info;
	unzGetCurrentFileInfo64(uf, &info, NULL, 0, NULL, 0, NULL, 0);

	totalSz = info.uncompressed_size;

	qDebug() << "compressed size : " << info.compressed_size << " bytes";
	qDebug() << "uncompressed size : " << info.uncompressed_size << " bytes";

	unsigned long long totalNumsectors = (unsigned long long)info.uncompressed_size / sectorsize;

	ui->progressBar->setRange(0, totalNumsectors);

	unsigned long long partNumber = 0;

	if (unzOpenCurrentFile(uf) != UNZ_OK)
	{
		qDebug() << "error occured!";

		unzCloseCurrentFile(uf);
		unzClose(uf);

		status = STATUS_EXIT;
		
		return;
	}

	const int BUFSIZE = 524288;
	Bytef in[BUFSIZE];
	unsigned long long readSz = 0;

	while (readSz = unzReadCurrentFile(uf, in, BUFSIZE))
	{
		if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->EXIT_EVENT)
		{
			qDebug() << "detect clicking exit button!";

			break;
		}

		if (readSz < 0)
		{
			qDebug() << "error occured!";

			unzCloseCurrentFile(uf);
			unzClose(uf);

			status = STATUS_EXIT;

			return;
		}

		curTot += readSz;

		partNumber = (curTot * 100 / totalSz);

		qDebug() << curTot << "/" << totalSz << " completed...";

		QString uzFilename = "WayneOSfile_part";

		QFile uzf("updStatus/" + uzFilename + QString::number(partNumber));
		uzf.open(QIODevice::WriteOnly);
		
		uzf.write((const char*)in, readSz);

		uzf.close();

		QCoreApplication::processEvents();

		path = dir.absoluteFilePath(QString("updStatus/"));

		QDirIterator it(path, QDirIterator::Subdirectories);

		while (it.hasNext())
		{
			qDebug() << it.next();
			if (it.fileName().toStdString().find("zip") == std::string::npos && it.fileName().toStdString().find(uzFilename.toStdString()) != std::string::npos)
			{
				qDebug() << "OS File : " << it.fileName();
				path = dir.absoluteFilePath(it.filePath());
				break;
			}
		}

		charPath = path.toLocal8Bit();

		hFile = getHandleOnFile(charPath.data(), GENERIC_READ);
		//hFile = getHandleOnFile("wayneUpdateFile", GENERIC_READ);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			removeLockOnVolume(hVolume);
			CloseHandle(hVolume);
			//status = STATUS_IDLE;
			status = STATUS_EXIT;
			hVolume = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			return;
		}

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

		timer.start();

		sectorData = readSectorDataFromHandle(hFile, 0, (totalNumsectors - i >= numsectors) ? numsectors : (totalNumsectors - i), sectorsize);
		
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
		
		if (!writeSectorDataToHandle(hRawDisk, sectorData, i, (totalNumsectors - i >= numsectors) ? numsectors : (totalNumsectors - i), sectorsize))
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
		QCoreApplication::processEvents();
		
		if (timer.elapsed() >= 1000)
		{
			mbpersec = (((double)sectorsize * (i - lasti)) * (1000.0 / timer.elapsed())) / 1024.0 / 1024.0;
			//after make
			//statusbar->showMessage(QString("%1MB/s").arg(mbpersec));
			timer.start();
			lasti = i;
		}
		ui->progressBar->setValue(i);
		CloseHandle(hFile);
		sectorData = NULL;
		hFile = INVALID_HANDLE_VALUE;
		uzf.remove();
		i += numsectors;
		QCoreApplication::processEvents();
	}

	removeLockOnVolume(hVolume);
	CloseHandle(hRawDisk);
	CloseHandle(hVolume);
	hRawDisk = INVALID_HANDLE_VALUE;
	hVolume = INVALID_HANDLE_VALUE;
	unzCloseCurrentFile(uf);
	unzClose(uf);
	ViewManager::GetInstance()->timer->stop();
	ui->progressBar->reset();
    #endif
	
	if (ViewManager::GetInstance()->flag == ViewManager::GetInstance()->EXIT_EVENT)
	{
		this->CompleteUpdateFileDelete();
		QCoreApplication::exit();
	}

	ui->progressBar->hide();
	ui->label_3->hide();
	ui->label_4->hide();
	ui->label_5->hide();
	ui->labelStatus->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	ui->labelStatus->setFont(QFont("Aharoni", 13, QFont::Bold, false));
	ui->labelStatus->setText(QString::fromLocal8Bit("Installation Complete!!"));
	this->CompleteUpdateFileDelete();
	ui->btnNext->setEnabled(true);
	
	status = STATUS_IDLE;
}
// Modified by LEE Jeun jeun@wayne-inc.com ~

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

	if (status == STATUS_EXIT)
	{
		QCoreApplication::exit(-1);
	}
}
// Modified by LEE Jeun jeun@wayne-inc.com ~

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

		else
		{
			display = "Extracting";
		}

		p = 0;
		ui->labelStatus->setText(display);
	}
}

/*int WidgetInstall::extract(const QString& filename) // this is for extracting .zip files.
{
	ViewManager::GetInstance()->flag = ViewManager::GetInstance()->EXTRACT;

	p = 0;

	ui->progressBar->reset();
	ui->progressBar->setRange(0, 100);

	unsigned long long totalSz = 0;

	//QString uzFilename = filename;
	//uzFilename.chop(4);
	//uzFilename += ".bin";

	QDir dir;
	QString path = dir.absoluteFilePath("updStatus/" + filename);
	QByteArray charpath = path.toLocal8Bit();

	//QFile uzf("updStatus/" + uzFilename);
	//uzf.open(QIODevice::WriteOnly);

	unzFile uf = unzOpen(charpath.toStdString().c_str());

	if (uf == NULL)
	{
		qDebug() << "failed to open .zip file!";

		//uzf.close();
		unzClose(uf);

		return -1;
	}

	if (unzGoToFirstFile(uf) != UNZ_OK)
	{
		qDebug() << "error occured!";

		//uzf.close();
		unzClose(uf);

		return -1;
	}

	const int MAX_FILENAME = 256;
	const int MAX_COMMENT = 256;

	unsigned long long curTot = 0;

	char oriFileName[MAX_FILENAME];
	char comment[MAX_COMMENT];

	unz_file_info64 info;
	unzGetCurrentFileInfo64(uf, &info, oriFileName, MAX_FILENAME, NULL, 0, comment, MAX_COMMENT);

	totalSz = info.uncompressed_size;

	qDebug() << "filename : " << oriFileName;
	qDebug() << "comment : " << comment;
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

	const int BUFSIZE = 20480;
	Bytef in[BUFSIZE];
	unsigned long long readSz = 0;

	while (readSz = unzReadCurrentFile(uf, in, BUFSIZE))
	{
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

		QCoreApplication::processEvents();
	}

	qDebug() << "decompression completed : " << filename << " - > " << uzFilename;

	unzCloseCurrentFile(uf);
	uzf.close();
	unzClose(uf);

	return 0;
}*/
// Added by LEE Jeun jeun@wayne-inc.com ~
