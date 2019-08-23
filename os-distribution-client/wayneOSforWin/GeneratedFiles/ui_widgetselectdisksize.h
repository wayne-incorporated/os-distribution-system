/********************************************************************************
** Form generated from reading UI file 'widgetselectdisksize.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSELECTDISKSIZE_H
#define UI_WIDGETSELECTDISKSIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSelectDiskSize
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetSelectDiskSize)
    {
        if (WidgetSelectDiskSize->objectName().isEmpty())
            WidgetSelectDiskSize->setObjectName(QStringLiteral("WidgetSelectDiskSize"));
        WidgetSelectDiskSize->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSelectDiskSize->sizePolicy().hasHeightForWidth());
        WidgetSelectDiskSize->setSizePolicy(sizePolicy);
        WidgetSelectDiskSize->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetSelectDiskSize);
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

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setVerticalSpacing(50);
        formLayout->setContentsMargins(200, 100, 200, 100);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);


        verticalLayout->addLayout(formLayout);

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


        retranslateUi(WidgetSelectDiskSize);

        QMetaObject::connectSlotsByName(WidgetSelectDiskSize);
    } // setupUi

    void retranslateUi(QWidget *WidgetSelectDiskSize)
    {
        WidgetSelectDiskSize->setWindowTitle(QApplication::translate("WidgetSelectDiskSize", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("WidgetSelectDiskSize", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Select a device capacity</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:12pt; font-weight:600;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you choose it, OS by Wayne will be installed fit to the device capacity.</p>\n"
""
                        "<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label->setText(QApplication::translate("WidgetSelectDiskSize", "<html><head/><body><p><span style=\" font-size:11pt;\">Device capacity</span></p></body></html>", nullptr));
        btnPrev->setText(QApplication::translate("WidgetSelectDiskSize", "Back", nullptr));
        btnNext->setText(QApplication::translate("WidgetSelectDiskSize", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSelectDiskSize: public Ui_WidgetSelectDiskSize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSELECTDISKSIZE_H
