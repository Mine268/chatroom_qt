/****************************************************************************
** Meta object code from reading C++ file 'signindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QQdemo/signindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'signindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_signinDialog_t {
    QByteArrayData data[11];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_signinDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_signinDialog_t qt_meta_stringdata_signinDialog = {
    {
QT_MOC_LITERAL(0, 0, 12), // "signinDialog"
QT_MOC_LITERAL(1, 13, 12), // "okToRegister"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "closeDialog"
QT_MOC_LITERAL(4, 39, 17), // "on_cancel_clicked"
QT_MOC_LITERAL(5, 57, 15), // "on_sure_clicked"
QT_MOC_LITERAL(6, 73, 12), // "receiveRgMsg"
QT_MOC_LITERAL(7, 86, 22), // "on_username_textEdited"
QT_MOC_LITERAL(8, 109, 4), // "arg1"
QT_MOC_LITERAL(9, 114, 24), // "on_passward_r_textEdited"
QT_MOC_LITERAL(10, 139, 24) // "on_checkBox_stateChanged"

    },
    "signinDialog\0okToRegister\0\0closeDialog\0"
    "on_cancel_clicked\0on_sure_clicked\0"
    "receiveRgMsg\0on_username_textEdited\0"
    "arg1\0on_passward_r_textEdited\0"
    "on_checkBox_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_signinDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   58,    2, 0x08 /* Private */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      10,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void signinDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        signinDialog *_t = static_cast<signinDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->okToRegister((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->closeDialog(); break;
        case 2: _t->on_cancel_clicked(); break;
        case 3: _t->on_sure_clicked(); break;
        case 4: _t->receiveRgMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_username_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_passward_r_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (signinDialog::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&signinDialog::okToRegister)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (signinDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&signinDialog::closeDialog)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject signinDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_signinDialog.data,
    qt_meta_data_signinDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *signinDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *signinDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_signinDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int signinDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void signinDialog::okToRegister(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void signinDialog::closeDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
