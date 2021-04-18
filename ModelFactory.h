#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <QObject>

#include "models/RoomModel.h"

class ModelFactory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* roomModel READ roomModel)

public:
    explicit ModelFactory(QObject *parent = nullptr);
    QAbstractListModel* roomModel();

public slots:

private:
    void initRoomModel();


private:
    RoomModel* m_roomModel;
};

#endif // MODELFACTORY_H
