/****************************************************************************
** Meta object code from reading C++ file 'admintabledata.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/include/models/admintabledata.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admintabledata.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_AdminTableData_t {
    uint offsetsAndSizes[34];
    char stringdata0[15];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[15];
    char stringdata5[12];
    char stringdata6[16];
    char stringdata7[10];
    char stringdata8[15];
    char stringdata9[6];
    char stringdata10[6];
    char stringdata11[5];
    char stringdata12[8];
    char stringdata13[11];
    char stringdata14[10];
    char stringdata15[22];
    char stringdata16[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AdminTableData_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AdminTableData_t qt_meta_stringdata_AdminTableData = {
    {
        QT_MOC_LITERAL(0, 14),  // "AdminTableData"
        QT_MOC_LITERAL(15, 15),  // "preItemAppended"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 16),  // "postItemAppended"
        QT_MOC_LITERAL(49, 14),  // "preItemRemoved"
        QT_MOC_LITERAL(64, 11),  // "QModelIndex"
        QT_MOC_LITERAL(76, 15),  // "postItemRemoved"
        QT_MOC_LITERAL(92, 9),  // "setItemAt"
        QT_MOC_LITERAL(102, 14),  // "res::FoundUser"
        QT_MOC_LITERAL(117, 5),  // "admin"
        QT_MOC_LITERAL(123, 5),  // "index"
        QT_MOC_LITERAL(129, 4),  // "item"
        QT_MOC_LITERAL(134, 7),  // "addItem"
        QT_MOC_LITERAL(142, 10),  // "removeItem"
        QT_MOC_LITERAL(153, 9),  // "setAdmins"
        QT_MOC_LITERAL(163, 21),  // "QList<res::FoundUser>"
        QT_MOC_LITERAL(185, 6)   // "admins"
    },
    "AdminTableData",
    "preItemAppended",
    "",
    "postItemAppended",
    "preItemRemoved",
    "QModelIndex",
    "postItemRemoved",
    "setItemAt",
    "res::FoundUser",
    "admin",
    "index",
    "item",
    "addItem",
    "removeItem",
    "setAdmins",
    "QList<res::FoundUser>",
    "admins"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AdminTableData[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    1,   82,    2, 0x06,    3 /* Public */,
       6,    0,   85,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    2,   86,    2, 0x0a,    6 /* Public */,
       7,    1,   91,    2, 0x2a,    9 /* Public | MethodCloned */,
       7,    2,   94,    2, 0x0a,   11 /* Public */,
      12,    1,   99,    2, 0x0a,   14 /* Public */,
      13,    1,  102,    2, 0x0a,   16 /* Public */,
      13,    0,  105,    2, 0x2a,   18 /* Public | MethodCloned */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  106,    2, 0x02,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 5,    9,   10,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,   10,   11,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 5,   10,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdminTableData::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AdminTableData.offsetsAndSizes,
    qt_meta_data_AdminTableData,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminTableData_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdminTableData, std::true_type>,
        // method 'preItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'postItemAppended'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'preItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'postItemRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setItemAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'setItemAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser &, std::false_type>,
        // method 'setItemAt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser &, std::false_type>,
        // method 'addItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser &, std::false_type>,
        // method 'removeItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'removeItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAdmins'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<res::FoundUser> &, std::false_type>
    >,
    nullptr
} };

void AdminTableData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminTableData *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->setItemAt((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 5: _t->setItemAt((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 6: _t->setItemAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[2]))); break;
        case 7: _t->addItem((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 8: _t->removeItem((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->removeItem(); break;
        case 10: _t->setAdmins((*reinterpret_cast< std::add_pointer_t<QList<res::FoundUser>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminTableData::*)();
            if (_t _q_method = &AdminTableData::preItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminTableData::*)();
            if (_t _q_method = &AdminTableData::postItemAppended; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdminTableData::*)(const QModelIndex & );
            if (_t _q_method = &AdminTableData::preItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdminTableData::*)();
            if (_t _q_method = &AdminTableData::postItemRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *AdminTableData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminTableData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminTableData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AdminTableData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void AdminTableData::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminTableData::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AdminTableData::preItemRemoved(const QModelIndex & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AdminTableData::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
