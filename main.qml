import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1
import "./room_panel"
//import Qt5Compat.GraphicalEffects
//import QtQuick.VirtualKeyboard 2.15

ApplicationWindow {
    readonly property double scaleFactor: 0.3

    id: window
    width: 1080 * scaleFactor
    height: 2248 * scaleFactor
    visible: true
    title: qsTr("Scroll")

    background: Rectangle{
        color: "#121212"
//        opacity: 0.7
    }

    RoomPanel {
        anchors.fill: parent
        anchors.margins: 5
        myModel: ModelFactory.roomModel
    }

//    GridLayout {
//        anchors.fill: parent
//        columns: 3
//        Rectangle { color: "red"; Layout.preferredWidth: 50; Layout.preferredHeight: 50 }
//        Rectangle { color: "green"; Layout.preferredWidth: 20; Layout.preferredHeight: 70 }
//        Rectangle { color: "blue"; Layout.preferredWidth: 50; Layout.preferredHeight: 20 }
//        Rectangle { color: "cyan"; Layout.preferredWidth: 50; Layout.preferredHeight: 50 }
//        Rectangle { color: "magenta"; Layout.preferredWidth: 10; Layout.preferredHeight: 10 }
//    }



//    ScrollView {
//        anchors.fill: parent

//        ListView {
//            id: listView
//            width: parent.width
//            model: 20
//            delegate: ItemDelegate {
//                text: "Item " + (index + 1)
//                width: listView.width
//            }
//        }
//    }

//    InputPanel {
//        id: inputPanel
//        z: 99
//        x: 0
//        y: window.height
//        width: window.width

//        states: State {
//            name: "visible"
//            when: inputPanel.active
//            PropertyChanges {
//                target: inputPanel
//                y: window.height - inputPanel.height
//            }
//        }
//        transitions: Transition {
//            from: ""
//            to: "visible"
//            reversible: true
//            ParallelAnimation {
//                NumberAnimation {
//                    properties: "y"
//                    duration: 250
//                    easing.type: Easing.InOutQuad
//                }
//            }
//        }
//    }
}
