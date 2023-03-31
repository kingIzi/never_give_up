/****************************************************************************
** Meta object code from reading C++ file 'admin.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/include/admin.hpp"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'admin.hpp' doesn't include <QObject>."
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
struct qt_meta_stringdata_Admin_t {
    uint offsetsAndSizes[272];
    char stringdata0[6];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[17];
    char stringdata5[22];
    char stringdata6[18];
    char stringdata7[13];
    char stringdata8[11];
    char stringdata9[23];
    char stringdata10[23];
    char stringdata11[18];
    char stringdata12[11];
    char stringdata13[26];
    char stringdata14[21];
    char stringdata15[14];
    char stringdata16[13];
    char stringdata17[15];
    char stringdata18[16];
    char stringdata19[23];
    char stringdata20[14];
    char stringdata21[22];
    char stringdata22[17];
    char stringdata23[12];
    char stringdata24[17];
    char stringdata25[17];
    char stringdata26[15];
    char stringdata27[15];
    char stringdata28[19];
    char stringdata29[19];
    char stringdata30[14];
    char stringdata31[19];
    char stringdata32[17];
    char stringdata33[19];
    char stringdata34[17];
    char stringdata35[21];
    char stringdata36[16];
    char stringdata37[11];
    char stringdata38[16];
    char stringdata39[14];
    char stringdata40[18];
    char stringdata41[16];
    char stringdata42[14];
    char stringdata43[14];
    char stringdata44[14];
    char stringdata45[16];
    char stringdata46[17];
    char stringdata47[16];
    char stringdata48[18];
    char stringdata49[12];
    char stringdata50[9];
    char stringdata51[15];
    char stringdata52[18];
    char stringdata53[13];
    char stringdata54[21];
    char stringdata55[12];
    char stringdata56[15];
    char stringdata57[15];
    char stringdata58[15];
    char stringdata59[13];
    char stringdata60[13];
    char stringdata61[17];
    char stringdata62[17];
    char stringdata63[15];
    char stringdata64[17];
    char stringdata65[15];
    char stringdata66[14];
    char stringdata67[14];
    char stringdata68[12];
    char stringdata69[14];
    char stringdata70[12];
    char stringdata71[12];
    char stringdata72[12];
    char stringdata73[14];
    char stringdata74[15];
    char stringdata75[14];
    char stringdata76[16];
    char stringdata77[18];
    char stringdata78[16];
    char stringdata79[15];
    char stringdata80[15];
    char stringdata81[5];
    char stringdata82[16];
    char stringdata83[6];
    char stringdata84[13];
    char stringdata85[10];
    char stringdata86[14];
    char stringdata87[17];
    char stringdata88[5];
    char stringdata89[20];
    char stringdata90[13];
    char stringdata91[18];
    char stringdata92[8];
    char stringdata93[26];
    char stringdata94[8];
    char stringdata95[16];
    char stringdata96[8];
    char stringdata97[20];
    char stringdata98[7];
    char stringdata99[20];
    char stringdata100[9];
    char stringdata101[20];
    char stringdata102[18];
    char stringdata103[18];
    char stringdata104[6];
    char stringdata105[8];
    char stringdata106[22];
    char stringdata107[9];
    char stringdata108[22];
    char stringdata109[11];
    char stringdata110[20];
    char stringdata111[22];
    char stringdata112[20];
    char stringdata113[19];
    char stringdata114[6];
    char stringdata115[19];
    char stringdata116[17];
    char stringdata117[7];
    char stringdata118[19];
    char stringdata119[17];
    char stringdata120[17];
    char stringdata121[17];
    char stringdata122[19];
    char stringdata123[8];
    char stringdata124[20];
    char stringdata125[19];
    char stringdata126[21];
    char stringdata127[14];
    char stringdata128[9];
    char stringdata129[15];
    char stringdata130[10];
    char stringdata131[16];
    char stringdata132[17];
    char stringdata133[12];
    char stringdata134[13];
    char stringdata135[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Admin_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Admin_t qt_meta_stringdata_Admin = {
    {
        QT_MOC_LITERAL(0, 5),  // "Admin"
        QT_MOC_LITERAL(6, 18),  // "currentUserChanged"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 19),  // "errorMessageChanged"
        QT_MOC_LITERAL(46, 16),  // "isLoadingChanged"
        QT_MOC_LITERAL(63, 21),  // "adminTableDataChanged"
        QT_MOC_LITERAL(85, 17),  // "isLoggedInChanged"
        QT_MOC_LITERAL(103, 12),  // "requestError"
        QT_MOC_LITERAL(116, 10),  // "res::Error"
        QT_MOC_LITERAL(127, 22),  // "registeredSuccessfully"
        QT_MOC_LITERAL(150, 22),  // "readLoginResponseError"
        QT_MOC_LITERAL(173, 17),  // "readLoginResponse"
        QT_MOC_LITERAL(191, 10),  // "res::Login"
        QT_MOC_LITERAL(202, 25),  // "readRegisterResponseError"
        QT_MOC_LITERAL(228, 20),  // "readRegisterResponse"
        QT_MOC_LITERAL(249, 13),  // "res::Register"
        QT_MOC_LITERAL(263, 12),  // "readFindUser"
        QT_MOC_LITERAL(276, 14),  // "res::FoundUser"
        QT_MOC_LITERAL(291, 15),  // "readUpdatedUser"
        QT_MOC_LITERAL(307, 22),  // "readAddComicToFavorite"
        QT_MOC_LITERAL(330, 13),  // "readUsersList"
        QT_MOC_LITERAL(344, 21),  // "QList<res::FoundUser>"
        QT_MOC_LITERAL(366, 16),  // "readCreateAuthor"
        QT_MOC_LITERAL(383, 11),  // "res::Author"
        QT_MOC_LITERAL(395, 16),  // "readUpdateAuthor"
        QT_MOC_LITERAL(412, 16),  // "readDeleteAuthor"
        QT_MOC_LITERAL(429, 14),  // "readFindAuthor"
        QT_MOC_LITERAL(444, 14),  // "readAuthorList"
        QT_MOC_LITERAL(459, 18),  // "QList<res::Author>"
        QT_MOC_LITERAL(478, 18),  // "readCreateCategory"
        QT_MOC_LITERAL(497, 13),  // "res::Category"
        QT_MOC_LITERAL(511, 18),  // "readUpdateCategory"
        QT_MOC_LITERAL(530, 16),  // "readFindCategory"
        QT_MOC_LITERAL(547, 18),  // "readRemoveCategory"
        QT_MOC_LITERAL(566, 16),  // "readCategoryList"
        QT_MOC_LITERAL(583, 20),  // "QList<res::Category>"
        QT_MOC_LITERAL(604, 15),  // "readCreateComic"
        QT_MOC_LITERAL(620, 10),  // "res::Comic"
        QT_MOC_LITERAL(631, 15),  // "readUpdateComic"
        QT_MOC_LITERAL(647, 13),  // "readComicList"
        QT_MOC_LITERAL(661, 17),  // "QList<res::Comic>"
        QT_MOC_LITERAL(679, 15),  // "readRemoveComic"
        QT_MOC_LITERAL(695, 13),  // "readFindComic"
        QT_MOC_LITERAL(709, 13),  // "readLikeComic"
        QT_MOC_LITERAL(723, 13),  // "readViewComic"
        QT_MOC_LITERAL(737, 15),  // "readFindComment"
        QT_MOC_LITERAL(753, 16),  // "readReplyComment"
        QT_MOC_LITERAL(770, 15),  // "readLikeComment"
        QT_MOC_LITERAL(786, 17),  // "readRemoveComment"
        QT_MOC_LITERAL(804, 11),  // "onLoginUser"
        QT_MOC_LITERAL(816, 8),  // "document"
        QT_MOC_LITERAL(825, 14),  // "onRegisterUser"
        QT_MOC_LITERAL(840, 17),  // "onFindActiveAgent"
        QT_MOC_LITERAL(858, 12),  // "onUpdateUser"
        QT_MOC_LITERAL(871, 20),  // "onAddComicToFavorite"
        QT_MOC_LITERAL(892, 11),  // "onUsersList"
        QT_MOC_LITERAL(904, 14),  // "onCreateAuthor"
        QT_MOC_LITERAL(919, 14),  // "onUpdateAuthor"
        QT_MOC_LITERAL(934, 14),  // "onDeleteAuthor"
        QT_MOC_LITERAL(949, 12),  // "onFindAuthor"
        QT_MOC_LITERAL(962, 12),  // "onAuthorList"
        QT_MOC_LITERAL(975, 16),  // "onCreateCategory"
        QT_MOC_LITERAL(992, 16),  // "onUpdateCategory"
        QT_MOC_LITERAL(1009, 14),  // "onFindCategory"
        QT_MOC_LITERAL(1024, 16),  // "onRemoveCategory"
        QT_MOC_LITERAL(1041, 14),  // "onCategoryList"
        QT_MOC_LITERAL(1056, 13),  // "onCreateComic"
        QT_MOC_LITERAL(1070, 13),  // "onUpdateComic"
        QT_MOC_LITERAL(1084, 11),  // "onComicList"
        QT_MOC_LITERAL(1096, 13),  // "onRemoveComic"
        QT_MOC_LITERAL(1110, 11),  // "onFindComic"
        QT_MOC_LITERAL(1122, 11),  // "onLikeComic"
        QT_MOC_LITERAL(1134, 11),  // "onViewComic"
        QT_MOC_LITERAL(1146, 13),  // "onFindComment"
        QT_MOC_LITERAL(1160, 14),  // "onReplyComment"
        QT_MOC_LITERAL(1175, 13),  // "onLikeComment"
        QT_MOC_LITERAL(1189, 15),  // "onRemoveComment"
        QT_MOC_LITERAL(1205, 17),  // "setAdminTableData"
        QT_MOC_LITERAL(1223, 15),  // "AdminTableData*"
        QT_MOC_LITERAL(1239, 14),  // "adminTableData"
        QT_MOC_LITERAL(1254, 14),  // "setCurrentUser"
        QT_MOC_LITERAL(1269, 4),  // "user"
        QT_MOC_LITERAL(1274, 15),  // "setErrorMessage"
        QT_MOC_LITERAL(1290, 5),  // "error"
        QT_MOC_LITERAL(1296, 12),  // "setIsLoading"
        QT_MOC_LITERAL(1309, 9),  // "isLoading"
        QT_MOC_LITERAL(1319, 13),  // "setIsLoggedIn"
        QT_MOC_LITERAL(1333, 16),  // "requestLoginUser"
        QT_MOC_LITERAL(1350, 4),  // "body"
        QT_MOC_LITERAL(1355, 19),  // "requestRegisterUser"
        QT_MOC_LITERAL(1375, 12),  // "registerUser"
        QT_MOC_LITERAL(1388, 17),  // "requestUpdateUser"
        QT_MOC_LITERAL(1406, 7),  // "profile"
        QT_MOC_LITERAL(1414, 25),  // "requestAddComicToFavorite"
        QT_MOC_LITERAL(1440, 7),  // "comicId"
        QT_MOC_LITERAL(1448, 15),  // "requestFindUser"
        QT_MOC_LITERAL(1464, 7),  // "localId"
        QT_MOC_LITERAL(1472, 19),  // "requestCreateAuthor"
        QT_MOC_LITERAL(1492, 6),  // "author"
        QT_MOC_LITERAL(1499, 19),  // "requestUpdateAuthor"
        QT_MOC_LITERAL(1519, 8),  // "authorId"
        QT_MOC_LITERAL(1528, 19),  // "requestDeleteAuthor"
        QT_MOC_LITERAL(1548, 17),  // "requestFindAuthor"
        QT_MOC_LITERAL(1566, 17),  // "requestAuthorList"
        QT_MOC_LITERAL(1584, 5),  // "limit"
        QT_MOC_LITERAL(1590, 7),  // "options"
        QT_MOC_LITERAL(1598, 21),  // "requestCreateCategory"
        QT_MOC_LITERAL(1620, 8),  // "category"
        QT_MOC_LITERAL(1629, 21),  // "requestUpdateCategory"
        QT_MOC_LITERAL(1651, 10),  // "categoryId"
        QT_MOC_LITERAL(1662, 19),  // "requestFindCategory"
        QT_MOC_LITERAL(1682, 21),  // "requestRemoveCategory"
        QT_MOC_LITERAL(1704, 19),  // "requestCategoryList"
        QT_MOC_LITERAL(1724, 18),  // "requestCreateComic"
        QT_MOC_LITERAL(1743, 5),  // "comic"
        QT_MOC_LITERAL(1749, 18),  // "requestUpdateComic"
        QT_MOC_LITERAL(1768, 16),  // "requestComicList"
        QT_MOC_LITERAL(1785, 6),  // "option"
        QT_MOC_LITERAL(1792, 18),  // "requestRemoveComic"
        QT_MOC_LITERAL(1811, 16),  // "requestFindComic"
        QT_MOC_LITERAL(1828, 16),  // "requestLikeComic"
        QT_MOC_LITERAL(1845, 16),  // "requestViewComic"
        QT_MOC_LITERAL(1862, 18),  // "requestFindComment"
        QT_MOC_LITERAL(1881, 7),  // "comment"
        QT_MOC_LITERAL(1889, 19),  // "requestReplyComment"
        QT_MOC_LITERAL(1909, 18),  // "requestLikeComment"
        QT_MOC_LITERAL(1928, 20),  // "requestRemoveComment"
        QT_MOC_LITERAL(1949, 13),  // "getRequestPtr"
        QT_MOC_LITERAL(1963, 8),  // "Request*"
        QT_MOC_LITERAL(1972, 14),  // "getResponsePtr"
        QT_MOC_LITERAL(1987, 9),  // "Response*"
        QT_MOC_LITERAL(1997, 15),  // "findActiveAgent"
        QT_MOC_LITERAL(2013, 16),  // "requestUsersList"
        QT_MOC_LITERAL(2030, 11),  // "currentUser"
        QT_MOC_LITERAL(2042, 12),  // "errorMessage"
        QT_MOC_LITERAL(2055, 10)   // "isLoggedIn"
    },
    "Admin",
    "currentUserChanged",
    "",
    "errorMessageChanged",
    "isLoadingChanged",
    "adminTableDataChanged",
    "isLoggedInChanged",
    "requestError",
    "res::Error",
    "registeredSuccessfully",
    "readLoginResponseError",
    "readLoginResponse",
    "res::Login",
    "readRegisterResponseError",
    "readRegisterResponse",
    "res::Register",
    "readFindUser",
    "res::FoundUser",
    "readUpdatedUser",
    "readAddComicToFavorite",
    "readUsersList",
    "QList<res::FoundUser>",
    "readCreateAuthor",
    "res::Author",
    "readUpdateAuthor",
    "readDeleteAuthor",
    "readFindAuthor",
    "readAuthorList",
    "QList<res::Author>",
    "readCreateCategory",
    "res::Category",
    "readUpdateCategory",
    "readFindCategory",
    "readRemoveCategory",
    "readCategoryList",
    "QList<res::Category>",
    "readCreateComic",
    "res::Comic",
    "readUpdateComic",
    "readComicList",
    "QList<res::Comic>",
    "readRemoveComic",
    "readFindComic",
    "readLikeComic",
    "readViewComic",
    "readFindComment",
    "readReplyComment",
    "readLikeComment",
    "readRemoveComment",
    "onLoginUser",
    "document",
    "onRegisterUser",
    "onFindActiveAgent",
    "onUpdateUser",
    "onAddComicToFavorite",
    "onUsersList",
    "onCreateAuthor",
    "onUpdateAuthor",
    "onDeleteAuthor",
    "onFindAuthor",
    "onAuthorList",
    "onCreateCategory",
    "onUpdateCategory",
    "onFindCategory",
    "onRemoveCategory",
    "onCategoryList",
    "onCreateComic",
    "onUpdateComic",
    "onComicList",
    "onRemoveComic",
    "onFindComic",
    "onLikeComic",
    "onViewComic",
    "onFindComment",
    "onReplyComment",
    "onLikeComment",
    "onRemoveComment",
    "setAdminTableData",
    "AdminTableData*",
    "adminTableData",
    "setCurrentUser",
    "user",
    "setErrorMessage",
    "error",
    "setIsLoading",
    "isLoading",
    "setIsLoggedIn",
    "requestLoginUser",
    "body",
    "requestRegisterUser",
    "registerUser",
    "requestUpdateUser",
    "profile",
    "requestAddComicToFavorite",
    "comicId",
    "requestFindUser",
    "localId",
    "requestCreateAuthor",
    "author",
    "requestUpdateAuthor",
    "authorId",
    "requestDeleteAuthor",
    "requestFindAuthor",
    "requestAuthorList",
    "limit",
    "options",
    "requestCreateCategory",
    "category",
    "requestUpdateCategory",
    "categoryId",
    "requestFindCategory",
    "requestRemoveCategory",
    "requestCategoryList",
    "requestCreateComic",
    "comic",
    "requestUpdateComic",
    "requestComicList",
    "option",
    "requestRemoveComic",
    "requestFindComic",
    "requestLikeComic",
    "requestViewComic",
    "requestFindComment",
    "comment",
    "requestReplyComment",
    "requestLikeComment",
    "requestRemoveComment",
    "getRequestPtr",
    "Request*",
    "getResponsePtr",
    "Response*",
    "findActiveAgent",
    "requestUsersList",
    "currentUser",
    "errorMessage",
    "isLoggedIn"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Admin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      98,   14, // methods
       5,  898, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      36,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  602,    2, 0x06,    6 /* Public */,
       3,    0,  603,    2, 0x06,    7 /* Public */,
       4,    0,  604,    2, 0x06,    8 /* Public */,
       5,    0,  605,    2, 0x06,    9 /* Public */,
       6,    0,  606,    2, 0x06,   10 /* Public */,
       7,    1,  607,    2, 0x06,   11 /* Public */,
       9,    0,  610,    2, 0x06,   13 /* Public */,
      10,    1,  611,    2, 0x06,   14 /* Public */,
      11,    1,  614,    2, 0x06,   16 /* Public */,
      13,    1,  617,    2, 0x06,   18 /* Public */,
      14,    1,  620,    2, 0x06,   20 /* Public */,
      16,    1,  623,    2, 0x06,   22 /* Public */,
      18,    1,  626,    2, 0x06,   24 /* Public */,
      19,    1,  629,    2, 0x06,   26 /* Public */,
      20,    1,  632,    2, 0x06,   28 /* Public */,
      22,    1,  635,    2, 0x06,   30 /* Public */,
      24,    1,  638,    2, 0x06,   32 /* Public */,
      25,    1,  641,    2, 0x06,   34 /* Public */,
      26,    1,  644,    2, 0x06,   36 /* Public */,
      27,    1,  647,    2, 0x06,   38 /* Public */,
      29,    1,  650,    2, 0x06,   40 /* Public */,
      31,    1,  653,    2, 0x06,   42 /* Public */,
      32,    1,  656,    2, 0x06,   44 /* Public */,
      33,    1,  659,    2, 0x06,   46 /* Public */,
      34,    1,  662,    2, 0x06,   48 /* Public */,
      36,    1,  665,    2, 0x06,   50 /* Public */,
      38,    1,  668,    2, 0x06,   52 /* Public */,
      39,    1,  671,    2, 0x06,   54 /* Public */,
      41,    1,  674,    2, 0x06,   56 /* Public */,
      42,    1,  677,    2, 0x06,   58 /* Public */,
      43,    1,  680,    2, 0x06,   60 /* Public */,
      44,    1,  683,    2, 0x06,   62 /* Public */,
      45,    1,  686,    2, 0x06,   64 /* Public */,
      46,    1,  689,    2, 0x06,   66 /* Public */,
      47,    1,  692,    2, 0x06,   68 /* Public */,
      48,    1,  695,    2, 0x06,   70 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      49,    1,  698,    2, 0x08,   72 /* Private */,
      51,    1,  701,    2, 0x08,   74 /* Private */,
      52,    1,  704,    2, 0x08,   76 /* Private */,
      53,    1,  707,    2, 0x08,   78 /* Private */,
      54,    1,  710,    2, 0x08,   80 /* Private */,
      55,    1,  713,    2, 0x08,   82 /* Private */,
      56,    1,  716,    2, 0x08,   84 /* Private */,
      57,    1,  719,    2, 0x08,   86 /* Private */,
      58,    1,  722,    2, 0x08,   88 /* Private */,
      59,    1,  725,    2, 0x08,   90 /* Private */,
      60,    1,  728,    2, 0x08,   92 /* Private */,
      61,    1,  731,    2, 0x08,   94 /* Private */,
      62,    1,  734,    2, 0x08,   96 /* Private */,
      63,    1,  737,    2, 0x08,   98 /* Private */,
      64,    1,  740,    2, 0x08,  100 /* Private */,
      65,    1,  743,    2, 0x08,  102 /* Private */,
      66,    1,  746,    2, 0x08,  104 /* Private */,
      67,    1,  749,    2, 0x08,  106 /* Private */,
      68,    1,  752,    2, 0x08,  108 /* Private */,
      69,    1,  755,    2, 0x08,  110 /* Private */,
      70,    1,  758,    2, 0x08,  112 /* Private */,
      71,    1,  761,    2, 0x08,  114 /* Private */,
      72,    1,  764,    2, 0x08,  116 /* Private */,
      73,    1,  767,    2, 0x08,  118 /* Private */,
      74,    1,  770,    2, 0x08,  120 /* Private */,
      75,    1,  773,    2, 0x08,  122 /* Private */,
      76,    1,  776,    2, 0x08,  124 /* Private */,
      77,    1,  779,    2, 0x0a,  126 /* Public */,
      80,    1,  782,    2, 0x0a,  128 /* Public */,
      82,    1,  785,    2, 0x0a,  130 /* Public */,
      84,    1,  788,    2, 0x0a,  132 /* Public */,
      86,    1,  791,    2, 0x0a,  134 /* Public */,
      87,    1,  794,    2, 0x0a,  136 /* Public */,
      89,    1,  797,    2, 0x0a,  138 /* Public */,
      91,    1,  800,    2, 0x0a,  140 /* Public */,
      93,    1,  803,    2, 0x0a,  142 /* Public */,
      95,    1,  806,    2, 0x0a,  144 /* Public */,
      97,    1,  809,    2, 0x0a,  146 /* Public */,
      99,    2,  812,    2, 0x0a,  148 /* Public */,
     101,    1,  817,    2, 0x0a,  151 /* Public */,
     102,    1,  820,    2, 0x0a,  153 /* Public */,
     103,    2,  823,    2, 0x0a,  155 /* Public */,
     106,    1,  828,    2, 0x0a,  158 /* Public */,
     108,    2,  831,    2, 0x0a,  160 /* Public */,
     110,    1,  836,    2, 0x0a,  163 /* Public */,
     111,    1,  839,    2, 0x0a,  165 /* Public */,
     112,    2,  842,    2, 0x0a,  167 /* Public */,
     113,    1,  847,    2, 0x0a,  170 /* Public */,
     115,    2,  850,    2, 0x0a,  172 /* Public */,
     116,    2,  855,    2, 0x0a,  175 /* Public */,
     118,    1,  860,    2, 0x0a,  178 /* Public */,
     119,    1,  863,    2, 0x0a,  180 /* Public */,
     120,    1,  866,    2, 0x0a,  182 /* Public */,
     121,    1,  869,    2, 0x0a,  184 /* Public */,
     122,    2,  872,    2, 0x0a,  186 /* Public */,
     124,    2,  877,    2, 0x0a,  189 /* Public */,
     125,    2,  882,    2, 0x0a,  192 /* Public */,
     126,    2,  887,    2, 0x0a,  195 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
     127,    0,  892,    2, 0x102,  198 /* Public | MethodIsConst  */,
     129,    0,  893,    2, 0x102,  199 /* Public | MethodIsConst  */,
     131,    0,  894,    2, 0x02,  200 /* Public */,
     132,    1,  895,    2, 0x02,  201 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 21,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 28,    2,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 35,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 40,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,
    QMetaType::Void, 0x80000000 | 37,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, QMetaType::QJsonDocument,   50,
    QMetaType::Void, 0x80000000 | 78,   79,
    QMetaType::Void, 0x80000000 | 17,   81,
    QMetaType::Void, 0x80000000 | 8,   83,
    QMetaType::Void, QMetaType::Bool,   85,
    QMetaType::Void, QMetaType::Bool,   85,
    QMetaType::Void, QMetaType::QVariantMap,   88,
    QMetaType::Void, QMetaType::QVariantMap,   90,
    QMetaType::Void, 0x80000000 | 17,   92,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void, QMetaType::QVariantMap,   98,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,  100,   98,
    QMetaType::Void, QMetaType::QString,  100,
    QMetaType::Void, QMetaType::QString,  100,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantMap,  104,  105,
    QMetaType::Void, QMetaType::QVariantMap,  107,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,  109,  107,
    QMetaType::Void, QMetaType::QString,  109,
    QMetaType::Void, QMetaType::QString,  109,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantMap,  104,  105,
    QMetaType::Void, QMetaType::QVariantMap,  114,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   94,  114,
    QMetaType::Void, QMetaType::Int, QMetaType::QVariantMap,  104,  117,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString,   94,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   94,  123,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   94,  123,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   94,  123,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   94,  123,

 // methods: parameters
    0x80000000 | 128,
    0x80000000 | 130,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,    2,

 // properties: name, type, flags
     133, 0x80000000 | 17, 0x0001510b, uint(0), 0,
     134, 0x80000000 | 8, 0x0001510b, uint(1), 0,
      85, QMetaType::Bool, 0x00015103, uint(2), 0,
      79, 0x80000000 | 78, 0x0001510b, uint(3), 0,
     135, QMetaType::Bool, 0x00015103, uint(4), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Admin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Admin.offsetsAndSizes,
    qt_meta_data_Admin,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Admin_t,
        // property 'currentUser'
        QtPrivate::TypeAndForceComplete<res::FoundUser, std::true_type>,
        // property 'errorMessage'
        QtPrivate::TypeAndForceComplete<res::Error, std::true_type>,
        // property 'isLoading'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'adminTableData'
        QtPrivate::TypeAndForceComplete<AdminTableData*, std::true_type>,
        // property 'isLoggedIn'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Admin, std::true_type>,
        // method 'currentUserChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'errorMessageChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isLoadingChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'adminTableDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isLoggedInChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::Error, std::false_type>,
        // method 'registeredSuccessfully'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readLoginResponseError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Error, std::false_type>,
        // method 'readLoginResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Login, std::false_type>,
        // method 'readRegisterResponseError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Error, std::false_type>,
        // method 'readRegisterResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Register, std::false_type>,
        // method 'readFindUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::FoundUser, std::false_type>,
        // method 'readUpdatedUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::FoundUser, std::false_type>,
        // method 'readAddComicToFavorite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::FoundUser, std::false_type>,
        // method 'readUsersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<res::FoundUser>, std::false_type>,
        // method 'readCreateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Author, std::false_type>,
        // method 'readUpdateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Author, std::false_type>,
        // method 'readDeleteAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Author, std::false_type>,
        // method 'readFindAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Author, std::false_type>,
        // method 'readAuthorList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<res::Author>, std::false_type>,
        // method 'readCreateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Category, std::false_type>,
        // method 'readUpdateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Category, std::false_type>,
        // method 'readFindCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Category, std::false_type>,
        // method 'readRemoveCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Category, std::false_type>,
        // method 'readCategoryList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<res::Category>, std::false_type>,
        // method 'readCreateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readUpdateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readComicList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<res::Comic>, std::false_type>,
        // method 'readRemoveComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readFindComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readLikeComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readViewComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readFindComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readReplyComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readLikeComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'readRemoveComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<res::Comic, std::false_type>,
        // method 'onLoginUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRegisterUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onFindActiveAgent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onUpdateUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onAddComicToFavorite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onUsersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onCreateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onUpdateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onDeleteAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onFindAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onAuthorList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onCreateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onUpdateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onFindCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRemoveCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onCategoryList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onCreateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onUpdateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onComicList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRemoveComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onFindComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onLikeComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onViewComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onFindComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onReplyComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onLikeComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'onRemoveComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QJsonDocument, std::false_type>,
        // method 'setAdminTableData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<AdminTableData *, std::false_type>,
        // method 'setCurrentUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser &, std::false_type>,
        // method 'setErrorMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::Error &, std::false_type>,
        // method 'setIsLoading'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'setIsLoggedIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const bool, std::false_type>,
        // method 'requestLoginUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'requestRegisterUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>,
        // method 'requestUpdateUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const res::FoundUser, std::false_type>,
        // method 'requestAddComicToFavorite'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestFindUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestCreateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestUpdateAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestDeleteAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestFindAuthor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestAuthorList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestCreateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestUpdateCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestFindCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestRemoveCategory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestCategoryList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestCreateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestUpdateComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestComicList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestRemoveComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestFindComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestLikeComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestViewComic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        // method 'requestFindComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestReplyComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestLikeComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'requestRemoveComment'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap, std::false_type>,
        // method 'getRequestPtr'
        QtPrivate::TypeAndForceComplete<Request *, std::false_type>,
        // method 'getResponsePtr'
        QtPrivate::TypeAndForceComplete<Response *, std::false_type>,
        // method 'findActiveAgent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestUsersList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantMap &, std::false_type>
    >,
    nullptr
} };

