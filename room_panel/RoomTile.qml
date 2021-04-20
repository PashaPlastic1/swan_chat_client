import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.15
import room.namespace 1.0

Rectangle {
    property int elemenHeight
    property int titleScaleFactor: 4
    property int extraScaleFactor: 1
    property int messageScaleFactor: 2
    property var roomTileModel: model.roomTitleModel
    readonly property int filledRowCount: titleScaleFactor + extraScaleFactor + roomTileView.count * messageScaleFactor

    id: roomTile
    color: "transparent"
//    clip: true
//    radius: 6


    Image {
        id: backgroungImage
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: model.roomImage
//        clip: true
//        z: -1
        Rectangle {
            anchors.fill: parent
            color: Material.color(Material.Grey, Material.Shade900)
            radius: roomTile.radius
            opacity: 0.85
        }
    }

    Column {
        anchors.fill: parent
        anchors.leftMargin: 5
        anchors.rightMargin: 5
        spacing: 0
        Label {
            id: titleLabel
//            Layout.fillWidth: true
//            Layout.preferredHeight: 2 * roomTile.elemenHeight
//            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            width: parent.width
            height: titleScaleFactor * roomTile.elemenHeight
            text: model.title
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            color: Material.color(Material.Grey)
//            font.pixelSize: roomTile.elemenHeight * titleScaleFactor * 0.3
            fontSizeMode: Text.Fit
            minimumPixelSize: 14
            font.pixelSize: roomTile.elemenHeight * titleScaleFactor * 0.3
            wrapMode: Text.WordWrap
        }
        Row {
            id: extraDataRow
//            Layout.fillWidth: true
//            Layout.preferredHeight: roomTile.elemenHeight
//            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            width: parent.width
            height: extraScaleFactor * roomTile.elemenHeight
            spacing: 3
            clip: true
            Image {
                id: privatTypeImage
                clip: true
                height: extraDataRow.height
//                y: parent.height / 2 - height / 2
//                height: roomTile.elemenHeight * 0.4
                fillMode: Image.PreserveAspectFit
//                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                source: {
                    switch (model.privateType) {
                    case RoomNamespace.AbsoluteAnonymous:
                        return "qrc:/icons/anonymous.png";
                    case RoomNamespace.Anonymous:
                        return "qrc:/icons/superman.png";
                    case RoomNamespace.LookAtMe:
                        return "qrc:/icons/bender.png";
                    }
                }

                ColorOverlay {
                    anchors.fill: parent
                    source: parent
                    color: Material.color(Material.Grey)
                }
            }
            Label {
                id: userNumLabel
                height: extraDataRow.height
                text: model.userNum
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                color: Material.color(Material.Grey)
                font.pixelSize: roomTile.elemenHeight * extraScaleFactor
            }
        }

        ListView {
            id: roomTileView
//            Layout.preferredHeight: roomTile.messageScaleFactor * roomTile.elemenHeight * count
//            Layout.fillWidth: true
            width: parent.width
            height: roomTile.messageScaleFactor * roomTile.elemenHeight * count
            onCountChanged: console.log(index, "count:", count)

            model: roomTile.roomTileModel
            spacing: 0

            Component {
                id: userImageComponent
                Image {
                    fillMode: Image.PreserveAspectFit
                    source: userImage
                }
            }

            delegate: RowLayout {
                height: roomTile.messageScaleFactor * roomTile.elemenHeight
                width: roomTileView.width
                clip: true

                Loader {
                    property var userImage: model.userImage
//                    Layout.preferredHeight: roomTile.messageScaleFactor * roomTile.elemenHeight / 2
                    Layout.preferredHeight: messageLabel.font.pixelSize * 1.2
                    Layout.preferredWidth: parent.width * 0.1
                    Layout.alignment: Qt.AlignLeft | Qt.AlignVCenter

                    sourceComponent: {
                        switch (model.whoSendType) {
                        case RoomNamespace.RoomSendType:
                            return null;
                        case RoomNamespace.UserSendType:
                            return userImageComponent;
                        }
                    }
                }
                Label {
                    id: messageLabel
//                    height: parent.height
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: model.message
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    color: Material.color(Material.Grey)
                    elide: Text.ElideRight
                }
            }
        }
    }
}
