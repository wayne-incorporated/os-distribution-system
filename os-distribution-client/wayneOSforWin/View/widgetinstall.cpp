#define WAYNE_WINAPI 1

#include "widgetinstall.h"
#include "ui_widgetinstall.h"

#include "viewmanager.h"

#include "../Info/infomanager.h"
#include "../View/viewmanager.h"

#include <QMessageBox>
#include <QDir>



WidgetInstall::WidgetInstall(QWidget *parent) : QWidget(parent),ui(new Ui::WidgetInstall)
{
    ui->setupUi(this);
	// ~ Added by LEE Jeun@wayne-inc.com
	idx = 0, cnt = 0, p = 0;
	display = "Downloading Files";
	connect(ViewManager::GetInstance()->timer, SIGNAL(timeout()), this, SLOT(setDynamic()));
	ViewManager::GetInstance()->timer->start(500);
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
	int volumeID = InfoManager::GetInstance()->mVolumeId;
	int deviceID = InfoManager::GetInstance()->mDeviceId;
	//QMessageBox::information(NULL, "ID info123", QString("volumeID = %1, deviceID = %2").arg(volumeID).arg(deviceID));
	/***************************************************************/
	//////////////////////////////////////////////////////////
	hVolume = getHandleOnVolume(volumeID, GENERIC_WRITE);
	if (hVolume == INVALID_HANDLE_VALUE)
	{
		status = STATUS_IDLE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	if (!getLockOnVolume(hVolume))
	{
		CloseHandle(hVolume);
		status = STATUS_IDLE;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	if (!unmountVolume(hVolume))
	{
		removeLockOnVolume(hVolume);
		CloseHandle(hVolume);
		status = STATUS_IDLE;
		hVolume = INVALID_HANDLE_VALUE;
		//btnCancel->setEnabled(false);
		//setReadWriteButtonState();
		return;
	}
	
	QDir dir;
	QString path = dir.absoluteFilePath("updStatus/wayneUpdateFile");
	
	QByteArray charPath = path.toLocal8Bit();
	if (HttpManager::GetInstance()->httpThread.getFileName() != "dummy.img") // Modified by LEE Jeun jeun@wayne-inc.com
	{
		hFile = getHandleOnFile(charPath.data(), GENERIC_READ);
		//hFile = getHandleOnFile("wayneUpdateFile", GENERIC_READ);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			removeLockOnVolume(hVolume);
			CloseHandle(hVolume);
			status = STATUS_IDLE;
			hVolume = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			return;
		}
		hRawDisk = getHandleOnDevice(deviceID, GENERIC_WRITE);
		if (hRawDisk == INVALID_HANDLE_VALUE)
		{
			removeLockOnVolume(hVolume);
			CloseHandle(hFile);
			CloseHandle(hVolume);
			status = STATUS_IDLE;
			hVolume = INVALID_HANDLE_VALUE;
			hFile = INVALID_HANDLE_VALUE;
			//btnCancel->setEnabled(false);
			//setReadWriteButtonState();
			return;
		}
		availablesectors = getNumberOfSectors(hRawDisk, &sectorsize);
		numsectors = getFileSizeInSectors(hFile, sectorsize);
		if (numsectors > availablesectors)
		{
			QMessageBox::critical(NULL, "Write Error", QString::fromLocal8Bit("Not enough space on disk: Size: %1 sectors  Available: %2 sectors  Sector size: %3").arg(numsectors).arg(availablesectors).arg(sectorsize));
			removeLockOnVolume(hVolume);
			CloseHandle(hRawDisk);
			CloseHandle(hFile);
			CloseHandle(hVolume);
			status = STATUS_IDLE;
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
		for (i = 0ul; i < numsectors && status == STATUS_WRITING; i += 1024ul)
		{
			sectorData = readSectorDataFromHandle(hFile, i, (numsectors - i >= 1024ul) ? 1024ul : (numsectors - i), sectorsize);
			if (sectorData == NULL)
			{
				delete sectorData;
				removeLockOnVolume(hVolume);
				CloseHandle(hRawDisk);
				CloseHandle(hFile);
				CloseHandle(hVolume);
				status = STATUS_IDLE;
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
				status = STATUS_IDLE;
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
			QCoreApplication::processEvents();
		}
		removeLockOnVolume(hVolume);
		CloseHandle(hRawDisk);
		CloseHandle(hFile);
		CloseHandle(hVolume);
		sectorData = NULL;
		hRawDisk = INVALID_HANDLE_VALUE;
		hFile = INVALID_HANDLE_VALUE;
		hVolume = INVALID_HANDLE_VALUE;
		ViewManager::GetInstance()->timer->stop(); // Added by LEE Jeun jeun@wayne-inc.com
		ui->progressBar->reset();
	}
	///////////////////
    #endif
	
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
	
	if (status == STATUS_EXIT)
	{
		close();
		
	}
	status = STATUS_IDLE;
}


void WidgetInstall::RequestServerData()
{
	ui->btnNext->setEnabled(false);
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
		HttpManager::GetInstance()->httpThread.updateFile->close();
		try
		{
			this->startInstall();
		}
		catch (std::exception & e)
		{
			qDebug() << "install Fail!";
			this->CompleteUpdateFileDelete();

		}
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
	if (ViewManager::GetInstance()->flag==ViewManager::GetInstance()->DOWNLOAD)
	{
		if (p < 3)
		{
			display += " . ";
			++p;
			ui->labelStatus->setText(display);
		}
		else
		{
			display = "Downloading Files " + QString::number(idx) + " / " + QString::number(cnt);
			p = 0;
			ui->labelStatus->setText(display);
		}
	}
	else
	{
		if (p < 3)
		{
			display += " . ";
			++p;
			ui->labelStatus->setText(display);
		}
		else
		{
			display = "Installing";
			p = 0;
			ui->labelStatus->setText(display);
		}
	}
}
// Added by LEE Jeun jeun@wayne-inc.com
