#ifndef ROOMMODEL_H
#define ROOMMODEL_H

#include <QAbstractListModel>
#include <QImage>

namespace RoomNamespace
{
    Q_NAMESPACE

    enum PrivateType {
        AbsoluteAnonymous = 0,
        Anonymous,
        LookAtMe
    };
    Q_ENUM_NS(PrivateType)

    enum WhoSendType {
        RoomSendType,
        UserSendType
    };
    Q_ENUM_NS(WhoSendType)
}

class RoomTileModel;

struct RoomModelItem {
    QString title;
    QString roomImage;
    RoomNamespace::PrivateType privateType;
    int userNum;
    RoomTileModel* roomTileModel = nullptr;
};

struct RoomTileItem {
    QString userName;
    QString userImage;
    RoomNamespace::WhoSendType whoSendType;
    QString message;
};

class RoomModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        TitleRole = Qt::UserRole,
        RoomImageRole,
        PrivateTypeRole,
        UserNumRole,
        RoomTileModelRole
    };
    explicit RoomModel(QObject *parent = nullptr);

    // tests
    void testInitModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<RoomModelItem> m_items;
};

class RoomTileModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        UserIdRole = Qt::UserRole,
        UserImageRole,
        WhoSendTypeRole,
        MessageRole
    };

    explicit RoomTileModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

public slots:
    void setItem(const RoomTileItem& item);

private:
    QList<RoomTileItem> m_items;
};

#endif // ROOMMODEL_H
