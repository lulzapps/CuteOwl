import QtQuick

Rectangle 
{
    id: page
    width: 320; height: 480
    color: "#ffffff"

    Text {
        id: helloText
        text: "Hello world!"
        font.family: "Verdana"
        font.pointSize: 24; font.bold: true
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: page.horizontalCenter
        anchors.top: page.top
        anchors.topMargin: 5
    }

    ListView {
        id: listView
        width: 208
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 35
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }
}
