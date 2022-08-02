import QtQuick 2.0
import QtQuick.Controls 2.5
import QtCharts 2.0
import QtQml 2.0

Item {
    width: 1050
    height: 200
    visible: true
    property int paket: 0
    property int paket1: 0
    property int paket2: 0

    property int test: 0
    property int test1: 0
    property int test2: 0



    Connections{
        target: mainWidget
        onGraphs:{
           // label1.text = basinc
            paket = inishizi
            paket1 = gerilim
            paket2 = sicaklik
            //console.log(paket)
        }
    }

//    Label {
//        id: label1
//        text: "null"

//    }

        ChartView {
            id: chartView
            x: 0
//            y:0
            width: 350
            height: 200
            title: qsTr("İniş Hızı (m/s)")
            theme: ChartView.ChartThemeDark

//            anchors.fill: parent
            legend.alignment: Qt.AlignTop
            animationOptions: ChartView.SeriesAnimations
            antialiasing: true


            Timer{
                id: timerId
                interval: 1000
                repeat: true
                triggeredOnStart: true
                running: true

                onTriggered: {
                    //console.log("calisiyor")
                    test += 1
                    chartView.axisX()
                    //console.log(test)
                    series1.append(test,paket);
                }
            }

            LineSeries {
                id: series1
                axisX: axisX
                axisY: axisY


            }
            ValueAxis {
                id: axisX
                min: 0
                max: test+2
                tickCount: 5
            }
            ValueAxis {
                id: axisY
                min: 0
                max: paket + 5

            }
        }

        ChartView {
            id: chartView1
            x:350
//            y:0
            width: 350
            height: 200
            title: qsTr("Gerilim (V)")
            theme: ChartView.ChartThemeDark
//            anchors.fill: parent
            legend.alignment: Qt.AlignTop
            animationOptions: ChartView.SeriesAnimations
            antialiasing: true


            Timer{
                id: timerId1
                interval: 1000
                repeat: true
                triggeredOnStart: true
                running: true

                onTriggered: {
                    //console.log("calisiyor")
                    test1 += 1
                    chartView1.axisX()
                    //console.log(test)
                    series2.append(test1,paket1);
                }
            }

            LineSeries {
                id: series2
                axisX: axisX1
                axisY: axisY1


            }
            ValueAxis {
                id: axisX1
                min: 0
                max: test1+2
                tickCount: 5
            }
            ValueAxis {
                id: axisY1
                min: 0
                max: paket1 + 5

            }
        }
        ChartView {
            id: chartView2
            x:700
//            y:0
            width: 350
            height: 200
            title: qsTr("Sıcaklık (°C)")
            theme: ChartView.ChartThemeDark
//            anchors.fill: parent
            legend.alignment: Qt.AlignTop
            animationOptions: ChartView.SeriesAnimations
            antialiasing: true


            Timer{
                id: timerId2
                interval: 1000
                repeat: true
                triggeredOnStart: true
                running: true

                onTriggered: {
                    //console.log("calisiyor")
                    test2 += 1
                    chartView2.axisX()
                    //console.log(test)
                    series3.append(test2,paket2);
                }
            }

            LineSeries {
                id: series3
                axisX: axisX2
                axisY: axisY2


            }
            ValueAxis {
                id: axisX2
                min: 0
                max: test2+2
                tickCount: 5
            }
            ValueAxis {
                id: axisY2
                min: 0
                max: paket2 + 5

            }
        }
    }



