/****************************************************************************
** Meta object code from reading C++ file 'admintablemodel.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/include/models/admintablemodel.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admintablemodel.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_AdminTableModel_t {
    uint offsetsAndSizes[74];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[19];
    char stringdata4[6];
    char stringdata5[15];
    char stringdata6[1];
    char stringdata7[9];
    char stringdata8[22];
    char stringdata9[21];
    char stringdata10[21];
    char stringdata11[17];
    char stringdata12[12];
    char stringdata13[15];
    char stringdata14[12];
    char stringdata15[11];
    char stringdata16[6];
    char stringdata17[14];
    char stringdata18[5];
    char stringdata19[11];
    char stringdata20[8];
    char stringdata21[17];
    char stringdata22[10];
    char stringdata23[9];
    char stringdata24[17];
    char stringdata25[9];
    char stringdata26[8];
    char stringdata27[13];
    char stringdata28[16];
    char stringdata29[15];
    char stringdata30[10];
    char stringdata31[12];
    char stringdata32[6];
    char stringdata33[5];
    char stringdata34[14];
    char stringdata35[14];
    char stringdata36[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AdminTableModel_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_AdminTableModel_t qt_meta_stringdata_AdminTableModel = {
    {
        QT_MOC_LITERAL(0, 15),  // "AdminTableModel"
        QT_MOC_LITERAL(16, 11),  // "QML.Element"
        QT_MOC_LITERAL(28, 4),  // "auto"
        QT_MOC_LITERAL(33, 18),  // "QML.AddedInVersion"
        QT_MOC_LITERAL(52, 5),  // "65281"
        QT_MOC_LITERAL(58, 14),  // "headersChanged"
        QT_MOC_LITERAL(73, 0),  // ""
        QT_MOC_LITERAL(74, 8),  // "populate"
        QT_MOC_LITERAL(83, 21),  // "QList<res::FoundUser>"
        QT_MOC_LITERAL(105, 20),  // "tableRequestsChanged"
        QT_MOC_LITERAL(126, 20),  // "tableResponseChanged"
        QT_MOC_LITERAL(147, 16),  // "tableDataChanged"
        QT_MOC_LITERAL(164, 11),  // "itemChanged"
        QT_MOC_LITERAL(176, 14),  // "res::FoundUser"
        QT_MOC_LITERAL(191, 11),  // "updatedItem"
        QT_MOC_LITERAL(203, 10),  // "onPopulate"
        QT_MOC_LITERAL(214, 5),  // "users"
        QT_MOC_LITERAL(220, 13),  // "onUpdatedItem"
        QT_MOC_LITERAL(234, 4),  // "item"
        QT_MOC_LITERAL(239, 10),  // "setHeaders"
        QT_MOC_LITERAL(250, 7),  // "headers"
        QT_MOC_LITERAL(258, 16),  // "setTableResponse"
        QT_MOC_LITERAL(275, 9),  // "Response*"
        QT_MOC_LITERAL(285, 8),  // "response"
        QT_MOC_LITERAL(294, 16),  // "setTableRequests"
        QT_MOC_LITERAL(311, 8),  // "Request*"
        QT_MOC_LITERAL(320, 7),  // "request"
        QT_MOC_LITERAL(328, 12),  // "setTableData"
        QT_MOC_LITERAL(341, 15),  // "AdminTableData*"
        QT_MOC_LITERAL(357, 14),  // "adminTableData"
        QT_MOC_LITERAL(372, 9),  // "setItemAt"
        QT_MOC_LITERAL(382, 11),  // "QModelIndex"
        QT_MOC_LITERAL(394, 5),  // "index"
        QT_MOC_LITERAL(400, 4),  // "data"
        QT_MOC_LITERAL(405, 13),  // "tableRequests"
        QT_MOC_LITERAL(419, 13),  // "tableResponse"
        QT_MOC_LITERAL(433, 9)   // "tableData"
    },
    "AdminTableModel",
    "QML.Element",
    "auto",
    "QML.AddedInVersion",
    "65281",
    "headersChanged",
    "",
    "populate",
    "QList<res::FoundUser>",
    "tableRequestsChanged",
    "tableResponseChanged",
    "tableDataChanged",
    "itemChanged",
    "res::FoundUser",
    "updatedItem",
    "onPopulate",
    "users",
    "onUpdatedItem",
    "item",
    "setHeaders",
    "headers",
    "setTableResponse",
    "Response*",
    "response",
    "setTableRequests",
    "Request*",
    "request",
    "setTableData",
    "AdminTableData*",
    "adminTableData",
    "setItemAt",
    "QModelIndex",
    "index",
    "data",
    "tableRequests",
    "tableResponse",
    "tableData"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_AdminTableModel[] = {

 // content:
      10,       // revision
       0,       // classname
       2,   14, // classinfo
      14,   18, // methods
       4,  138, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  102,    6, 0x06,    5 /* Public */,
       7,    1,  103,    6, 0x06,    6 /* Public */,
       9,    0,  106,    6, 0x06,    8 /* Public */,
      10,    0,  107,    6, 0x06,    9 /* Public */,
      11,    0,  108,    6, 0x06,   10 /* Public */,
      12,    1,  109,    6, 0x06,   11 /* Public */,
      14,    1,  112,    6, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    1,  115,    6, 0x0a,   15 /* Public */,
      17,    1,  118,    6, 0x0a,   17 /* Public */,
      19,    1,  121,    6, 0x0a,   19 /* Public */,
      21,    1,  124,    6, 0x0a,   21 /* Public */,
      24,    1,  127,    6, 0x0a,   23 /* Public */,
      27,    1,  130,    6, 0x0a,   25 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      30,    2,  133,    6, 0x02,   27 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    6,
    QMetaType::Void, 0x80000000 | 13,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,   16,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void, QMetaType::QStringList,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28,   29,

 // methods: parameters
    QMetaType::Void, 0x80000000 | 31, QMetaType::QString,   32,   33,

 // properties: name, type, flags
      34, 0x80000000 | 25, 0x0001510b, uint(2), 0,
      35, 0x80000000 | 22, 0x0001510b, uint(3), 0,
      20, QMetaType::QStringList, 0x00015103, uint(0), 0,
      36, 0x80000000 | 28, 0x0001510b, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdminTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_AdminTableModel.offsetsAndSizes,
    qt_meta_data_AdminTableModel,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'tableRequests'
        Request*,
        // property 'tableResponse'
        Response*,
        // property 'headers'
        QStringList,
        // property 'tableData'
        AdminTableData*,
        // Q_OBJECT / Q_GADGET
        AdminTableModel,
        // method 'headersChanged'
        void,
        // method 'populate'
        void,
        const QList<res::FoundUser>,
        // method 'tableRequestsChanged'
        void,
        // method 'tableResponseChanged'
        void,
        // method 'tableDataChanged'
        void,
        // method 'itemChanged'
        void,
        const res::FoundUser,
        // method 'updatedItem'
        void,
        const res::FoundUser,
        // method 'onPopulate'
        void,
        const QList<res::FoundUser>,
        // method 'onUpdatedItem'
        void,
        const res::FoundUser,
        // method 'setHeaders'
        void,
        const QStringList &,
        // method 'setTableResponse'
        void,
        Response *,
        // method 'setTableRequests'
        void,
        Request *,
        // method 'setTableData'
        void,
        AdminTableData *,
        // method 'setItemAt'
        void,
        const QModelIndex &,
        const QString
    >,
    nullptr
} };

void AdminTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminTableModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->headersChanged(); break;
        case 1: _t->populate((*reinterpret_cast< std::add_pointer_t<QList<res::FoundUser>>>(_a[1]))); break;
        case 2: _t->tableRequestsChanged(); break;
        case 3: _t->tableResponseChanged(); break;
        case 4: _t->tableDataChanged(); break;
        case 5: _t->itemChanged((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 6: _t->updatedItem((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 7: _t->onPopulate((*reinterpret_cast< std::add_pointer_t<QList<res::FoundUser>>>(_a[1]))); break;
        case 8: _t->onUpdatedItem((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 9: _t->setHeaders((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 10: _t->setTableResponse((*reinterpret_cast< std::add_pointer_t<Response*>>(_a[1]))); break;
        case 11: _t->setTableRequests((*reinterpret_cast< std::add_pointer_t<Request*>>(_a[1]))); break;
        case 12: _t->setTableData((*reinterpret_cast< std::add_pointer_t<AdminTableData*>>(_a[1]))); break;
        case 13: _t->setItemAt((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Response* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Request* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< AdminTableData* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdminTableModel::*)();
            if (_t _q_method = &AdminTableModel::headersChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)(const QList<res::FoundUser> );
            if (_t _q_method = &AdminTableModel::populate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)();
            if (_t _q_method = &AdminTableModel::tableRequestsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)();
            if (_t _q_method = &AdminTableModel::tableResponseChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)();
            if (_t _q_method = &AdminTableModel::tableDataChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)(const res::FoundUser );
            if (_t _q_method = &AdminTableModel::itemChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AdminTableModel::*)(const res::FoundUser );
            if (_t _q_method = &AdminTableModel::updatedItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AdminTableData* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Request* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Response* >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AdminTableModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Request**>(_v) = _t->tableRequests(); break;
        case 1: *reinterpret_cast< Response**>(_v) = _t->tableResponse(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->headers(); break;
        case 3: *reinterpret_cast< AdminTableData**>(_v) = _t->tableData(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AdminTableModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTableRequests(*reinterpret_cast< Request**>(_v)); break;
        case 1: _t->setTableResponse(*reinterpret_cast< Response**>(_v)); break;
        case 2: _t->setHeaders(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setTableData(*reinterpret_cast< AdminTableData**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *AdminTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminTableModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int AdminTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AdminTableModel::headersChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AdminTableModel::populate(const QList<res::FoundUser> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdminTableModel::tableRequestsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AdminTableModel::tableResponseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void AdminTableModel::tableDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void AdminTableModel::itemChanged(const res::FoundUser _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AdminTableModel::updatedItem(const res::FoundUser _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
