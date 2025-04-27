/****************************************************************************
 *
 * (c) 2009-2020 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQml.Models

import QGroundControl
import QGroundControl.Controls
import PythonManager

import QtQuick

ToolStripActionList {
    id: _root

    signal displayPreFlightChecklist

    model: [
        Item{
            PythonManager{
                id: pythonManager
            }
            visible: false
        },
        ToolStripAction {
            property bool _is3DViewOpen:            viewer3DWindow.isOpen
            property bool   _viewer3DEnabled:       QGroundControl.settingsManager.viewer3DSettings.enabled.rawValue

            id: view3DIcon
            visible: _viewer3DEnabled
            text:           qsTr("3D View")
            iconSource:     "/qmlimages/Viewer3D/City3DMapIcon.svg"
            onTriggered:{
                if(_is3DViewOpen === false){
                    viewer3DWindow.open()
                }else{
                    viewer3DWindow.close()
                }
            }

            on_Is3DViewOpenChanged: {
                if(_is3DViewOpen === true){
                    view3DIcon.iconSource =     "/qmlimages/PaperPlane.svg"
                    text=           qsTr("Fly")
                }else{
                    iconSource =     "/qmlimages/Viewer3D/City3DMapIcon.svg"
                    text =           qsTr("3D View")
                }
            }
        },
        ToolStripAction {
            text: qsTr("Down")
            onTriggered:{
                console.debug("Call python 1 onTriggered")
                pythonManager.callPythonScript()
            }
        },
        ToolStripAction {
            text: qsTr("Left")
            onTriggered:{
                console.debug("Call python 1 onTriggered")
                pythonManager.callPythonScript()
            }
        },
        ToolStripAction {
            text: qsTr("Right")
            onTriggered:{
                console.debug("Call python 1 onTriggered")
                pythonManager.callPythonScript()
            }
        },
        ToolStripAction {
            text: qsTr("X")
            onTriggered:{
                console.debug("Call python 1 onTriggered")
                pythonManager.callPythonScript()
            }
        },
        PreFlightCheckListShowAction { onTriggered: displayPreFlightChecklist() },
        GuidedActionTakeoff { }, //San takeoff button location
        GuidedActionLand { },
        GuidedActionRTL { },
        GuidedActionPause { },
        FlyViewAdditionalActionsButton { },
        GuidedActionGripper { }
    ]
}
