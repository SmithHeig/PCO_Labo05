/****************************************************************************
** Meta object code from reading C++ file 'display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ressources/src/display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KidItem_t {
    QByteArrayData data[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KidItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KidItem_t qt_meta_stringdata_KidItem = {
    {
QT_MOC_LITERAL(0, 0, 7), // "KidItem"
QT_MOC_LITERAL(1, 8, 3) // "pos"

    },
    "KidItem\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KidItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       1,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void KidItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        KidItem *_t = static_cast<KidItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        KidItem *_t = static_cast<KidItem *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject KidItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KidItem.data,
      qt_meta_data_KidItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KidItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KidItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KidItem.stringdata0))
        return static_cast<void*>(const_cast< KidItem*>(this));
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(const_cast< KidItem*>(this));
    return QObject::qt_metacast(_clname);
}

int KidItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
struct qt_meta_stringdata_TobogganDisplay_t {
    QByteArrayData data[11];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TobogganDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TobogganDisplay_t qt_meta_stringdata_TobogganDisplay = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TobogganDisplay"
QT_MOC_LITERAL(1, 16, 6), // "setKid"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "step"
QT_MOC_LITERAL(4, 29, 5), // "kidId"
QT_MOC_LITERAL(5, 35, 6), // "travel"
QT_MOC_LITERAL(6, 42, 5), // "KidId"
QT_MOC_LITERAL(7, 48, 5), // "step2"
QT_MOC_LITERAL(8, 54, 2), // "ms"
QT_MOC_LITERAL(9, 57, 4), // "play"
QT_MOC_LITERAL(10, 62, 17) // "finishedAnimation"

    },
    "TobogganDisplay\0setKid\0\0step\0kidId\0"
    "travel\0KidId\0step2\0ms\0play\0finishedAnimation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TobogganDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       5,    3,   39,    2, 0x0a /* Public */,
       9,    2,   46,    2, 0x0a /* Public */,
      10,    0,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,    6,    7,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    6,    8,
    QMetaType::Void,

       0        // eod
};

void TobogganDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TobogganDisplay *_t = static_cast<TobogganDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setKid((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->travel((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->play((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->finishedAnimation(); break;
        default: ;
        }
    }
}

const QMetaObject TobogganDisplay::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_TobogganDisplay.data,
      qt_meta_data_TobogganDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TobogganDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TobogganDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TobogganDisplay.stringdata0))
        return static_cast<void*>(const_cast< TobogganDisplay*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int TobogganDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
