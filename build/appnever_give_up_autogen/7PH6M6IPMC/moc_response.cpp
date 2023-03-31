/****************************************************************************
** Meta object code from reading C++ file 'response.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/include/response.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'response.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_res__Error_t {
    uint offsetsAndSizes[6];
    char stringdata0[11];
    char stringdata1[8];
    char stringdata2[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Error_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Error_t qt_meta_stringdata_res__Error = {
    {
        QT_MOC_LITERAL(0, 10),  // "res::Error"
        QT_MOC_LITERAL(11, 7),  // "message"
        QT_MOC_LITERAL(19, 4)   // "code"
    },
    "res::Error",
    "message",
    "code"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Error[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015003, uint(-1), 0,
       2, QMetaType::Int, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Error::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Error.offsetsAndSizes,
    qt_meta_data_res__Error,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Error_t,
        // property 'message'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'code'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Error, std::true_type>
    >,
    nullptr
} };

void res::Error::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<Error *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->message; break;
        case 1: *reinterpret_cast< int*>(_v) = _t->code; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<Error *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->message != *reinterpret_cast< QString*>(_v)) {
                _t->message = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->code != *reinterpret_cast< int*>(_v)) {
                _t->code = *reinterpret_cast< int*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}
namespace {
struct qt_meta_stringdata_res__Register_t {
    uint offsetsAndSizes[12];
    char stringdata0[14];
    char stringdata1[8];
    char stringdata2[8];
    char stringdata3[6];
    char stringdata4[10];
    char stringdata5[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Register_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Register_t qt_meta_stringdata_res__Register = {
    {
        QT_MOC_LITERAL(0, 13),  // "res::Register"
        QT_MOC_LITERAL(14, 7),  // "idToken"
        QT_MOC_LITERAL(22, 7),  // "localId"
        QT_MOC_LITERAL(30, 5),  // "email"
        QT_MOC_LITERAL(36, 9),  // "expiresIn"
        QT_MOC_LITERAL(46, 12)   // "refreshToken"
    },
    "res::Register",
    "idToken",
    "localId",
    "email",
    "expiresIn",
    "refreshToken"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Register[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015003, uint(-1), 0,
       2, QMetaType::QString, 0x00015003, uint(-1), 0,
       3, QMetaType::QString, 0x00015003, uint(-1), 0,
       4, QMetaType::Int, 0x00015003, uint(-1), 0,
       5, QMetaType::QString, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Register::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Register.offsetsAndSizes,
    qt_meta_data_res__Register,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Register_t,
        // property 'idToken'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'localId'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'email'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'expiresIn'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'refreshToken'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Register, std::true_type>
    >,
    nullptr
} };

void res::Register::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<Register *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->idToken; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->localId; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->email; break;
        case 3: *reinterpret_cast< int*>(_v) = _t->expiresIn; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->refreshToken; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<Register *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->idToken != *reinterpret_cast< QString*>(_v)) {
                _t->idToken = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->localId != *reinterpret_cast< QString*>(_v)) {
                _t->localId = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 2:
            if (_t->email != *reinterpret_cast< QString*>(_v)) {
                _t->email = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (_t->expiresIn != *reinterpret_cast< int*>(_v)) {
                _t->expiresIn = *reinterpret_cast< int*>(_v);
            }
            break;
        case 4:
            if (_t->refreshToken != *reinterpret_cast< QString*>(_v)) {
                _t->refreshToken = *reinterpret_cast< QString*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}
namespace {
struct qt_meta_stringdata_res__Login_t {
    uint offsetsAndSizes[2];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Login_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Login_t qt_meta_stringdata_res__Login = {
    {
        QT_MOC_LITERAL(0, 10)   // "res::Login"
    },
    "res::Login"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Login[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Login::staticMetaObject = { {
    QtPrivate::MetaObjectForType<Register>::value,
    qt_meta_stringdata_res__Login.offsetsAndSizes,
    qt_meta_data_res__Login,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Login_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Login, std::true_type>
    >,
    nullptr
} };

namespace {
struct qt_meta_stringdata_res__FoundUser_t {
    uint offsetsAndSizes[26];
    char stringdata0[15];
    char stringdata1[7];
    char stringdata2[6];
    char stringdata3[8];
    char stringdata4[12];
    char stringdata5[9];
    char stringdata6[14];
    char stringdata7[9];
    char stringdata8[5];
    char stringdata9[12];
    char stringdata10[12];
    char stringdata11[7];
    char stringdata12[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__FoundUser_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__FoundUser_t qt_meta_stringdata_res__FoundUser = {
    {
        QT_MOC_LITERAL(0, 14),  // "res::FoundUser"
        QT_MOC_LITERAL(15, 6),  // "userId"
        QT_MOC_LITERAL(22, 5),  // "email"
        QT_MOC_LITERAL(28, 7),  // "localId"
        QT_MOC_LITERAL(36, 11),  // "phoneNumber"
        QT_MOC_LITERAL(48, 8),  // "fullName"
        QT_MOC_LITERAL(57, 13),  // "photoFileName"
        QT_MOC_LITERAL(71, 8),  // "photoUrl"
        QT_MOC_LITERAL(80, 4),  // "role"
        QT_MOC_LITERAL(85, 11),  // "dateCreated"
        QT_MOC_LITERAL(97, 11),  // "dateUpdated"
        QT_MOC_LITERAL(109, 6),  // "status"
        QT_MOC_LITERAL(116, 9)   // "favorites"
    },
    "res::FoundUser",
    "userId",
    "email",
    "localId",
    "phoneNumber",
    "fullName",
    "photoFileName",
    "photoUrl",
    "role",
    "dateCreated",
    "dateUpdated",
    "status",
    "favorites"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__FoundUser[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      12,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015003, uint(-1), 0,
       2, QMetaType::QString, 0x00015003, uint(-1), 0,
       3, QMetaType::QString, 0x00015003, uint(-1), 0,
       4, QMetaType::QString, 0x00015003, uint(-1), 0,
       5, QMetaType::QString, 0x00015003, uint(-1), 0,
       6, QMetaType::QString, 0x00015003, uint(-1), 0,
       7, QMetaType::QString, 0x00015003, uint(-1), 0,
       8, QMetaType::QString, 0x00015003, uint(-1), 0,
       9, QMetaType::QDateTime, 0x00015003, uint(-1), 0,
      10, QMetaType::QDateTime, 0x00015003, uint(-1), 0,
      11, QMetaType::QString, 0x00015003, uint(-1), 0,
      12, QMetaType::QStringList, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject res::FoundUser::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__FoundUser.offsetsAndSizes,
    qt_meta_data_res__FoundUser,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__FoundUser_t,
        // property 'userId'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'email'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'localId'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'phoneNumber'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'fullName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'photoFileName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'photoUrl'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'role'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'dateCreated'
        QtPrivate::TypeAndForceComplete<QDateTime, std::true_type>,
        // property 'dateUpdated'
        QtPrivate::TypeAndForceComplete<QDateTime, std::true_type>,
        // property 'status'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'favorites'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FoundUser, std::true_type>
    >,
    nullptr
} };

void res::FoundUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<FoundUser *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->userId; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->email; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->localId; break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->phoneNumber; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->fullName; break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->photoFileName; break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->photoUrl; break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->role; break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = _t->dateCreated; break;
        case 9: *reinterpret_cast< QDateTime*>(_v) = _t->dateUpdated; break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->status; break;
        case 11: *reinterpret_cast< QStringList*>(_v) = _t->favorites; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<FoundUser *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->userId != *reinterpret_cast< QString*>(_v)) {
                _t->userId = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->email != *reinterpret_cast< QString*>(_v)) {
                _t->email = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 2:
            if (_t->localId != *reinterpret_cast< QString*>(_v)) {
                _t->localId = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (_t->phoneNumber != *reinterpret_cast< QString*>(_v)) {
                _t->phoneNumber = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 4:
            if (_t->fullName != *reinterpret_cast< QString*>(_v)) {
                _t->fullName = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 5:
            if (_t->photoFileName != *reinterpret_cast< QString*>(_v)) {
                _t->photoFileName = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 6:
            if (_t->photoUrl != *reinterpret_cast< QString*>(_v)) {
                _t->photoUrl = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 7:
            if (_t->role != *reinterpret_cast< QString*>(_v)) {
                _t->role = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 8:
            if (_t->dateCreated != *reinterpret_cast< QDateTime*>(_v)) {
                _t->dateCreated = *reinterpret_cast< QDateTime*>(_v);
            }
            break;
        case 9:
            if (_t->dateUpdated != *reinterpret_cast< QDateTime*>(_v)) {
                _t->dateUpdated = *reinterpret_cast< QDateTime*>(_v);
            }
            break;
        case 10:
            if (_t->status != *reinterpret_cast< QString*>(_v)) {
                _t->status = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 11:
            if (_t->favorites != *reinterpret_cast< QStringList*>(_v)) {
                _t->favorites = *reinterpret_cast< QStringList*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}
namespace {
struct qt_meta_stringdata_res__Author_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[9];
    char stringdata2[10];
    char stringdata3[9];
    char stringdata4[12];
    char stringdata5[8];
    char stringdata6[12];
    char stringdata7[7];
    char stringdata8[9];
    char stringdata9[14];
    char stringdata10[12];
    char stringdata11[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Author_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Author_t qt_meta_stringdata_res__Author = {
    {
        QT_MOC_LITERAL(0, 11),  // "res::Author"
        QT_MOC_LITERAL(12, 8),  // "authorId"
        QT_MOC_LITERAL(21, 9),  // "firstName"
        QT_MOC_LITERAL(31, 8),  // "lastName"
        QT_MOC_LITERAL(40, 11),  // "dateOfBirth"
        QT_MOC_LITERAL(52, 7),  // "address"
        QT_MOC_LITERAL(60, 11),  // "phoneNumber"
        QT_MOC_LITERAL(72, 6),  // "status"
        QT_MOC_LITERAL(79, 8),  // "photoUrl"
        QT_MOC_LITERAL(88, 13),  // "photoFileName"
        QT_MOC_LITERAL(102, 11),  // "dateCreated"
        QT_MOC_LITERAL(114, 11)   // "dateUpdated"
    },
    "res::Author",
    "authorId",
    "firstName",
    "lastName",
    "dateOfBirth",
    "address",
    "phoneNumber",
    "status",
    "photoUrl",
    "photoFileName",
    "dateCreated",
    "dateUpdated"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Author[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      11,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015003, uint(-1), 0,
       2, QMetaType::QString, 0x00015003, uint(-1), 0,
       3, QMetaType::QString, 0x00015003, uint(-1), 0,
       4, QMetaType::QDate, 0x00015003, uint(-1), 0,
       5, QMetaType::QString, 0x00015003, uint(-1), 0,
       6, QMetaType::QString, 0x00015003, uint(-1), 0,
       7, QMetaType::QString, 0x00015003, uint(-1), 0,
       8, QMetaType::QString, 0x00015003, uint(-1), 0,
       9, QMetaType::QString, 0x00015003, uint(-1), 0,
      10, QMetaType::QDate, 0x00015003, uint(-1), 0,
      11, QMetaType::QDate, 0x00015003, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Author::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Author.offsetsAndSizes,
    qt_meta_data_res__Author,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Author_t,
        // property 'authorId'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'firstName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'lastName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'dateOfBirth'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // property 'address'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'phoneNumber'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'status'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'photoUrl'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'photoFileName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'dateCreated'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // property 'dateUpdated'
        QtPrivate::TypeAndForceComplete<QDate, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Author, std::true_type>
    >,
    nullptr
} };

void res::Author::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = reinterpret_cast<Author *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->authorId; break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->firstName; break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->lastName; break;
        case 3: *reinterpret_cast< QDate*>(_v) = _t->dateOfBirth; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->address; break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->phoneNumber; break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->status; break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->photoUrl; break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->photoFileName; break;
        case 9: *reinterpret_cast< QDate*>(_v) = _t->dateCreated; break;
        case 10: *reinterpret_cast< QDate*>(_v) = _t->dateUpdated; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = reinterpret_cast<Author *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (_t->authorId != *reinterpret_cast< QString*>(_v)) {
                _t->authorId = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 1:
            if (_t->firstName != *reinterpret_cast< QString*>(_v)) {
                _t->firstName = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 2:
            if (_t->lastName != *reinterpret_cast< QString*>(_v)) {
                _t->lastName = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (_t->dateOfBirth != *reinterpret_cast< QDate*>(_v)) {
                _t->dateOfBirth = *reinterpret_cast< QDate*>(_v);
            }
            break;
        case 4:
            if (_t->address != *reinterpret_cast< QString*>(_v)) {
                _t->address = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 5:
            if (_t->phoneNumber != *reinterpret_cast< QString*>(_v)) {
                _t->phoneNumber = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 6:
            if (_t->status != *reinterpret_cast< QString*>(_v)) {
                _t->status = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 7:
            if (_t->photoUrl != *reinterpret_cast< QString*>(_v)) {
                _t->photoUrl = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 8:
            if (_t->photoFileName != *reinterpret_cast< QString*>(_v)) {
                _t->photoFileName = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 9:
            if (_t->dateCreated != *reinterpret_cast< QDate*>(_v)) {
                _t->dateCreated = *reinterpret_cast< QDate*>(_v);
            }
            break;
        case 10:
            if (_t->dateUpdated != *reinterpret_cast< QDate*>(_v)) {
                _t->dateUpdated = *reinterpret_cast< QDate*>(_v);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}
namespace {
struct qt_meta_stringdata_res__Category_t {
    uint offsetsAndSizes[2];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Category_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Category_t qt_meta_stringdata_res__Category = {
    {
        QT_MOC_LITERAL(0, 13)   // "res::Category"
    },
    "res::Category"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Category[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Category::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Category.offsetsAndSizes,
    qt_meta_data_res__Category,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Category_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Category, std::true_type>
    >,
    nullptr
} };

namespace {
struct qt_meta_stringdata_res__Comment_t {
    uint offsetsAndSizes[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Comment_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Comment_t qt_meta_stringdata_res__Comment = {
    {
        QT_MOC_LITERAL(0, 12)   // "res::Comment"
    },
    "res::Comment"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Comment[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Comment::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Comment.offsetsAndSizes,
    qt_meta_data_res__Comment,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Comment_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Comment, std::true_type>
    >,
    nullptr
} };

namespace {
struct qt_meta_stringdata_res__Comic_t {
    uint offsetsAndSizes[2];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_res__Comic_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_res__Comic_t qt_meta_stringdata_res__Comic = {
    {
        QT_MOC_LITERAL(0, 10)   // "res::Comic"
    },
    "res::Comic"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_res__Comic[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject res::Comic::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_res__Comic.offsetsAndSizes,
    qt_meta_data_res__Comic,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_res__Comic_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Comic, std::true_type>
    >,
    nullptr
} };

namespace {
struct qt_meta_stringdata_Response_t {
    uint offsetsAndSizes[8];
    char stringdata0[9];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Response_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Response_t qt_meta_stringdata_Response = {
    {
        QT_MOC_LITERAL(0, 8),  // "Response"
        QT_MOC_LITERAL(9, 25),  // "requestUnsuccessfullError"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 10)   // "res::Error"
    },
    "Response",
    "requestUnsuccessfullError",
    "",
    "res::Error"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Response[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject Response::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Response.offsetsAndSizes,
    qt_meta_data_Response,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Response_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Response, std::true_type>,
        // method 'requestUnsuccessfullError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::Error, std::false_type>
    >,
    nullptr
} };

void Response::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Response *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->requestUnsuccessfullError((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Response::*)(const res::Error );
            if (_t _q_method = &Response::requestUnsuccessfullError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Response::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Response::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Response.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Response::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Response::requestUnsuccessfullError(const res::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
