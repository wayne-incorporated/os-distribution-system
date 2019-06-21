/********************************************************************************
** Form generated from reading UI file 'widgetmain.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETMAIN_H
#define UI_WIDGETMAIN_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetMain
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWebView *webView;
    QPushButton *btnStart;

    void setupUi(QWidget *WidgetMain)
    {
        if (WidgetMain->objectName().isEmpty())
            WidgetMain->setObjectName(QStringLiteral("WidgetMain"));
        WidgetMain->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetMain->sizePolicy().hasHeightForWidth());
        WidgetMain->setSizePolicy(sizePolicy);
        WidgetMain->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetMain);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(70);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        webView = new QWebView(verticalLayoutWidget);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy1);
        webView->setStyleSheet(QStringLiteral(""));
        webView->setProperty("url", QVariant(QUrl(QStringLiteral("about:blank"))));

        verticalLayout->addWidget(webView);

        btnStart = new QPushButton(verticalLayoutWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setEnabled(false);
        sizePolicy1.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy1);
        btnStart->setMinimumSize(QSize(100, 45));

        verticalLayout->addWidget(btnStart, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(WidgetMain);

        QMetaObject::connectSlotsByName(WidgetMain);
    } // setupUi

    void retranslateUi(QWidget *WidgetMain)
    {
        WidgetMain->setWindowTitle(QApplication::translate("WidgetMain", "Form", nullptr));
        btnStart->setText(QApplication::translate("WidgetMain", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetMain: public Ui_WidgetMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETMAIN_H
