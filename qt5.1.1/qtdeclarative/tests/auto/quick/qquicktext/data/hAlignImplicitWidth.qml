import QtQuick 2.0

Rectangle {
    width: 200
    height: 100

    Text {
        objectName: "textItem"
        text: "AA\nBBBBB\nCCCCCCCCCCCCCCCC"
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignLeft
    }
}
