import QtQuick 2.15

ListView {
    width: 200; height: 250

    required model

    delegate: Text {
        required property string name
        required property string color

        text: "Animal: " + name + ", " + color
    }
}

//Rectangle
//{
//    id: page
//    width: 320; height: 480
//    color: "#ffffff"

//    ListView {
//        id: listView
//        width: 208
//        anchors.left: parent.left
//        anchors.top: parent.top
//        anchors.bottom: parent.bottom
//        anchors.bottomMargin: 0
//        anchors.leftMargin: 0
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.topMargin: 35
//        required property model

////        model: ListModel
////        {
////            ListElement { name: "Grey"; colorCode: "grey"; poop: 1 }
////            ListElement { name: "Red"; colorCode: "red"; poop: 12 }
////            ListElement { name: "Blue"; colorCode: "blue"; poop: 43 }
////            ListElement { name: "Green"; colorCode: "green"; poop: 987 }
////            ListElement { name: "Yellow"; colorCode: "yellow"; poop: 7665 }
////            ListElement { name: "Elephant"; colorCode: "purple"; poop: 67 }
////        }

//        delegate: Item
//        {
//            x: 5
//            width: 80
//            height: 40
//            Row
//            {
//                id: row1
//                height: 58
//                spacing: 10

//                Rectangle
//                {
//                    width: 40
//                    height: 40
//                    color: colorCode
//                }

//                Text
//                {
//                    text: name
//                    anchors.verticalCenter: parent.verticalCenter
//                    font.bold: true
//                }

//                Text
//                {
//                    text: poop
//                    anchors.verticalCenter: parent.verticalCenter
//                    font.bold: true
//                }
//            }
//        }
//    }
//}
