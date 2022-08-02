import QtQuick 2.5
import QtQuick.Controls 1.4
import QtLocation 5.9
import QtPositioning 5.5
import QtQml 2.0

Rectangle {
    width: 360
    height: 640

    property double paket: 0
    property double paket1: 0

    Connections{
        target: mainWidget
        onGps:{
           // label1.text = basinc
            paket = latitude
            paket1 = longtitude
            //console.log(paket)
        }
    }

    //! [Initialize Plugin]
    Plugin {
        id: myPlugin
        name: "osm"
        // "mapboxgl", "esri", ...
        //specify plugin parameters if necessary
        //PluginParameter {...}
        //PluginParameter {...}
        //...
    }
    //! [Initialize Plugin]
    property var locationErz: QtPositioning.coordinate( paket1, paket)
    //! [Current Location]
    PositionSource {
        id: positionSource
        property variant lastSearchPosition: locationErz
        active: true
        updateInterval: 1000 // 2 mins
        onPositionChanged:  {
            var currentPosition = positionSource.position.coordinate
            map.center = currentPosition
        }
    }
    //! [Current Location]

    //! [PlaceSearchModel]
    property variant locationOslo: QtPositioning.coordinate(39.925533,32.866287)

    //    PlaceSearchModel {
    //        id: searchModel

    //        plugin: myPlugin

    //        searchTerm: "turkey"
    //        searchArea: QtPositioning.circle(locationOslo)

    //        Component.onCompleted: update()
    //    }
    //! [PlaceSearchModel]

    //! [Places MapItemView]
    Map {
        id: map
        anchors.fill: parent
        plugin: myPlugin;
        center: locationOslo
        zoomLevel: 8


        MapQuickItem {
            id: uyduKonum
            coordinate: locationErz

            anchorPoint.x: image.width * 0.5
            anchorPoint.y: image.height

            sourceItem: Column {
                Image { id: image; source: "image/marker.png" }

            }
        }

        GeocodeModel {
            id: geoModel
            plugin: map.plugin
            onStatusChanged: {
                if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
                    map.geocodeFinished()
            }
            onLocationsChanged:
            {
                if (count == 1) {
                    map.center.latitude = get(0).coordinate.latitude
                    map.center.longitude = get(0).coordinate.longitude
                }
            }

        }
    }
}
