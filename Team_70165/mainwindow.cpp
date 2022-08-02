#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QQmlContext>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QByteArray>
#include <QPixmap>
#include <QTimer>
#include <QGeoRoute>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QSslSocket>
#include <QLocale>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDir>

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace std;
using namespace cv;

bool isActive=false ;
char keyPress;
Mat frame;
VideoCapture cap;
QImage qt_image;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Team_70165");

    ui->comboBox_2->addItem("9600");
    ui->comboBox_2->addItem("115200");

    int num = QSerialPortInfo::availablePorts().length();
    for(int i =0 ; i<num; ++i ) {
        QSerialPortInfo baudRate;
        baudRate = QSerialPortInfo::availablePorts()[i];
        QString addCombo = baudRate.portName();
        ui->comboBox->addItem(addCombo);
    }
    //QSerialPortInfo::availablePorts().length();


    ui->charts_2 -> rootContext() -> setContextProperty("mainWidget", this);
    ui ->charts_2 ->setSource(QUrl(QStringLiteral("qrc:/Charts.qml")));

    ui->quickWidget -> rootContext() -> setContextProperty("mainWidget", this);
    ui ->quickWidget ->setSource(QUrl(QStringLiteral("qrc:/Charts3.qml")));

    ui->quickWidget_2 -> rootContext() -> setContextProperty("mainWidget", this);
    ui ->quickWidget_2 ->setSource(QUrl(QStringLiteral("qrc:/Charts2.qml")));

    ui->quickWidget_3 -> rootContext() -> setContextProperty("mainWidget", this);
    ui ->quickWidget_3 ->setSource(QUrl(QStringLiteral("qrc:/Listasama.qml")));

    ui->quickWidget_4 -> rootContext() -> setContextProperty("mainWidget", this);
    ui ->quickWidget_4 ->setSource(QUrl(QStringLiteral("qrc:/Ucboyutlu.qml")));

    QStringList title;
    ui -> tableWidget ->setColumnCount(18);
    title << "Takım No" << "Paket No"<< "Gönderme günü"<< "Saat"<< "Basınç"<< "Yükseklik" << "İniş Hızı" <<"Sıcaklık" << "Pil Gerilimi"
        << "GPS Latitude"<< "GPS Longtitude" << "GPS Altitude" << "Uydu Statüsü" << "Pitch" << "Roll" << "Yaw" << "Dönüş Sayısı"<< "Video Aktarım";
    ui->tableWidget-> setHorizontalHeaderLabels(title);
    ui->tableWidget->acceptDrops();

}

MainWindow::~MainWindow()
{
    if(arduino->isOpen()){
        arduino->close(); //    Close the serial port if it's open.
    }
    delete ui;
}

void MainWindow::readSerial()
{
    //QThread::sleep(50);
    //QTimer::
    QString xAngle;
    QString takimno;
    QString paketno;
    QString gun;

    QByteArray serialData = arduino->readAll();
    QStringList list = QString(serialData).split(",");

    if (list.size()>3 && list.size()<5) {
        xAngle = list[3];

        int fila;
        fila = ui->tableWidget->rowCount()-1;

        if(xAngle.endsWith("a") == true ) {
            takimno = list[0];
            paketno = list[1];
            gun = list[2];


            ui->tableWidget->setItem(fila  ,NAME,new QTableWidgetItem(takimno));
            ui->tableWidget->setItem(fila  , AGE, new QTableWidgetItem(
                                         QString(paketno)));
            ui->tableWidget->setItem(fila , SALARY,new QTableWidgetItem (
                                         QString(gun)));
        }
        else if(xAngle.endsWith("b") == true) {
            QString saat = list[0];
            QString basinc = list[1];
            QString yukseklik = list[2];
            double basinc1 = basinc.toDouble();
            double yukseklik1 = yukseklik.toDouble();

            emit datas(basinc1,yukseklik1);


            ui->tableWidget->setItem(fila  ,SAAT,new QTableWidgetItem(saat));
            ui->tableWidget->setItem(fila  , BASINC, new QTableWidgetItem(
                                         QString(basinc)));
            ui->tableWidget->setItem(fila , YUKSEKLIK,new QTableWidgetItem (
                                         QString(yukseklik)));

        }
        else if(xAngle.endsWith("c") == true) {
            QString inishizi = list[0];
            QString sicaklik = list[1];
            QString gerilim = list[2];

            double inishizi1 = inishizi.toDouble();
            double gerilim1 = gerilim.toDouble();
            double sicaklik1 = sicaklik.toDouble();

            emit graphs(inishizi1,gerilim1,sicaklik1);

            ui->tableWidget->setItem(fila  ,INISHIZI,new QTableWidgetItem(inishizi));
            ui->tableWidget->setItem(fila  , SICAKLIK, new QTableWidgetItem(
                                         QString(sicaklik)));
            ui->tableWidget->setItem(fila , GERILIM,new QTableWidgetItem (
                                         QString(gerilim)));
        }
        else if(xAngle.endsWith("d") == true) {
            QString latitude = list[0];
            QString longtitude = list[1];
            QString altitude = list[2];
            double latitude1 = latitude.toDouble();
            double longtitude1 = longtitude.toDouble();
            //double altitude1 = altitude.toDouble();

            emit gps (latitude1,longtitude1);

            ui->tableWidget->setItem(fila  ,LATITUDE,new QTableWidgetItem(latitude));
            ui->tableWidget->setItem(fila  , LONGTITUDE, new QTableWidgetItem(
                                         QString(longtitude)));
            ui->tableWidget->setItem(fila , ALTITUDE,new QTableWidgetItem (
                                         QString(altitude)));
        }
        else if(xAngle.endsWith("e") == true) {
            QString statu = list[0];
            QString xGyro = list[1];
            QString yGyro = list[2];

            int statu1 = statu.toInt();
            double xGyro1 = xGyro.toDouble();

            double yGyro1 = yGyro.toDouble();

            ui->tableWidget->setItem(fila  ,STATU,new QTableWidgetItem(statu));
            ui->tableWidget->setItem(fila , XGYRO, new QTableWidgetItem(
                                         QString(xGyro)));
            ui->tableWidget->setItem(fila , YGYRO,new QTableWidgetItem (
                                         QString(yGyro)));

            emit durum (statu1);
            emit xandy(xGyro1,yGyro1);
        }
        else if(xAngle.endsWith("f") == true) {
            QString zGyro = list[0];
            QString donus = list[1];
            QString video = list[2];
            double zGyro1 = zGyro.toDouble();
            int video1 = video.toInt();
            ui->tableWidget ->insertRow(ui->tableWidget->rowCount());
            if(video1 == 0) {
               ui->checkBox->setChecked(false);
            }
            else if (video1 == 1 ) {
                ui->checkBox->setChecked(true);
            }


            ui->tableWidget->setItem(fila  ,ZGYRO,new QTableWidgetItem(zGyro));
            ui->tableWidget->setItem(fila  , DONUS, new QTableWidgetItem(
                                         QString(donus)));
            ui->tableWidget->setItem(fila , VIDEO,new QTableWidgetItem (
                                         QString(video)));

            emit onlyz(zGyro1);

        }
    }
}

