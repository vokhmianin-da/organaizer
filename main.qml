import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import TaskList 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Organaizer")

    TaskList{
        id: _taskList
    }

    Rectangle {
        id: rectangle1
        anchors.fill: parent

        width: 360
        height: 360

        MyButton {
            id: myButton1
            x: 40
            y: 217
            width: 134
            height: 81
            text: "Записать"
            onClicked: if(_nameTask.text) {_taskList.taskString = _nameTask.text + "; " + _endDate.text + "; " + _progress.text
                           _statusBar.text = "Успех"
                       textQuant.text = qsTr("Количество задач: ") + _taskList.quantityTasks}
            else _statusBar.text = "Введите название задачи"
        }

        Text {
            id: _statusBar
            y: 331
            width: 61
            height: 14
            anchors.left: parent.left
            anchors.leftMargin: 25
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 15
            font.pixelSize: 12
        }


        Text {
            id: text1
            x: 60
            y: 15
            width: 93
            height: 17
            text: qsTr("Название задачи")
            font.pixelSize: 12
        }

        Text {
            id: textQuant
            x: text1.x + 300
            y: 15
            width: 93
            height: 17
            text: qsTr("Количество задач: ") +_taskList.quantityTasks
            font.pixelSize: 12
        }

//        Text {
//            id: _quantityTasks
//            x: textQuant.x + textQuant.width + 30
//            y: textQuant.y
//            width: 61
//            height: 14
//            font.pixelSize: 12
//            text: "1"
//        }

        TextField {
            id: _nameTask
            x: 25
            y: 38
            width: 163
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        TextField {
            id: _endDate
            x: 25
            y: 96
            width: 163
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            validator: RegExpValidator {regExp: /^([0-2][0-9]|[3][0-1])[.]([0][1-9]|[1][0-2])[.]([0-2][0-9][0-9][0-9])$ /}
        }

        Text {
            id: text2
            x: 60
            y: 73
            width: 93
            height: 17
            text: qsTr("Дата окончания")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 60
            y: 140
            width: 93
            height: 17
            text: qsTr("Текущий прогресс")
            font.pixelSize: 12
        }

        Slider {
            id: _currentProgress
            x: 25
            y: 163
            width: 163
            height: 22
            stepSize: 1
            minimumValue: 0
            value: 0
            maximumValue: 10
        }

        Text {
            id: _progress
            x: 194
            y: 163
            width: 29
            height: 22
            horizontalAlignment: Text.AlignHCenter
            text: qsTr(_currentProgress.value.toString())
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 12
        }
    }

}
