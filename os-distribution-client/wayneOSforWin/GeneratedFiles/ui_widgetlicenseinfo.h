/********************************************************************************
** Form generated from reading UI file 'widgetlicenseinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETLICENSEINFO_H
#define UI_WIDGETLICENSEINFO_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetLicenseInfo
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QWebView *webView;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetLicenseInfo)
    {
        if (WidgetLicenseInfo->objectName().isEmpty())
            WidgetLicenseInfo->setObjectName(QStringLiteral("WidgetLicenseInfo"));
        WidgetLicenseInfo->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetLicenseInfo->sizePolicy().hasHeightForWidth());
        WidgetLicenseInfo->setSizePolicy(sizePolicy);
        WidgetLicenseInfo->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetLicenseInfo);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        webView = new QWebView(verticalLayoutWidget);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy1);
        webView->setProperty("url", QVariant(QUrl(QStringLiteral("about:blank"))));

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPrev = new QPushButton(verticalLayoutWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        sizePolicy1.setHeightForWidth(btnPrev->sizePolicy().hasHeightForWidth());
        btnPrev->setSizePolicy(sizePolicy1);
        btnPrev->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnPrev, 0, Qt::AlignRight|Qt::AlignBottom);

        btnNext = new QPushButton(verticalLayoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnNext, 0, Qt::AlignLeft|Qt::AlignBottom);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WidgetLicenseInfo);

        QMetaObject::connectSlotsByName(WidgetLicenseInfo);
    } // setupUi

    void retranslateUi(QWidget *WidgetLicenseInfo)
    {
        WidgetLicenseInfo->setWindowTitle(QApplication::translate("WidgetLicenseInfo", "Form", nullptr));
        checkBox->setText(QApplication::translate("WidgetLicenseInfo", "Agree", nullptr));
        btnPrev->setText(QApplication::translate("WidgetLicenseInfo", "Back", nullptr));
        btnNext->setText(QApplication::translate("WidgetLicenseInfo", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetLicenseInfo: public Ui_WidgetLicenseInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETLICENSEINFO_H
