/********************************************************************************
** Form generated from reading UI file 'widgetselecttype.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSELECTTYPE_H
#define UI_WIDGETSELECTTYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSelectType
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QRadioButton *radioUSB;
    QRadioButton *radioSSD;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetSelectType)
    {
        if (WidgetSelectType->objectName().isEmpty())
            WidgetSelectType->setObjectName(QStringLiteral("WidgetSelectType"));
        WidgetSelectType->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSelectType->sizePolicy().hasHeightForWidth());
        WidgetSelectType->setSizePolicy(sizePolicy);
        WidgetSelectType->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget_2 = new QWidget(WidgetSelectType);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(100);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(textEdit);

        radioUSB = new QRadioButton(verticalLayoutWidget_2);
        radioUSB->setObjectName(QStringLiteral("radioUSB"));
        sizePolicy1.setHeightForWidth(radioUSB->sizePolicy().hasHeightForWidth());
        radioUSB->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        radioUSB->setFont(font);

        verticalLayout_2->addWidget(radioUSB, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        radioSSD = new QRadioButton(verticalLayoutWidget_2);
        radioSSD->setObjectName(QStringLiteral("radioSSD"));
        sizePolicy1.setHeightForWidth(radioSSD->sizePolicy().hasHeightForWidth());
        radioSSD->setSizePolicy(sizePolicy1);
        radioSSD->setMinimumSize(QSize(143, 22));
        radioSSD->setFont(font);

        verticalLayout_2->addWidget(radioSSD, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPrev = new QPushButton(verticalLayoutWidget_2);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnPrev->sizePolicy().hasHeightForWidth());
        btnPrev->setSizePolicy(sizePolicy1);
        btnPrev->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnPrev, 0, Qt::AlignRight|Qt::AlignVCenter);

        btnNext = new QPushButton(verticalLayoutWidget_2);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnNext, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(WidgetSelectType);

        QMetaObject::connectSlotsByName(WidgetSelectType);
    } // setupUi

    void retranslateUi(QWidget *WidgetSelectType)
    {
        WidgetSelectType->setWindowTitle(QApplication::translate("WidgetSelectType", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("WidgetSelectType", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Select a device type</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:12pt; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Choose the type of your device</p></body></html>", nullptr));
        radioUSB->setText(QApplication::translate("WidgetSelectType", "USB Flash Drive", nullptr));
        radioSSD->setText(QApplication::translate("WidgetSelectType", "SSD", nullptr));
        btnPrev->setText(QApplication::translate("WidgetSelectType", "Back", nullptr));
        btnNext->setText(QApplication::translate("WidgetSelectType", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSelectType: public Ui_WidgetSelectType {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSELECTTYPE_H
