/********************************************************************************
** Form generated from reading UI file 'widgetselectversion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSELECTVERSION_H
#define UI_WIDGETSELECTVERSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSelectVersion
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit;
    QRadioButton *radioPaid;
    QRadioButton *radioFree;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetSelectVersion)
    {
        if (WidgetSelectVersion->objectName().isEmpty())
            WidgetSelectVersion->setObjectName(QStringLiteral("WidgetSelectVersion"));
        WidgetSelectVersion->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSelectVersion->sizePolicy().hasHeightForWidth());
        WidgetSelectVersion->setSizePolicy(sizePolicy);
        WidgetSelectVersion->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget_2 = new QWidget(WidgetSelectVersion);
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
        textEdit->setAutoFormatting(QTextEdit::AutoNone);
        textEdit->setLineWrapMode(QTextEdit::WidgetWidth);
        textEdit->setReadOnly(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(textEdit);

        radioPaid = new QRadioButton(verticalLayoutWidget_2);
        radioPaid->setObjectName(QStringLiteral("radioPaid"));
        sizePolicy1.setHeightForWidth(radioPaid->sizePolicy().hasHeightForWidth());
        radioPaid->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        radioPaid->setFont(font);

        verticalLayout_2->addWidget(radioPaid, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        radioFree = new QRadioButton(verticalLayoutWidget_2);
        radioFree->setObjectName(QStringLiteral("radioFree"));
        sizePolicy1.setHeightForWidth(radioFree->sizePolicy().hasHeightForWidth());
        radioFree->setSizePolicy(sizePolicy1);
        radioFree->setMinimumSize(QSize(242, 22));
        radioFree->setFont(font);

        verticalLayout_2->addWidget(radioFree, 0, Qt::AlignHCenter|Qt::AlignVCenter);

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


        retranslateUi(WidgetSelectVersion);

        QMetaObject::connectSlotsByName(WidgetSelectVersion);
    } // setupUi

    void retranslateUi(QWidget *WidgetSelectVersion)
    {
        WidgetSelectVersion->setWindowTitle(QApplication::translate("WidgetSelectVersion", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("WidgetSelectVersion", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Choose a version of OS</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:12pt; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">If you purchased registered vers"
                        "ion, you can select paid option.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">If not, you can only choose the free version.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        radioPaid->setText(QApplication::translate("WidgetSelectVersion", "OS Registered version (Paid)", nullptr));
        radioFree->setText(QApplication::translate("WidgetSelectVersion", "OS free version", nullptr));
        btnPrev->setText(QApplication::translate("WidgetSelectVersion", "Back", nullptr));
        btnNext->setText(QApplication::translate("WidgetSelectVersion", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSelectVersion: public Ui_WidgetSelectVersion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSELECTVERSION_H
