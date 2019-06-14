/****************************************************************************
** Meta object code from reading C++ file 'httpthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HTTP/httpthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpThread_t {
    QByteArrayData data[15];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpThread_t qt_meta_stringdata_HttpThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HttpThread"
QT_MOC_LITERAL(1, 11, 14), // "DonwloadStatus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "index"
QT_MOC_LITERAL(4, 33, 5), // "count"
QT_MOC_LITERAL(5, 39, 20), // "DownloadDeviceVolume"
QT_MOC_LITERAL(6, 60, 4), // "list"
QT_MOC_LITERAL(7, 65, 13), // "ReplyFinished"
QT_MOC_LITERAL(8, 79, 14), // "QNetworkReply*"
QT_MOC_LITERAL(9, 94, 5), // "reply"
QT_MOC_LITERAL(10, 100, 13), // "RequestOSData"
QT_MOC_LITERAL(11, 114, 13), // "RequestOSFile"
QT_MOC_LITERAL(12, 128, 19), // "ReqeustDeviceVolume"
QT_MOC_LITERAL(13, 148, 8), // "gotReply"
QT_MOC_LITERAL(14, 157, 12) // "networkReply"

    },
    "HttpThread\0DonwloadStatus\0\0index\0count\0"
    "DownloadDeviceVolume\0list\0ReplyFinished\0"
    "QNetworkReply*\0reply\0RequestOSData\0"
    "RequestOSFile\0ReqeustDeviceVolume\0"
    "gotReply\0networkReply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       5,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   57,    2, 0x0a /* Public */,
      10,    0,   60,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,
      12,    0,   62,    2, 0x0a /* Public */,
      13,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QStringList,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,   14,

       0        // eod
};

void HttpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpThread *_t = static_cast<HttpThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DonwloadStatus((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->DownloadDeviceVolume((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->ReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->RequestOSData(); break;
        case 4: _t->RequestOSFile(); break;
        case 5: _t->ReqeustDeviceVolume(); break;
        case 6: _t->gotReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HttpThread::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpThread::DonwloadStatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HttpThread::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpThread::DownloadDeviceVolume)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_HttpThread.data,
      qt_meta_data_HttpThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HttpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int HttpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void HttpThread::DonwloadStatus(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HttpThread::DownloadDeviceVolume(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
