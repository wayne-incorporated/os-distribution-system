#include "widgetselectversion.h"
#include "ui_widgetselectversion.h"

#include "viewmanager.h"

#include "../Info/infomanager.h"
#include "WinDpiScale/WinDpiScale.h"

WidgetSelectVersion::WidgetSelectVersion(QWidget *parent) :QWidget(parent), ui(new Ui::WidgetSelectVersion)
{
    ui->setupUi(this);
	/*ui->textEdit->setFixedSize((int)(windowsDpiScale()*1.5*ui->textEdit->width()), (int)(windowsDpiScale()*1.5*ui->textEdit->height()));
	ui->textEdit->move(QPoint(ui->textEdit->x()*1.5*windowsDpiScale(), ui->textEdit->y()*1.5*windowsDpiScale()));
	ui->verticalLayoutWidget->setFixedSize((int)(windowsDpiScale()*1.5*ui->verticalLayoutWidget->width()), (int)(windowsDpiScale()*1.5*ui->verticalLayoutWidget->height()));
	ui->verticalLayoutWidget->move(QPoint(ui->verticalLayoutWidget->x()*1.5*windowsDpiScale(), ui->verticalLayoutWidget->y()*1.5*windowsDpiScale()));
	ui->btnPrev->setFixedSize((int)(windowsDpiScale()*1.5*ui->btnPrev->width()), (int)(windowsDpiScale()*1.5*ui->btnPrev->height()));
	ui->btnPrev->move(QPoint(ui->btnPrev->x()*1.5*windowsDpiScale(), ui->btnPrev->y()*1.5*windowsDpiScale()));
	ui->btnNext->setFixedSize((int)(windowsDpiScale()*1.5*ui->btnNext->width()), (int)(windowsDpiScale()*1.5*ui->btnNext->height()));
	ui->btnNext->move(QPoint(ui->btnNext->x()*1.5*windowsDpiScale(), ui->btnNext->y()*1.5*windowsDpiScale()));*/
    ui->radioPaid->click();
}



WidgetSelectVersion::~WidgetSelectVersion()
{
    delete ui;
}

void WidgetSelectVersion::on_btnNext_clicked()
{
    if(ui->radioFree->isChecked())
    {
        InfoManager::GetInstance()->mVersionType = InfoManager::FREE;

    }
    else if(ui->radioPaid->isChecked())
    {
        InfoManager::GetInstance()->mVersionType= InfoManager::PAID;
    }


    ViewManager::GetInstance()->SetViewByIndex(ViewManager::WIDGET_SELECTDISK);
}

void WidgetSelectVersion::on_btnPrev_clicked()
{
    ViewManager::GetInstance()->SetViewByIndex(ViewManager::WIDGET_LICENSEINFO);
}
