/****************************************************************************
** Meta object code from reading C++ file 'friendlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QQdemo/friendlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendList_t {
    QByteArrayData data[15];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendList_t qt_meta_stringdata_FriendList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FriendList"
QT_MOC_LITERAL(1, 11, 15), // "closeMainWidget"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "sign_re"
QT_MOC_LITERAL(4, 36, 14), // "on_add_clicked"
QT_MOC_LITERAL(5, 51, 18), // "on_setting_clicked"
QT_MOC_LITERAL(6, 70, 16), // "on_close_clicked"
QT_MOC_LITERAL(7, 87, 19), // "on_minimize_clicked"
QT_MOC_LITERAL(8, 107, 17), // "on_search_clicked"
QT_MOC_LITERAL(9, 125, 31), // "on_treeWidget_itemDoubleClicked"
QT_MOC_LITERAL(10, 157, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(11, 174, 4), // "item"
QT_MOC_LITERAL(12, 179, 6), // "column"
QT_MOC_LITERAL(13, 186, 19), // "on_maximize_clicked"
QT_MOC_LITERAL(14, 206, 7) // "restore"

    },
    "FriendList\0closeMainWidget\0\0sign_re\0"
    "on_add_clicked\0on_setting_clicked\0"
    "on_close_clicked\0on_minimize_clicked\0"
    "on_search_clicked\0on_treeWidget_itemDoubleClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "on_maximize_clicked\0restore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    2,   71,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FriendList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FriendList *_t = static_cast<FriendList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeMainWidget(); break;
        case 1: _t->sign_re(); break;
        case 2: _t->on_add_clicked(); break;
        case 3: _t->on_setting_clicked(); break;
        case 4: _t->on_close_clicked(); break;
        case 5: _t->on_minimize_clicked(); break;
        case 6: _t->on_search_clicked(); break;
        case 7: _t->on_treeWidget_itemDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->on_maximize_clicked(); break;
        case 9: _t->restore(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FriendList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FriendList::closeMainWidget)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FriendList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FriendList::sign_re)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FriendList::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_FriendList.data,
    qt_meta_data_FriendList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FriendList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FriendList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FriendList::closeMainWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FriendList::sign_re()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
