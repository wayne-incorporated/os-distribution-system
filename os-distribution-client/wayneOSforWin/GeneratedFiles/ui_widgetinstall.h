/********************************************************************************
** Form generated from reading UI file 'widgetinstall.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETINSTALL_H
#define UI_WIDGETINSTALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetInstall
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *labelStatus;
    QLabel *label_5;
    QProgressBar *progressBar;
    QLabel *label_4;
    QPushButton *btnNext;

    void setupUi(QWidget *WidgetInstall)
    {
        if (WidgetInstall->objectName().isEmpty())
            WidgetInstall->setObjectName(QStringLiteral("WidgetInstall"));
        WidgetInstall->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetInstall->sizePolicy().hasHeightForWidth());
        WidgetInstall->setSizePolicy(sizePolicy);
        WidgetInstall->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetInstall);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 681, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(6);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamily(QStringLiteral("Aharoni"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("Aharoni"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(50, 0, 50, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        labelStatus = new QLabel(verticalLayoutWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        sizePolicy1.setHeightForWidth(labelStatus->sizePolicy().hasHeightForWidth());
        labelStatus->setSizePolicy(sizePolicy1);
        labelStatus->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Black"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        labelStatus->setFont(font2);
        labelStatus->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, labelStatus);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(0, 30));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        formLayout->setWidget(1, QFormLayout::FieldRole, progressBar);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(450, 100));

        gridLayout->addWidget(label_4, 3, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addLayout(gridLayout);

        btnNext = new QPushButton(verticalLayoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy1);
        btnNext->setMinimumSize(QSize(100, 45));

        verticalLayout->addWidget(btnNext, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        retranslateUi(WidgetInstall);

        QMetaObject::connectSlotsByName(WidgetInstall);
    } // setupUi

    void retranslateUi(QWidget *WidgetInstall)
    {
        WidgetInstall->setWindowTitle(QApplication::translate("WidgetInstall", "Form", nullptr));
        label_2->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p align=\"center\">\342\200\273 Please don't remove the device (USB, SSD) </p><p align=\"center\">or disconnect internet while installation is being done. \342\200\273</p></body></html>", nullptr));
        label->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p align=\"center\">Installation</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p><span style=\" font-size:11pt;\">Status :</span></p></body></html>", nullptr));
        labelStatus->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p><span style=\" font-size:11pt;\">Downloading...</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Progress :</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("WidgetInstall", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">Please wait while the OS is being installed.</span></p><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">It may take upto 1~2 hours depending on your hardware &amp; network.</span></p></body></html>", nullptr));
        btnNext->setText(QApplication::translate("WidgetInstall", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetInstall: public Ui_WidgetInstall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETINSTALL_H
