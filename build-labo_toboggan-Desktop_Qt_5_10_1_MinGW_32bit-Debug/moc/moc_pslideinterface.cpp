/****************************************************************************
** Meta object code from reading C++ file 'pslideinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ressources/src/pslideinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pslideinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PSlideInterface_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PSlideInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PSlideInterface_t qt_meta_stringdata_PSlideInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PSlideInterface"
QT_MOC_LITERAL(1, 16, 21), // "sig_consoleAppendText"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "consoleId"
QT_MOC_LITERAL(4, 49, 4), // "text"
QT_MOC_LITERAL(5, 54, 10), // "sig_travel"
QT_MOC_LITERAL(6, 65, 5), // "kidId"
QT_MOC_LITERAL(7, 71, 5), // "step2"
QT_MOC_LITERAL(8, 77, 2), // "ms"
QT_MOC_LITERAL(9, 80, 8) // "sig_play"

    },
    "PSlideInterface\0sig_consoleAppendText\0"
    "\0consoleId\0text\0sig_travel\0kidId\0step2\0"
    "ms\0sig_play"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PSlideInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    3,   34,    2, 0x06 /* Public */,
       9,    2,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    8,

       0        // eod
};

void PSlideInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PSlideInterface *_t = static_cast<PSlideInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_consoleAppendText((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->sig_travel((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->sig_play((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PSlideInterface::*_t)(unsigned int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PSlideInterface::sig_consoleAppendText)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PSlideInterface::*_t)(unsigned int , unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PSlideInterface::sig_travel)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PSlideInterface::*_t)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PSlideInterface::sig_play)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PSlideInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PSlideInterface.data,
      qt_meta_data_PSlideInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PSlideInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PSlideInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PSlideInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PSlideInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void PSlideInterface::sig_consoleAppendText(unsigned int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PSlideInterface::sig_travel(unsigned int _t1, unsigned int _t2, unsigned int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PSlideInterface::sig_play(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
