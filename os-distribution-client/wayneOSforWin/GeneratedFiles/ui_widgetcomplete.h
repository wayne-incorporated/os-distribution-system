/********************************************************************************
** Form generated from reading UI file 'widgetcomplete.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETCOMPLETE_H
#define UI_WIDGETCOMPLETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetComplete
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetComplete)
    {
        if (WidgetComplete->objectName().isEmpty())
            WidgetComplete->setObjectName(QStringLiteral("WidgetComplete"));
        WidgetComplete->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetComplete->sizePolicy().hasHeightForWidth());
        WidgetComplete->setSizePolicy(sizePolicy);
        WidgetComplete->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetComplete);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setAlignment(Qt::AlignJustify|Qt::AlignTop);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        sizePolicy1.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy1);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Sunken);
        textBrowser->setLineWidth(0);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textBrowser->setOpenExternalLinks(true);

        verticalLayout->addWidget(textBrowser, 0, Qt::AlignVCenter);

        verticalSpacer = new QSpacerItem(0, 100, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        btnNext = new QPushButton(verticalLayoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(100, 45));

        verticalLayout->addWidget(btnNext, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(WidgetComplete);

        QMetaObject::connectSlotsByName(WidgetComplete);
    } // setupUi

    void retranslateUi(QWidget *WidgetComplete)
    {
        WidgetComplete->setWindowTitle(QApplication::translate("WidgetComplete", "Form", nullptr));
        label->setText(QString());
        textBrowser->setHtml(QApplication::translate("WidgetComplete", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Installation successful!!</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Congraturation!</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">The software was installed successfully.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">For more information on OS by Wayne, </span><a href=\"http://www.wayne-inc.com\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">Click here</span></a></p></body></html>", nullptr));
        btnNext->setText(QApplication::translate("WidgetComplete", "Finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetComplete: public Ui_WidgetComplete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETCOMPLETE_H