void Admin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Admin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentUserChanged(); break;
        case 1: _t->errorMessageChanged(); break;
        case 2: _t->isLoadingChanged(); break;
        case 3: _t->adminTableDataChanged(); break;
        case 4: _t->isLoggedInChanged(); break;
        case 5: _t->requestError((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        case 6: _t->registeredSuccessfully(); break;
        case 7: _t->readLoginResponseError((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        case 8: _t->readLoginResponse((*reinterpret_cast< std::add_pointer_t<res::Login>>(_a[1]))); break;
        case 9: _t->readRegisterResponseError((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        case 10: _t->readRegisterResponse((*reinterpret_cast< std::add_pointer_t<res::Register>>(_a[1]))); break;
        case 11: _t->readFindUser((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 12: _t->readUpdatedUser((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 13: _t->readAddComicToFavorite((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 14: _t->readUsersList((*reinterpret_cast< std::add_pointer_t<QList<res::FoundUser>>>(_a[1]))); break;
        case 15: _t->readCreateAuthor((*reinterpret_cast< std::add_pointer_t<res::Author>>(_a[1]))); break;
        case 16: _t->readUpdateAuthor((*reinterpret_cast< std::add_pointer_t<res::Author>>(_a[1]))); break;
        case 17: _t->readDeleteAuthor((*reinterpret_cast< std::add_pointer_t<res::Author>>(_a[1]))); break;
        case 18: _t->readFindAuthor((*reinterpret_cast< std::add_pointer_t<res::Author>>(_a[1]))); break;
        case 19: _t->readAuthorList((*reinterpret_cast< std::add_pointer_t<QList<res::Author>>>(_a[1]))); break;
        case 20: _t->readCreateCategory((*reinterpret_cast< std::add_pointer_t<res::Category>>(_a[1]))); break;
        case 21: _t->readUpdateCategory((*reinterpret_cast< std::add_pointer_t<res::Category>>(_a[1]))); break;
        case 22: _t->readFindCategory((*reinterpret_cast< std::add_pointer_t<res::Category>>(_a[1]))); break;
        case 23: _t->readRemoveCategory((*reinterpret_cast< std::add_pointer_t<res::Category>>(_a[1]))); break;
        case 24: _t->readCategoryList((*reinterpret_cast< std::add_pointer_t<QList<res::Category>>>(_a[1]))); break;
        case 25: _t->readCreateComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 26: _t->readUpdateComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 27: _t->readComicList((*reinterpret_cast< std::add_pointer_t<QList<res::Comic>>>(_a[1]))); break;
        case 28: _t->readRemoveComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 29: _t->readFindComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 30: _t->readLikeComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 31: _t->readViewComic((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 32: _t->readFindComment((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 33: _t->readReplyComment((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 34: _t->readLikeComment((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 35: _t->readRemoveComment((*reinterpret_cast< std::add_pointer_t<res::Comic>>(_a[1]))); break;
        case 36: _t->onLoginUser((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 37: _t->onRegisterUser((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 38: _t->onFindActiveAgent((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 39: _t->onUpdateUser((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 40: _t->onAddComicToFavorite((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 41: _t->onUsersList((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 42: _t->onCreateAuthor((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 43: _t->onUpdateAuthor((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 44: _t->onDeleteAuthor((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 45: _t->onFindAuthor((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 46: _t->onAuthorList((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 47: _t->onCreateCategory((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 48: _t->onUpdateCategory((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 49: _t->onFindCategory((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 50: _t->onRemoveCategory((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 51: _t->onCategoryList((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 52: _t->onCreateComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 53: _t->onUpdateComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 54: _t->onComicList((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 55: _t->onRemoveComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 56: _t->onFindComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 57: _t->onLikeComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 58: _t->onViewComic((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 59: _t->onFindComment((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 60: _t->onReplyComment((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 61: _t->onLikeComment((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 62: _t->onRemoveComment((*reinterpret_cast< std::add_pointer_t<QJsonDocument>>(_a[1]))); break;
        case 63: _t->setAdminTableData((*reinterpret_cast< std::add_pointer_t<AdminTableData*>>(_a[1]))); break;
        case 64: _t->setCurrentUser((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 65: _t->setErrorMessage((*reinterpret_cast< std::add_pointer_t<res::Error>>(_a[1]))); break;
        case 66: _t->setIsLoading((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 67: _t->setIsLoggedIn((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 68: _t->requestLoginUser((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 69: _t->requestRegisterUser((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 70: _t->requestUpdateUser((*reinterpret_cast< std::add_pointer_t<res::FoundUser>>(_a[1]))); break;
        case 71: _t->requestAddComicToFavorite((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 72: _t->requestFindUser((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 73: _t->requestCreateAuthor((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 74: _t->requestUpdateAuthor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 75: _t->requestDeleteAuthor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 76: _t->requestFindAuthor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 77: _t->requestAuthorList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 78: _t->requestCreateCategory((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 79: _t->requestUpdateCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 80: _t->requestFindCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 81: _t->requestRemoveCategory((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 82: _t->requestCategoryList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 83: _t->requestCreateComic((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        case 84: _t->requestUpdateComic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 85: _t->requestComicList((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 86: _t->requestRemoveComic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 87: _t->requestFindComic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 88: _t->requestLikeComic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 89: _t->requestViewComic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 90: _t->requestFindComment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 91: _t->requestReplyComment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 92: _t->requestLikeComment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 93: _t->requestRemoveComment((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2]))); break;
        case 94: { Request* _r = _t->getRequestPtr();
            if (_a[0]) *reinterpret_cast< Request**>(_a[0]) = std::move(_r); }  break;
        case 95: { Response* _r = _t->getResponsePtr();
            if (_a[0]) *reinterpret_cast< Response**>(_a[0]) = std::move(_r); }  break;
        case 96: _t->findActiveAgent(); break;
        case 97: _t->requestUsersList((*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 63:
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
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::currentUserChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::errorMessageChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::isLoadingChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::adminTableDataChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::isLoggedInChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Admin::*)(const res::Error );
            if (_t _q_method = &Admin::requestError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Admin::*)();
            if (_t _q_method = &Admin::registeredSuccessfully; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Error );
            if (_t _q_method = &Admin::readLoginResponseError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Login );
            if (_t _q_method = &Admin::readLoginResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Error );
            if (_t _q_method = &Admin::readRegisterResponseError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Register );
            if (_t _q_method = &Admin::readRegisterResponse; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::FoundUser );
            if (_t _q_method = &Admin::readFindUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::FoundUser );
            if (_t _q_method = &Admin::readUpdatedUser; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::FoundUser );
            if (_t _q_method = &Admin::readAddComicToFavorite; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Admin::*)(const QList<res::FoundUser> );
            if (_t _q_method = &Admin::readUsersList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Author );
            if (_t _q_method = &Admin::readCreateAuthor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Author );
            if (_t _q_method = &Admin::readUpdateAuthor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Author );
            if (_t _q_method = &Admin::readDeleteAuthor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Author );
            if (_t _q_method = &Admin::readFindAuthor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (Admin::*)(QList<res::Author> );
            if (_t _q_method = &Admin::readAuthorList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Category );
            if (_t _q_method = &Admin::readCreateCategory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Category );
            if (_t _q_method = &Admin::readUpdateCategory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Category );
            if (_t _q_method = &Admin::readFindCategory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Category );
            if (_t _q_method = &Admin::readRemoveCategory; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (Admin::*)(QList<res::Category> );
            if (_t _q_method = &Admin::readCategoryList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readCreateComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readUpdateComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (Admin::*)(QList<res::Comic> );
            if (_t _q_method = &Admin::readComicList; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readRemoveComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readFindComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readLikeComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readViewComic; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readFindComment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readReplyComment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readLikeComment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (Admin::*)(res::Comic );
            if (_t _q_method = &Admin::readRemoveComment; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 35;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AdminTableData* >(); break;
        }
    }
else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Admin *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< res::FoundUser*>(_v) = _t->currentUser(); break;
        case 1: *reinterpret_cast< res::Error*>(_v) = _t->errorMessage(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->isLoading(); break;
        case 3: *reinterpret_cast< AdminTableData**>(_v) = _t->adminTableData(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isLoggedIn(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Admin *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentUser(*reinterpret_cast< res::FoundUser*>(_v)); break;
        case 1: _t->setErrorMessage(*reinterpret_cast< res::Error*>(_v)); break;
        case 2: _t->setIsLoading(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setAdminTableData(*reinterpret_cast< AdminTableData**>(_v)); break;
        case 4: _t->setIsLoggedIn(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Admin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Admin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Admin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Admin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 98)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 98;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 98)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 98;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Admin::currentUserChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Admin::errorMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Admin::isLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Admin::adminTableDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Admin::isLoggedInChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Admin::requestError(const res::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Admin::registeredSuccessfully()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Admin::readLoginResponseError(res::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Admin::readLoginResponse(res::Login _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Admin::readRegisterResponseError(res::Error _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Admin::readRegisterResponse(res::Register _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Admin::readFindUser(res::FoundUser _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Admin::readUpdatedUser(res::FoundUser _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Admin::readAddComicToFavorite(res::FoundUser _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Admin::readUsersList(const QList<res::FoundUser> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Admin::readCreateAuthor(res::Author _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Admin::readUpdateAuthor(res::Author _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Admin::readDeleteAuthor(res::Author _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Admin::readFindAuthor(res::Author _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Admin::readAuthorList(QList<res::Author> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Admin::readCreateCategory(res::Category _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Admin::readUpdateCategory(res::Category _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Admin::readFindCategory(res::Category _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Admin::readRemoveCategory(res::Category _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Admin::readCategoryList(QList<res::Category> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Admin::readCreateComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void Admin::readUpdateComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void Admin::readComicList(QList<res::Comic> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void Admin::readRemoveComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void Admin::readFindComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void Admin::readLikeComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void Admin::readViewComic(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void Admin::readFindComment(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void Admin::readReplyComment(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void Admin::readLikeComment(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void Admin::readRemoveComment(res::Comic _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