void MainWindow::on_pushButton_clicked()
{

    //isActive = !ui->pushButton->isChecked();
    QTimer *timer = new QTimer(this);
    if(isActive == false) {
        cap.open(0);

        if(!cap.isOpened()) {
            cout << "camera is not open" << endl;
        }
        else {
            cout << "camera is open" << endl;

            connect(timer, SIGNAL(timeout()),this, SLOT(update_window()));
            timer->start(20);
            isActive = true;
            ui->pushButton->setText("Close Camera");
        }
    }
    else {

        ui->pushButton->setText("Open Camera");






        //Mat image = Mat::zeros(frame.size(),CV_8UC3);


        //qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);


        //ui->label_pic->setPixmap(QPixmap::fromImage(qt_image));

        //ui->label_pic->resize(ui->label_pic->pixmap()->size());



        cout << "camera is closed" << endl;
        isActive = false;
        disconnect(timer, SIGNAL(timeout()), this, SLOT(update_window()));
        cap.release();


    }
}

void MainWindow::update_window(){

    //cout << "update" << endl;

    cap >> frame;

    cvtColor(frame, frame, COLOR_BGR2RGB); // bgr ı rgb ye çevirme
    Mat image;
    cv::resize(frame,image,cv::Size(500,300));


    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    //qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);


    ui->label_pic->setPixmap(QPixmap::fromImage(qt_image));
    ui->label_pic->resize(ui->label_pic->pixmap()->size());

}


void MainWindow::on_buttonBox_accepted()
{
    int num = QSerialPortInfo::availablePorts().length();
    qDebug() << "ports number : " << num;
    if(num != 0) {
        int vendorId =0, productId = 0;
        QString portName;
        QSerialPortInfo portInfo = QSerialPortInfo::availablePorts()[0];
        if(portInfo.hasVendorIdentifier()) {
            vendorId = portInfo.vendorIdentifier();
            qDebug() << "vendor id : " << vendorId;
        }
        if(portInfo.hasProductIdentifier()){
            productId = portInfo.productIdentifier();
            qDebug() << "product id : " << productId;
        }
        portName = ui->comboBox ->currentText();
        if((vendorId != 0) && (productId != 0))          
//      portName = portInfo.portName();
        qDebug() << "port name : " << portName;
        QString baudRate1;
        baudRate1 = ui->comboBox_2->currentText();
        int choose = baudRate1.toInt();

//        quint32 baudRate;
//        baudRate = ;

        arduino = new QSerialPort(this);
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(portName);
        arduino->open(QSerialPort::ReadWrite);
        if (choose == 9600) {
            arduino->setBaudRate(QSerialPort::Baud9600);
        }
        else if(choose == 115200) {
            arduino->setBaudRate(QSerialPort::Baud115200);
        }
        else {
            qDebug() << "sorry bro there is nothing to say";
        }
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }
    else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }
}


void MainWindow::on_buttonBox_rejected()
{
    auto filename = QFileDialog::getSaveFileName(this,
                  "Guardar",QDir::rootPath(),"CSV File (*.csv)");
    if(filename.isEmpty()) {
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream xout(&file);
    const int rowCount = ui->tableWidget->rowCount();
    const int colCount = ui->tableWidget->columnCount();
    for(int ix = 0; ix<rowCount; ++ix) {
        xout << getValueAt(ix,0);
        for(int jx = 1;jx<colCount;++jx) {
            xout << "," << getValueAt(ix,jx);
        }
        xout<<"\n";
    }
    file.flush();
    file.close();
    window()->close();
}


void MainWindow::on_pushButton_5_clicked()
{
    QString string = "1";
    if(arduino && arduino->isWritable()){

            arduino->write(string.toLatin1());
    }
    else {
        qDebug() << "sorry reis gönderemedim...";
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString string1 = "500";
    if(arduino && arduino->isWritable()){
        for(int i=0; i<50;++i)
        arduino->write(string1.toLatin1());
    }
    else {
        qDebug() << "sorry reis gönderemedim...";
    }

}

QString MainWindow::getValueAt(int ix, int jx)
{
    if(!ui->tableWidget->item(ix,jx)) {
        return "";
    }
    return ui->tableWidget->item(ix,jx)->text();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Gözat",QDir::rootPath() , "MP4 File (*.mp4)");
    ui->label_3->setText(file_name);
}

