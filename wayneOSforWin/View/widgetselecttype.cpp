#include "widgetselecttype.h"
#include "ui_widgetselecttype.h"

#include "viewmanager.h"

#include "../Info/infomanager.h"

#include <QLabel>
WidgetSelectType::WidgetSelectType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSelectType)
{
    ui->setupUi(this);
	/*ui->textEdit->setFixedSize((int)(windowsDpiScale() * 2 * ui->textEdit->width()), (int)(windowsDpiScale() * 2 * ui->textEdit->height()));
	ui->textEdit->move(QPoint(ui->textEdit->x() * 2 * windowsDpiScale(), ui->textEdit->y() * 2 * windowsDpiScale()));
	ui->verticalLayoutWidget->setFixedSize((int)(windowsDpiScale() * 2 * ui->verticalLayoutWidget->width()), (int)(windowsDpiScale() * 2 * ui->verticalLayoutWidget->height()));
	ui->verticalLayoutWidget->move(QPoint(ui->verticalLayoutWidget->x() * 2 * windowsDpiScale(), ui->verticalLayoutWidget->y() * 2 * windowsDpiScale()));
	ui->btnPrev->setFixedSize((int)(windowsDpiScale() * 2 * ui->btnPrev->width()), (int)(windowsDpiScale() * 2 * ui->btnPrev->height()));
	ui->btnPrev->move(QPoint(ui->btnPrev->x() * 2 * windowsDpiScale(), ui->btnPrev->y() * 2 * windowsDpiScale()));
	ui->btnNext->setFixedSize((int)(windowsDpiScale() * 2 * ui->btnNext->width()), (int)(windowsDpiScale() * 2 * ui->btnNext->height()));
	ui->btnNext->move(QPoint(ui->btnNext->x() * 2 * windowsDpiScale(), ui->btnNext->y() * 2 * windowsDpiScale()));*/
	ui->radioUSB->click();
}

WidgetSelectType::~WidgetSelectType()
{
    delete ui;
}

void WidgetSelectType::on_btnPrev_clicked()
{
    ViewManager::GetInstance()->SetViewByIndex(ViewManager::WIDGET_SELECTDISK);
}

void WidgetSelectType::on_btnNext_clicked()
{

    if(ui->radioUSB->isChecked())
    {
        InfoManager::GetInstance()->mDeviceType = InfoManager::USB;
    }
    else if(ui->radioSSD->isChecked())
    {
        InfoManager::GetInstance()->mDeviceType = InfoManager::SSD;

    }
    ViewManager::GetInstance()->SetViewByIndex(ViewManager::WIDGET_SELECTDISKSIZE);
}
