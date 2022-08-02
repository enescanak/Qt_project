import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQml 2.0
Item {
    id: itemId
    width: 200
    height: 360
    visible: true
    property int durum

    Connections{
        target: mainWidget
        onDurum:{
            durum = hal


        }
    }
    Column {
        Rectangle {
            width: 200
            height: 40
            color: "black"
            Text {
                id: textId
                color: "white"
                font.pointSize: 16
                text: qsTr("Model Uydu Aşama")
                anchors.centerIn: parent


            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===0) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId1
                text: qsTr("Bekleme")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===1) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId2
                text: qsTr("Yükselme")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===2) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId3
                text: qsTr("Model Uydu İniş")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===3) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId4
                text: qsTr("Ayrılma")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===4) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId5
                text: qsTr("Görev Yükü İniş")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===5) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId6
                text: qsTr("Bonus Görev")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"
            color: if(durum ===6) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId7
                text: qsTr("Yere İniş")
                anchors.centerIn: parent
            }
        }
        Rectangle {
            width: 200
            height: 40
            border.color: "blue"

            color: if(durum ===7) {
                       "blue"
                   }
                    else {
                       "grey"
                   }

            Text {
                id: textId8
                text: qsTr("Kurtarma")
                anchors.centerIn: parent
            }
        }
    }
}
