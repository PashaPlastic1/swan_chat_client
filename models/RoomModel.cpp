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
    //------------------------------------------------------------------------------------------
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

        m_items.append({title, image, privateType, userNum, nullptr});
    }
    //------------------------------------------------------------------------------------------
    {
        QString title = "Gey Squad3";

        QImage myImage(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray bArray;
        QBuffer buffer(&bArray);
        buffer.open(QIODevice::WriteOnly);
        myImage.save(&buffer, "JPEG");
        QString image("data:image/jpg;base64,");
        image.append(QString::fromLatin1(bArray.toBase64().data()));

        RoomNamespace::PrivateType privateType = RoomNamespace::LookAtMe;

        int userNum{3};

        RoomTileModel* roomTileModel = new RoomTileModel();

        QString userName1 = "Ярик";

        QImage userImage1(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray userArray1;
        QBuffer userBuffer1(&userArray1);
        userBuffer1.open(QIODevice::WriteOnly);
        userImage1.save(&userBuffer1, "JPEG");
        QString userImageStr1("data:image/jpg;base64,");
        userImageStr1.append(QString::fromLatin1(userArray1.toBase64().data()));

        RoomNamespace::WhoSendType whoSendType1 = RoomNamespace::UserSendType;

        QString message1 = "Когда будем играть???";

        roomTileModel->setItem({userName1, userImageStr1, whoSendType1, message1});

        QString userName2 = "СерГей";

        QImage userImage2(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray userArray2;
        QBuffer userBuffer2(&userArray2);
        userBuffer2.open(QIODevice::WriteOnly);
        userImage2.save(&userBuffer2, "JPEG");
        QString userImageStr2("data:image/jpg;base64,");
        userImageStr2.append(QString::fromLatin1(userArray2.toBase64().data()));

        RoomNamespace::WhoSendType whoSendType2 = RoomNamespace::UserSendType;

        QString message2 = "Ща пропержусь и го";

        roomTileModel->setItem({userName2, userImageStr2, whoSendType2, message2});

        QString userName3 = "СерГей";

        QImage userImage3(QCoreApplication::applicationDirPath() + "/test_room_imag_1.png");
        QByteArray userArray3;
        QBuffer userBuffer3(&userArray3);
        userBuffer3.open(QIODevice::WriteOnly);
        userImage3.save(&userBuffer3, "JPEG");
        QString userImageStr3("data:image/jpg;base64,");
        userImageStr3.append(QString::fromLatin1(userArray3.toBase64().data()));

        RoomNamespace::WhoSendType whoSendType3 = RoomNamespace::UserSendType;

        QString message3 = "Соррян пацаны, я пернул с подливой";

        roomTileModel->setItem({userName3, userImageStr3, whoSendType3, message3});

        m_items.append({title, image, privateType, userNum, roomTileModel});
    }
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
    beginInsertRows(QModelIndex(), 0, 0);
    m_items.prepend(item);
    endInsertRows();
}
