#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T15:22:20
#
#-------------------------------------------------
QT       += core
QT       += network
QT       += core gui
QT       += webkit webkitwidgets
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wayneQT
TEMPLATE = app

win32:RC_ICONS += icon.ico

SOURCES += main.cpp\
    View/widgetlicenseinfo.cpp \
    View/widgetinstall.cpp \
    View/widgetselectdisk.cpp \
    View/stackedwidget.cpp \
    View/widgetmain.cpp \
    View/viewmanager.cpp \
    View/widgetselectversion.cpp \
    View/widgetselecttype.cpp \
    View/widgetselectdisksize.cpp \
    View/widgetpreparecomplete.cpp \
    Info/infomanager.cpp \
    HTTP/urlstrings.cpp \
    HTTP/Reqs/reqosdata.cpp \
    HTTP/httpmanager.cpp \
    HTTP/Reqs/reqosfile.cpp \
    HTTP/httpthread.cpp \
    View/CustomControl/titlebar.cpp \
    View/CustomControl/frametitlebar.cpp \
    View/widgetcomplete.cpp \
    HTTP/Reqs/reqdevicevolume.cpp

HEADERS  += \
    View/widgetlicenseinfo.h \
    View/widgetinstall.h \
    View/widgetselectdisk.h \
    View/stackedwidget.h \
    View/widgetmain.h \
    View/viewmanager.h \
    View/widgetselectversion.h \
    View/widgetselecttype.h \
    View/widgetselectdisksize.h \
    View/widgetpreparecomplete.h \
    Info/infomanager.h \
    HTTP/urlstrings.h \
    HTTP/Reqs/reqosdata.h \
    HTTP/httpmanager.h \
    HTTP/httpheaders.h \
    HTTP/Reqs/reqosfile.h \
    HTTP/httpthread.h \
    View/CustomControl/titlebar.h \
    View/CustomControl/frametitlebar.h \
    View/widgetcomplete.h \
    HTTP/Reqs/reqdevicevolume.h

FORMS    += \
    View/widgetlicenseinfo.ui \
    View/widgetinstall.ui \
    View/widgetselectdisk.ui \
    View/stackedwidget.ui \
    View/widgetmain.ui \
    View/widgetselectversion.ui \
    View/widgetselecttype.ui \
    View/widgetselectdisksize.ui \
    View/widgetpreparecomplete.ui \
    View/widgetcomplete.ui

RESOURCES += \
    images.qrc
