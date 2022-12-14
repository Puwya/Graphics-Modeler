import QtQuick 6.4
import QtQuick.Controls 6.4
import QtQuick.Window 6.4
import QtQuick.Controls.Material 2.3


Rectangle {
    readonly property int _CONTACT_WIDTH: 580
    readonly property int _CONTACT_HEIGHT: 420

    x: -12
    y: -12
    width: _CONTACT_WIDTH
    height: _CONTACT_HEIGHT

    color: "#2f2f2f"
    radius: 14
    border.color: "#ce93d8"
    border.width: 4

    Material.theme: Material.Dark
    Material.accent: Material.Purple

    Label {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 38
        color: "#ffffff"
        text: qsTr("Give us your Feedback")
        font.pointSize: 20
        font.bold: true
    }

    TextField {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 104
        width: 332
        height: 46
        placeholderText: qsTr("Email")
    }

    TextArea {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 158
        width: 332
        height: 172
        placeholderText: qsTr("Write something . . .")
    }

    Button {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 340
        width: 162
        height: 48
        text: qsTr("Send!")
        font.letterSpacing: 0
        font.capitalization: Font.Capitalize
        hoverEnabled: true
        font.bold: true
        checkable: false
        down: false
        flat: true
        checked: false
        highlighted: true
    }

    Button {
        x: 476
        y: 340
        width: 72
        height: 48
        text: qsTr("Back")
        font.letterSpacing: 0
        font.capitalization: Font.Capitalize
        hoverEnabled: true
        font.bold: true
        checkable: false
        down: false
        checked: false
        flat: true
        highlighted: true
        onClicked: parent_contact_us.close()
    }

    gradient: Gradient {
        orientation: Gradient.Vertical
        GradientStop {
            position: 0
            color: "#434343"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

