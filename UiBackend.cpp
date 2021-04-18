#include "UiBackend.h"

#include <QQmlEngine>

UiBackend::UiBackend(QQmlContext* mainContext, QObject *parent) :
    QObject(parent),
    m_rootContext(mainContext)
{
    qmlRegisterUncreatableMetaObject(
      RoomNamespace::staticMetaObject,
      "room.namespace",
      1, 0,
      "RoomNamespace",
      "Error: only enums"
    );
}

bool UiBackend::initContextPropeties()
{
    if (!m_rootContext ||
            !m_rootContext->isValid())
        return false;

    m_rootContext->setContextProperty("ModelFactory", &m_modelFactory);

    return true;
}
