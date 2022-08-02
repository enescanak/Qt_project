#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QSslSocket>

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void readSerial();
    void update_window();
    void on_pushButton_clicked();

signals:
    void info_camera(QImage qimgOriginal);
    void datas(double basinc, double yukseklik);
    void graphs(double inishizi, double gerilim, double sicaklik);
    void gps(double latitude, double longtitude);
    void durum(int hal);
    void xandy (double xAci, double yAci);
    void onlyz (double zAci);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino = nullptr;
    QString getValueAt(int ix , int jx);
    enum Columna {
        NAME,AGE,SALARY,SAAT,BASINC,YUKSEKLIK,INISHIZI,SICAKLIK,GERILIM,LATITUDE,LONGTITUDE,ALTITUDE,STATU,XGYRO,YGYRO,ZGYRO,DONUS,VIDEO
    };
};
#endif // MAINWINDOW_H
