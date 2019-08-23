/********************************************************************************
** Form generated from reading UI file 'widgetselectdisk.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSELECTDISK_H
#define UI_WIDGETSELECTDISK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSelectDisk
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *btnRefresh;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetSelectDisk)
    {
        if (WidgetSelectDisk->objectName().isEmpty())
            WidgetSelectDisk->setObjectName(QStringLiteral("WidgetSelectDisk"));
        WidgetSelectDisk->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSelectDisk->sizePolicy().hasHeightForWidth());
        WidgetSelectDisk->setSizePolicy(sizePolicy);
        WidgetSelectDisk->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetSelectDisk);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
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

        verticalLayout->addWidget(textEdit);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(100, 100, 100, 100);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1, Qt::AlignVCenter);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        btnRefresh = new QPushButton(verticalLayoutWidget);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        btnRefresh->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy1);
        btnRefresh->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(btnRefresh, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPrev = new QPushButton(verticalLayoutWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnPrev->sizePolicy().hasHeightForWidth());
        btnPrev->setSizePolicy(sizePolicy1);
        btnPrev->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnPrev, 0, Qt::AlignRight|Qt::AlignVCenter);

        btnNext = new QPushButton(verticalLayoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnNext, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WidgetSelectDisk);

        QMetaObject::connectSlotsByName(WidgetSelectDisk);
    } // setupUi

    void retranslateUi(QWidget *WidgetSelectDisk)
    {
        WidgetSelectDisk->setWindowTitle(QApplication::translate("WidgetSelectDisk", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("WidgetSelectDisk", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Select a device path</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">Please insert and select the removable USB device connected to your PC.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\"> </span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">  </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; t"
                        "ext-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:12pt; font-weight:600; color:#ff0000;\">Warning :</span><span style=\" font-family:'Gulim'; font-size:9pt; font-weight:600; color:#ff0000;\"> </span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt; font-weight:600; color:#ff0000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt; font-weight:600; color:#ff0000;\">\342\200\273 All of existing files / OS in the device will be deleted! \342\200\273</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("WidgetSelectDisk", "<html><head/><body><p><span style=\" font-size:11pt;\">Device path</span></p></body></html>", nullptr));
        btnRefresh->setText(QApplication::translate("WidgetSelectDisk", "Refresh", nullptr));
        btnPrev->setText(QApplication::translate("WidgetSelectDisk", "Back", nullptr));
        btnNext->setText(QApplication::translate("WidgetSelectDisk", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSelectDisk: public Ui_WidgetSelectDisk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSELECTDISK_H
