/********************************************************************************
** Form generated from reading UI file 'stackedwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STACKEDWIDGET_H
#define UI_STACKEDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QStackedWidget>
#include "widgetcomplete.h"
#include "widgetinstall.h"
#include "widgetlicenseinfo.h"
#include "widgetmain.h"
#include "widgetpreparecomplete.h"
#include "widgetselectdisk.h"
#include "widgetselectdisksize.h"
#include "widgetselecttype.h"
#include "widgetselectversion.h"

QT_BEGIN_NAMESPACE

class Ui_StackedWidget
{
public:
    WidgetMain *pageMain;
    WidgetLicenseInfo *pageLicenseInfo;
    WidgetSelectVersion *pageSelectVersion;
    WidgetSelectDisk *pageSelectDisk;
    WidgetSelectType *pageSelectType;
    WidgetSelectDiskSize *pageSelectDiskSize;
    WidgetPrepareComplete *pagePrepareComplete;
    WidgetInstall *pageInstall;
    WidgetComplete *pageComplete;

    void setupUi(QStackedWidget *StackedWidget)
    {
        if (StackedWidget->objectName().isEmpty())
            StackedWidget->setObjectName(QStringLiteral("StackedWidget"));
        StackedWidget->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StackedWidget->sizePolicy().hasHeightForWidth());
        StackedWidget->setSizePolicy(sizePolicy);
        StackedWidget->setMaximumSize(QSize(16777215, 16777215));
        pageMain = new WidgetMain();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        StackedWidget->addWidget(pageMain);
        pageLicenseInfo = new WidgetLicenseInfo();
        pageLicenseInfo->setObjectName(QStringLiteral("pageLicenseInfo"));
        StackedWidget->addWidget(pageLicenseInfo);
        pageSelectVersion = new WidgetSelectVersion();
        pageSelectVersion->setObjectName(QStringLiteral("pageSelectVersion"));
        StackedWidget->addWidget(pageSelectVersion);
        pageSelectDisk = new WidgetSelectDisk();
        pageSelectDisk->setObjectName(QStringLiteral("pageSelectDisk"));
        StackedWidget->addWidget(pageSelectDisk);
        pageSelectType = new WidgetSelectType();
        pageSelectType->setObjectName(QStringLiteral("pageSelectType"));
        StackedWidget->addWidget(pageSelectType);
        pageSelectDiskSize = new WidgetSelectDiskSize();
        pageSelectDiskSize->setObjectName(QStringLiteral("pageSelectDiskSize"));
        StackedWidget->addWidget(pageSelectDiskSize);
        pagePrepareComplete = new WidgetPrepareComplete();
        pagePrepareComplete->setObjectName(QStringLiteral("pagePrepareComplete"));
        StackedWidget->addWidget(pagePrepareComplete);
        pageInstall = new WidgetInstall();
        pageInstall->setObjectName(QStringLiteral("pageInstall"));
        StackedWidget->addWidget(pageInstall);
        pageComplete = new WidgetComplete();
        pageComplete->setObjectName(QStringLiteral("pageComplete"));
        StackedWidget->addWidget(pageComplete);

        retranslateUi(StackedWidget);

        QMetaObject::connectSlotsByName(StackedWidget);
    } // setupUi

    void retranslateUi(QStackedWidget *StackedWidget)
    {
        StackedWidget->setWindowTitle(QApplication::translate("StackedWidget", "StackedWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StackedWidget: public Ui_StackedWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STACKEDWIDGET_H
