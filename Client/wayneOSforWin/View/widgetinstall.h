#ifndef WIDGETINSTALL_H
#define WIDGETINSTALL_H

#include <QWidget>

#include <QtGui>

#include "ui_widgetinstall.h"
#include <windows.h>

#include "../Disk/disk.h"
//#include "md5.h"
#include "../HTTP/httpmanager.h"

namespace Ui {
class WidgetInstall;
}

class WidgetInstall : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetInstall(QWidget *parent = 0);
	//Lee Add

	Ui::WidgetInstall *getUI();

	void startInstall();
	void RequestServerData();
	void CompleteUpdateFileDelete();

	enum Status {STATUS_IDLE=0, STATUS_READING, STATUS_WRITING, STATUS_EXIT};

    ~WidgetInstall();

private slots:
    void on_btnNext_clicked();
public slots:
	void DonwloadStatus(int index, int count);
	void setDynamic(); // Added by LEE Jeun@wayne-inc.com
private:
    Ui::WidgetInstall *ui;

	HANDLE hVolume;
	HANDLE hFile;
	HANDLE hRawDisk;
	unsigned long long sectorsize;
	int status;
	char *sectorData;
	QTime timer;
	// ~ Added by LEE Jeun@wayne-inc.com
	QString display;
	int p;
	int idx;
	int cnt;
	// Added by LEE Jeun@wayne-inc.com ~
};

#endif // WIDGETINSTALL_H