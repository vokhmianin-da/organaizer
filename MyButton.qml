import QtQuick 2.0

BorderImage {
    id: name
    source: "qrc:///new/image/1button.png"
    signal clicked;
    property alias text: _txt.text
    width: _txt.width + 300
    height: _txt.height + 300
    border.left: 5; border.top: 5
    border.right: 5; border.bottom: 5

    Text {
        id: _txt
        color: "black"
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed: parent.source = "qrc:///new/image/2button.png"
        onReleased: parent.source = "qrc:///new/image/1button.png"
    }
}
