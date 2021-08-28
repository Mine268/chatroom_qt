/****************************************************************************
** Meta object code from reading C++ file 'addfriend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QQdemo/addfriend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfriend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddFriend_t {
    QByteArrayData data[10];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddFriend_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddFriend_t qt_meta_stringdata_AddFriend = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AddFriend"
QT_MOC_LITERAL(1, 10, 16), // "on_close_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "on_minimize_clicked"
QT_MOC_LITERAL(4, 48, 19), // "on_maximize_clicked"
QT_MOC_LITERAL(5, 68, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 90, 25), // "on_lineEdit_returnPressed"
QT_MOC_LITERAL(7, 116, 18), // "receive_friendlist"
QT_MOC_LITERAL(8, 135, 13), // "QList<People>"
QT_MOC_LITERAL(9, 149, 20) // "close_for_mainWidget"

    },
    "AddFriend\0on_close_clicked\0\0"
    "on_minimize_clicked\0on_maximize_clicked\0"
    "on_pushButton_clicked\0on_lineEdit_returnPressed\0"
    "receive_friendlist\0QList<People>\0"
    "close_for_mainWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddFriend[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,

       0        // eod
};

void AddFriend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddFriend *_t = static_cast<AddFriend *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_close_clicked(); break;
        case 1: _t->on_minimize_clicked(); break;
        case 2: _t->on_maximize_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_lineEdit_returnPressed(); break;
        case 5: _t->receive_friendlist((*reinterpret_cast< QList<People>(*)>(_a[1]))); break;
        case 6: _t->close_for_mainWidget(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddFriend::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_AddFriend.data,
    qt_meta_data_AddFriend,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AddFriend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddFriend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddFriend.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AddFriend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
