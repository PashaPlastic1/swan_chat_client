import QtQuick 2
import QtQuick.Controls 2
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2

GridLayout {
    property alias myModel: repeater.model
    property int cellHeight: 20

    id: root

    columns: 2

    Repeater {
        id: repeater

        delegate: RoomTile {
            id: roomTile
            Layout.fillWidth: true
//            Layout.preferredWidth: root.width / 2 - root.columnSpacing
            Layout.preferredHeight: elemenHeight * filledRowCount + 5
            Layout.rowSpan: filledRowCount
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            elemenHeight: cellHeight
        }

    }
}
