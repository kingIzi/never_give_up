/****************************************************************************
** Meta object code from reading C++ file 'agent.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/include/agent.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agent.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_Agent_t {
    uint offsetsAndSizes[50];
    char stringdata0[6];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[16];
    char stringdata5[11];
    char stringdata6[18];
    char stringdata7[10];
    char stringdata8[22];
    char stringdata9[15];
    char stringdata10[19];
    char stringdata11[20];
    char stringdata12[16];
    char stringdata13[4];
    char stringdata14[14];
    char stringdata15[15];
    char stringdata16[13];
    char stringdata17[5];
    char stringdata18[17];
    char stringdata19[18];
    char stringdata20[7];
    char stringdata21[15];
    char stringdata22[5];
    char stringdata23[13];
    char stringdata24[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Agent_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Agent_t qt_meta_stringdata_Agent = {
    {
        QT_MOC_LITERAL(0, 5),  // "Agent"
        QT_MOC_LITERAL(6, 18),  // "requestFailedError"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 19),  // "isRequestingChanged"
        QT_MOC_LITERAL(46, 15),  // "requestErrorMsg"
        QT_MOC_LITERAL(62, 10),  // "res::Error"
        QT_MOC_LITERAL(73, 17),  // "isLoggedInChanged"
        QT_MOC_LITERAL(91, 9),  // "usersList"
        QT_MOC_LITERAL(101, 21),  // "QList<res::FoundUser>"
        QT_MOC_LITERAL(123, 14),  // "onRequestLogin"
        QT_MOC_LITERAL(138, 18),  // "onRequestUsersList"
        QT_MOC_LITERAL(157, 19),  // "onRequestUserUpdate"
        QT_MOC_LITERAL(177, 15),  // "setIsRequesting"
        QT_MOC_LITERAL(193, 3),  // "arg"
        QT_MOC_LITERAL(197, 13),  // "setIsLoggedIn"
        QT_MOC_LITERAL(211, 14),  // "storeAgentAuth"
        QT_MOC_LITERAL(226, 12),  // "requestLogin"
        QT_MOC_LITERAL(239, 4),  // "body"
        QT_MOC_LITERAL(244, 16),  // "requestUsersList"
        QT_MOC_LITERAL(261, 17),  // "requestUserUpdate"
        QT_MOC_LITERAL(279, 6),  // "userId"
        QT_MOC_LITERAL(286, 14),  // "res::FoundUser"
        QT_MOC_LITERAL(301, 4),  // "user"
        QT_MOC_LITERAL(306, 12),  // "isRequesting"
        QT_MOC_LITERAL(319, 10)   // "isLoggedIn"
    },
    "Agent",
    "requestFailedError",
    "",
    "isRequestingChanged",
    "requestErrorMsg",
    "res::Error",
    "isLoggedInChanged",
    "usersList",
    "QList<res::FoundUser>",
    "onRequestLogin",
    "onRequestUsersList",
    "onRequestUserUpdate",
    "setIsRequesting",
    "arg",
    "setIsLoggedIn",
    "storeAgentAuth",
    "requestLogin",
    "body",
    "requestUsersList",
    "requestUserUpdate",
    "userId",
    "res::FoundUser",
    "user",
    "isRequesting",
    "isLoggedIn"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Agent[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       2,  136, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    3 /* Public */,
       3,    0,  101,    2, 0x06,    5 /* Public */,
       4,    1,  102,    2, 0x06,    6 /* Public */,
       6,    0,  105,    2, 0x06,    8 /* Public */,
       7,    1,  106,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  109,    2, 0x08,   11 /* Private */,
      10,    1,  112,    2, 0x08,   13 /* Private */,
      11,    1,  115,    2, 0x08,   15 /* Private */,
      12,    1,  118,    2, 0x0a,   17 /* Public */,
      14,    1,  121,    2, 0x0a,   19 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  124,    2, 0x102,   21 /* Public | MethodIsConst  */,
      16,    1,  125,    2, 0x02,   22 /* Public */,
      18,    1,  128,    2, 0x02,   24 /* Public */,
      19,    2,  131,    2, 0x02,   26 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,   17,
    QMetaType::Void, QMetaType::QVariantMap,   17,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 21,   20,   22,

 // properties: name, type, flags
      23, QMetaType::Bool, 0x00015103, uint(1), 0,
      24, QMetaType::Bool, 0x00015103, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Agent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Agent.offsetsAndSizes,
    qt_meta_data_Agent,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Agent_t,
        // property 'isRequesting'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'isLoggedIn'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Agent, std::true_type>,
        // method 'requestFailedError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'isRequestingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestErrorMsg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::Error, std::false_type>,
        // method 'isLoggedInChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'usersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<res::FoundUser>, std::false_type>,
        // method 'onRequestLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRequestUsersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRequestUserUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'setIsRequesting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'setIsLoggedIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'storeAgentAuth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestLogin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestUsersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestUserUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser, std::false_type>
    >,
    nullptr
} };

void Agent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Agent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestFailedError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->isRequestingChanged(); break;
        case 2: _t->requestErrorMsg((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        case 3: _t->isLoggedInChanged(); break;
        case 4: _t->usersList((*reinterpret_cast< std::add_pointer_t<QList<res::FoundUser>>>(_a[1]))); break;
        case 5: _t->onRequestLogin((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 6: _t->onRequestUsersList((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 7: _t->onRequestUserUpdate((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 8: _t->setIsRequesting((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->setIsLoggedIn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->storeAgentAuth(); break;
        case 11: _t->requestLogin((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 12: _t->requestUsersList((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 13: _t->requestUserUpdate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Agent::*)(const QString );
            if (_t _q_method = &Agent::requestFailedError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Agent::*)();
            if (_t _q_method = &Agent::isRequestingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Agent::*)(const res::Error );
            if (_t _q_method = &Agent::requestErrorMsg; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Agent::*)();
            if (_t _q_method = &Agent::isLoggedInChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Agent::*)(const QList<res::FoundUser> );
            if (_t _q_method = &Agent::usersList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Agent *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isRequesting(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isLoggedIn(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Agent *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIsRequesting(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setIsLoggedIn(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Agent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Agent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Agent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Agent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Agent::requestFailedError(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Agent::isRequestingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Agent::requestErrorMsg(const res::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Agent::isLoggedInChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Agent::usersList(const QList<res::FoundUser> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
