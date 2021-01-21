import QtQuick 2.5

Rectangle {

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        x: 171
        y: 91
        width: 100
        height: 100
    }

    MyButton {
        id: myButton1
        x: 83
        y: 207
        width: 134
        height: 81
        text: "Записать"
    }
}
