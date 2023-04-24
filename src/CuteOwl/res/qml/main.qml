import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

ApplicationWindow
{
    id: appWindow
    visible: true
    width: 820; height: 512

    Dialog
    {
        id: dialog
        modal: true
        visible: false
        anchors.centerIn: parent

        title: "Title"
        standardButtons: Dialog.Ok | Dialog.Cancel


        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
    }

    menuBar: MenuBar
    {
        id:menu
        visible: false

        Menu
        {
            title: qsTr("File")
            MenuItem
            {
                text: qsTr("Open")
                onTriggered: dialog.visible = true
            }
            MenuItem
            {
                text: qsTr("Save")
            }
            MenuItem
            {
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    header: ToolBar
    {
        RowLayout 
        {
            anchors.fill: parent
            ToolButton 
            {
                text: qsTr("New Server")
//                icon: "qrc:/images/splash-bg.png"
                onClicked: stack.pop()
                icon.source: "/Users/addy/src/lulzapps/CuteOwl/src/CuteOwl/res/images/spash-bg.png"
            }
            
            Label 
            {
                text: "Title"
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }
            
            ToolButton 
            {
                text: qsTr("⋮")
                // onClicked: menu.open()
                onClicked: menu.visible = !menu.visible
            }
        }
    }

    Rectangle 
    {
         id: page
        // width: 320; height: 480
        color: "lightgray"
        anchors.fill: parent

        Text 
        {
            id: helloText
            text: "Hello world!"
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }
    }

    StackView
    {
        id: stack
        anchors.fill: parent
    }
}

// Rectangle 
// {
//     id: page
//     width: 320; height: 480
//     color: "lightgray"

//     Text 
//     {
//         id: helloText
//         text: "Hello world!"
//         y: 30
//         anchors.horizontalCenter: page.horizontalCenter
//         font.pointSize: 24; font.bold: true
//     }
// }
