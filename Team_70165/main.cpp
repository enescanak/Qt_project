#include "mainwindow.h"

#include <QApplication>
#include <QGeoRoute>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QSslSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWidget;
    mainWidget.show();
    return a.exec();
}
