#include "ModelFactory.h"

ModelFactory::ModelFactory(QObject *parent) :
    QObject(parent),
    m_roomModel(nullptr)
{

}

QAbstractListModel *ModelFactory::roomModel()
{
    if (!m_roomModel)
        initRoomModel();

    return m_roomModel;
}

void ModelFactory::initRoomModel()
{
    m_roomModel = new RoomModel(this);

    // test
    m_roomModel->testInitModel();
}
