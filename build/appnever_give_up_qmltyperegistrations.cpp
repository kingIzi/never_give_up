/****************************************************************************
** Generated QML type registration code
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/qqmlmoduleregistration.h>

#include <admintablemodel.hpp>

#if !defined(QT_STATIC)
#define Q_QMLTYPE_EXPORT Q_DECL_EXPORT
#else
#define Q_QMLTYPE_EXPORT
#endif

Q_QMLTYPE_EXPORT void qml_register_types_never_give_up()
{
    qmlRegisterTypesAndRevisions<AdminTableModel>("never_give_up", 1);
    qmlRegisterAnonymousType<QAbstractItemModel, 254>("never_give_up", 1);
    QMetaType::fromType<QAbstractTableModel *>().id();
    qmlRegisterModule("never_give_up", 1, 0);
}

static const QQmlModuleRegistration registration("never_give_up", qml_register_types_never_give_up);
