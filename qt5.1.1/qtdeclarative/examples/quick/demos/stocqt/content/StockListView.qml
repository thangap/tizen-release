/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0

Rectangle {
    id: root
    width: 320
    height: 480
    color: "#423A2F"

    property string currentStockId: ""
    property string currentStockName: ""

    ListView {
        id: view
        anchors.fill: parent
        keyNavigationWraps: true
        focus: true
        snapMode: ListView.SnapToItem
        model: StockListModel{}

        onCurrentIndexChanged: {
            root.currentStockId = model.get(currentIndex).stockId;
            root.currentStockName = model.get(currentIndex).name;
            console.log("current stock:" + root.currentStockId + " - " + root.currentStockName);
        }

        delegate: Rectangle {
            height: 30
            width: parent.width
            color: "transparent"
            MouseArea {
                anchors.fill: parent;
                onClicked:view.currentIndex = index;
            }

            Text {
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset : 15
                color: index == view.currentIndex ? "#ECC089" : "#A58963"
                font.pointSize: 12
                font.bold: true
                text:"         " + stockId + " - " + name
            }
        }

        highlight: Rectangle {
            width: parent.width
            color: "#662"
        }
    }
}
