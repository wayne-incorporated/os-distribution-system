/********************************************************************************
** Form generated from reading UI file 'widgetpreparecomplete.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETPREPARECOMPLETE_H
#define UI_WIDGETPREPARECOMPLETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPrepareComplete
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *editVersion;
    QLabel *label_2;
    QLineEdit *editPath;
    QLabel *label_3;
    QLineEdit *editType;
    QLabel *label_4;
    QLineEdit *editSize;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPrev;
    QPushButton *btnSetup;

    void setupUi(QWidget *WidgetPrepareComplete)
    {
        if (WidgetPrepareComplete->objectName().isEmpty())
            WidgetPrepareComplete->setObjectName(QStringLiteral("WidgetPrepareComplete"));
        WidgetPrepareComplete->resize(701, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetPrepareComplete->sizePolicy().hasHeightForWidth());
        WidgetPrepareComplete->setSizePolicy(sizePolicy);
        WidgetPrepareComplete->setMaximumSize(QSize(16777215, 16777215));
        verticalLayoutWidget = new QWidget(WidgetPrepareComplete);
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
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(100, 10, 100, 10);
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

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        editVersion = new QLineEdit(verticalLayoutWidget);
        editVersion->setObjectName(QStringLiteral("editVersion"));
        editVersion->setEnabled(true);
        sizePolicy1.setHeightForWidth(editVersion->sizePolicy().hasHeightForWidth());
        editVersion->setSizePolicy(sizePolicy1);
        editVersion->setMinimumSize(QSize(0, 30));
        editVersion->setFocusPolicy(Qt::NoFocus);
        editVersion->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, editVersion);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        editPath = new QLineEdit(verticalLayoutWidget);
        editPath->setObjectName(QStringLiteral("editPath"));
        sizePolicy1.setHeightForWidth(editPath->sizePolicy().hasHeightForWidth());
        editPath->setSizePolicy(sizePolicy1);
        editPath->setMinimumSize(QSize(0, 30));
        editPath->setFocusPolicy(Qt::NoFocus);
        editPath->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, editPath);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        editType = new QLineEdit(verticalLayoutWidget);
        editType->setObjectName(QStringLiteral("editType"));
        sizePolicy1.setHeightForWidth(editType->sizePolicy().hasHeightForWidth());
        editType->setSizePolicy(sizePolicy1);
        editType->setMinimumSize(QSize(0, 30));
        editType->setFocusPolicy(Qt::NoFocus);
        editType->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, editType);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        editSize = new QLineEdit(verticalLayoutWidget);
        editSize->setObjectName(QStringLiteral("editSize"));
        sizePolicy1.setHeightForWidth(editSize->sizePolicy().hasHeightForWidth());
        editSize->setSizePolicy(sizePolicy1);
        editSize->setMinimumSize(QSize(0, 30));
        editSize->setFocusPolicy(Qt::NoFocus);
        editSize->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, editSize);


        verticalLayout->addLayout(formLayout);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        sizePolicy1.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
        textEdit_2->setSizePolicy(sizePolicy1);
        textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        textEdit_2->setReadOnly(true);
        textEdit_2->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(textEdit_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(100);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnPrev = new QPushButton(verticalLayoutWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));
        btnPrev->setEnabled(true);
        btnPrev->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnPrev, 0, Qt::AlignRight);

        btnSetup = new QPushButton(verticalLayoutWidget);
        btnSetup->setObjectName(QStringLiteral("btnSetup"));
        btnSetup->setEnabled(true);
        btnSetup->setMinimumSize(QSize(100, 45));

        horizontalLayout->addWidget(btnSetup, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(WidgetPrepareComplete);

        QMetaObject::connectSlotsByName(WidgetPrepareComplete);
    } // setupUi

    void retranslateUi(QWidget *WidgetPrepareComplete)
    {
        WidgetPrepareComplete->setWindowTitle(QApplication::translate("WidgetPrepareComplete", "Form", nullptr));
        textEdit->setHtml(QApplication::translate("WidgetPrepareComplete", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Install preparation completed</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">All data in your device will be removed.</s"
                        "pan></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">Please check your choice again.</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("WidgetPrepareComplete", "<html><head/><body><p><span style=\" font-size:10pt;\">OS type</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("WidgetPrepareComplete", "<html><head/><body><p><span style=\" font-size:10pt;\">Device path</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("WidgetPrepareComplete", "<html><head/><body><p><span style=\" font-size:10pt;\">Device type</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("WidgetPrepareComplete", "<html><head/><body><p><span style=\" font-size:10pt;\">Device capacity</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QApplication::translate("WidgetPrepareComplete", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; color:#ff0000;\">Caution</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Gulim'; font-size:9pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">If you don't choose correctly, </span></p>\n"
"<p "
                        "align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">		</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Gulim'; font-size:9pt;\">OS Installation might not run properly after the installation is completed.</span></p></body></html>", nullptr));
        btnPrev->setText(QApplication::translate("WidgetPrepareComplete", "Back", nullptr));
        btnSetup->setText(QApplication::translate("WidgetPrepareComplete", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPrepareComplete: public Ui_WidgetPrepareComplete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETPREPARECOMPLETE_H
