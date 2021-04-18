#include "RoomModel.h"
#include <QCoreApplication>
#include <QBuffer>

RoomModel::RoomModel(QObject *parent) :
    QAbstractListModel(parent),
    m_items()
{
}

void RoomModel::testInitModel()
{
    //------------------------------------------------------------------------------------------
    {
        QString title = "Gey Squad1";

        QImage myImage(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray bArray;
        QBuffer buffer(&bArray);
        buffer.open(QIODevice::WriteOnly);
        myImage.save(&buffer, "JPEG");
        QString image("data:image/jpg;base64,");
        image.append(QString::fromLatin1(bArray.toBase64().data()));

        RoomNamespace::PrivateType privateType = RoomNamespace::AbsoluteAnonymous;

        int userNum{3};

        RoomTileModel* roomTileModel = new RoomTileModel();

        QString userName = "Ярик";

        QImage userImage(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray userArray;
        QBuffer userBuffer(&userArray);
        userBuffer.open(QIODevice::WriteOnly);
        userImage.save(&userBuffer, "JPEG");
        QString userImageStr("data:image/jpg;base64,");
        userImageStr.append(QString::fromLatin1(userArray.toBase64().data()));

        RoomNamespace::WhoSendType whoSendType = RoomNamespace::UserSendType;

        QString message = "Когда будем играть???";

        roomTileModel->setItem({userName, userImageStr, whoSendType, message});
        m_items.append({title, image, privateType, userNum, roomTileModel});
    }

    {
        QString title = "Gey Squad2";

        QImage myImage(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray bArray;
        QBuffer buffer(&bArray);
        buffer.open(QIODevice::WriteOnly);
        myImage.save(&buffer, "JPEG");
        QString image("data:image/jpg;base64,");
        image.append(QString::fromLatin1(bArray.toBase64().data()));

        RoomNamespace::PrivateType privateType = RoomNamespace::AbsoluteAnonymous;

        int userNum{3};

//        RoomTileModel* roomTileModel = new RoomTileModel();

//        QString userName = "Ярик";

//        QImage userImage(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
//        QByteArray userArray;
//        QBuffer userBuffer(&userArray);
//        userBuffer.open(QIODevice::WriteOnly);
//        userImage.save(&userBuffer, "JPEG");
//        QString userImageStr("data:image/jpg;base64,");
//        userImageStr.append(QString::fromLatin1(userArray.toBase64().data()));

//        RoomNamespace::WhoSendType whoSendType = RoomNamespace::UserSendType;

//        QString message = "Когда будем играть???";

//        roomTileModel->setItem({userName, userImageStr, whoSendType, message});
        m_items.append({title, image, privateType, userNum, nullptr});
    }
    //------------------------------------------------------------------------------------------
//    m_items.append({"GeySquad", QImage})
}

int RoomModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

QVariant RoomModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case TitleRole:
        return m_items.at(index.row()).title;
    case RoomImageRole:
        return m_items.at(index.row()).roomImage;
    case PrivateTypeRole:
        return m_items.at(index.row()).privateType;
    case UserNumRole:
        return m_items.at(index.row()).userNum;
    case RoomTileModelRole:
        return QVariant::fromValue(m_items.at(index.row()).roomTileModel);
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> RoomModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[TitleRole] = "title";
    roles[RoomImageRole] = "roomImage";
    roles[PrivateTypeRole] = "privateType";
    roles[UserNumRole] = "userNum";
    roles[RoomTileModelRole] = "roomTitleModel";

    return roles;
}
//--------------------------------------------------------------

RoomTileModel::RoomTileModel(QObject *parent) :
    QAbstractListModel(parent),
    m_items()
{

}

int RoomTileModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.size();
}

QVariant RoomTileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case UserIdRole:
        return m_items.at(index.row()).userName;
    case UserImageRole:
        return m_items.at(index.row()).userImage;
    case WhoSendTypeRole:
        return m_items.at(index.row()).whoSendType;
    case MessageRole:
        return m_items.at(index.row()).message;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> RoomTileModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[UserIdRole] = "userId";
    roles[UserImageRole] = "userImage";
    roles[WhoSendTypeRole] = "whoSendType";
    roles[MessageRole] = "message";

    return roles;
}

void RoomTileModel::setItem(const RoomTileItem &item)
{
    m_items.append(item);
}
