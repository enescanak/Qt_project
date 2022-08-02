import QtQuick 2.0
import QtQuick.Controls 2.0
import QtCharts 2.0
import QtQml 2.0

Item {
    width: 700
    height: 200
    visible: true

    property int paket3: 0
    property int paket4: 0

    property int test3: 0
    property int test4: 0

    Connections{
        target: mainWidget
        onDatas:{
            paket3 = basinc
            paket4 = yukseklik
        }
    }

    ChartView {
        id: chartView3
        x: 0
//            y:0
        width: 350
        height: 200
        title: "Basinc (Pa)"
        theme: ChartView.ChartThemeDark
//            anchors.fill: parent
        legend.alignment: Qt.AlignTop
        animationOptions: ChartView.SeriesAnimations
        antialiasing: true


        Timer{
            id: timerId3
            interval: 1000
            repeat: true
            triggeredOnStart: true
            running: true

            onTriggered: {
                //console.log("calisiyor")
                test3 += 1
                chartView3.axisX()
                //console.log(test)
                series4.append(test3,paket3);
            }
        }

        LineSeries {
            id: series4
            axisX: axisX3
            axisY: axisY3


        }
        ValueAxis {
            id: axisX3
            min: 0
            max: test3+2
            tickCount: 5
        }
        ValueAxis {
            id: axisY3
            min: 0
            max: paket3 + 5

        }
    }

    ChartView {
        id: chartView4
        x:350
//            y:0
        width: 350
        height: 200
        title: qsTr("Yükseklik (m)")
        theme: ChartView.ChartThemeDark
//            anchors.fill: parent
        legend.alignment: Qt.AlignTop
        animationOptions: ChartView.SeriesAnimations
        antialiasing: true


        Timer{
            id: timerId4
            interval: 1000
            repeat: true
            triggeredOnStart: true
            running: true

            onTriggered: {
                //console.log("calisiyor")
                test4 += 1
                chartView4.axisX()
                //console.log(test)
                series5.append(test4,paket4);
            }
        }

        LineSeries {
            id: series5
            axisX: axisX4
            axisY: axisY4


        }
        ValueAxis {
            id: axisX4
            min: 0
            max: test4+2
            tickCount: 5
        }
        ValueAxis {
            id: axisY4
            min: 0
            max: paket4 + 5

        }
    }
}
