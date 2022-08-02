import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQml 2.0
import QtQuick.Scene3D 2.0
import QtQuick.Dialogs 1.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import Qt3D.Logic 2.0
import Qt3D.Animation 2.12


Item {
    id: itemId
    width: 350
    height: 450
    visible: true

    property real rollAngle: 0.0
    property real pitchAngle: 0.0
    property real altitude: 0
    property real angle: 0.0
    property real scaleFactor: 10
    property double userAngle: 0.0

    Connections{
        target: mainWidget
        onXandy:{
            rollAngle = xAci
            //console.log(rollAngle)
            pitchAngle = yAci
        }
        onOnlyz: {
            angle = zAci
        }
    }

    Scene3D {
        id:scene3dId
        anchors.fill: parent
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
        multisample: true

        Entity {
            id: sceneRoot

            Camera {
                id: camera
                projectionType: CameraLens.PerspectiveProjection
                fieldOfView: 45
                aspectRatio: itemId.width/itemId/height
                nearPlane: 0.1
                farPlane: 1000.0
                position: Qt.vector3d(0.0,10.0,20.0)
                upVector: Qt.vector3d(0.0,0.0,0.0)
                viewCenter: Qt.vector3d(0.0,1.0,1.0)

            }

            OrbitCameraController {
                camera: camera

            }

            components: [
                RenderSettings {
                    activeFrameGraph: ForwardRenderer {
                        clearColor: Qt.rgba(0,0.5,1,1)
                        camera: camera
                    }
                },
                InputSettings {

                }
            ]
            Entity {
                id: monkeyEntity

                SceneLoader {
                    id:sceneLoader
                    source: "qrc:/image/gorevblender1.obj"
                }

                Transform {
                    id: toyplaneTransform
                    rotation: fromAxisAndAngle(Qt.vector3d(0, 1, 0), angle)
                }
                Transform {
                    id: trefoilTransform
                    rotation: fromAxisAndAngle(Qt.vector3d(1,0, 0), rollAngle)
                }
                Transform {
                    id: lastTransform
                    rotation: fromAxisAndAngle(Qt.vector3d(0,0, 1), pitchAngle)
                }

                ParallelAnimation {
                    running: true
                    loops: Animation.Infinite
                    NumberAnimation {
                        target: toyplaneTransform
                        property:"angle"
                        easing.type: Easing.Linear
                        duration: 1000
                        from: 0
                        to: angle
                    }
                    NumberAnimation {
                        target: trefoilTransform
                        property:"rollAngle"
                        easing.type: Easing.Linear
                        duration: 1000
                        from: 0
                        to: rollAngle
                    }
                    NumberAnimation {
                        target: lastTransform
                        property:"pitchAngle"
                        easing.type: Easing.Linear
                        duration: 1000
                        from: 0
                        to: pitchAngle
                    }
                }

                components: [
                    sceneLoader,
                    toyplaneTransform,
                    trefoilTransform,
                    lastTransform
                ]
            }
        }
    }
}

