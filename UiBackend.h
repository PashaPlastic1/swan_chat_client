#ifndef UIBACKEND_H
#define UIBACKEND_H

#include <QObject>
#include <QQmlContext>

#include "ModelFactory.h"

class UiBackend : public QObject
{
    Q_OBJECT
public:
    explicit UiBackend(QQmlContext* mainContext, QObject *parent = nullptr);

    bool initContextPropeties();

signals:

private:
    QQmlContext* m_rootContext;

    ModelFactory m_modelFactory;
};

#endif // UIBACKEND_H
