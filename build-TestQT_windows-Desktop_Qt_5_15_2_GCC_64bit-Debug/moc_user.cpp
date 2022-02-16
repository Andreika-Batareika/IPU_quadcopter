/****************************************************************************
** Meta object code from reading C++ file 'user.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../TestQT_windows/user.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'user.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_user_t {
    QByteArrayData data[14];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_user_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_user_t qt_meta_stringdata_user = {
    {
QT_MOC_LITERAL(0, 0, 4), // "user"
QT_MOC_LITERAL(1, 5, 8), // "finished"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 14), // "runningChanged"
QT_MOC_LITERAL(4, 30, 7), // "running"
QT_MOC_LITERAL(5, 38, 14), // "messageChanged"
QT_MOC_LITERAL(6, 53, 7), // "message"
QT_MOC_LITERAL(7, 61, 11), // "sendMessage"
QT_MOC_LITERAL(8, 73, 12), // "MainProgramm"
QT_MOC_LITERAL(9, 86, 3), // "run"
QT_MOC_LITERAL(10, 90, 10), // "setRunning"
QT_MOC_LITERAL(11, 101, 10), // "setMessage"
QT_MOC_LITERAL(12, 112, 12), // "setMessage_2"
QT_MOC_LITERAL(13, 125, 9) // "message_2"

    },
    "user\0finished\0\0runningChanged\0running\0"
    "messageChanged\0message\0sendMessage\0"
    "MainProgramm\0run\0setRunning\0setMessage\0"
    "setMessage_2\0message_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_user[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,
       7,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   69,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void user::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<user *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->runningChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->messageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->MainProgramm(); break;
        case 5: _t->run(); break;
        case 6: _t->setRunning((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setMessage_2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (user::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (user::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::runningChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (user::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::messageChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (user::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&user::sendMessage)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject user::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_user.data,
    qt_meta_data_user,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *user::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *user::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_user.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int user::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void user::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void user::runningChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void user::messageChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void user::sendMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
