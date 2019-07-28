import QtQuick 2.11
import QtQuick.Window 2.11
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        height: 100
        width: 200
        anchors.centerIn: parent
        text: "Start Fetching!"

        onClicked: {
            manager.startDownloadData();
        }

    }
}
