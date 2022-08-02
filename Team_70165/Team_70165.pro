TARGET = qml_location_Charts2
TEMPLATE = app

QT       += core gui
QT       += core gui serialport
QT       += core gui quickwidgets
QT += qml network quick positioning location

OPENSSL_FOUND
OPENSSL_INCLUDE_DIR


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
INCLUDEPATH += /usr/local/include/opencv4

LIBS += `pkg-config --cflags --libs opencv4`

#LIBS += C:\opencv-build\bin\libopencv_core401.dll
#LIBS += C:\opencv-build\bin\libopencv_highgui401.dll
#LIBS += C:\opencv-build\bin\libopencv_imgcodecs401.dll
#LIBS += C:\opencv-build\bin\libopencv_imgproc401.dll
#LIBS += C:\opencv-build\bin\libopencv_calib3d401.dll
#LIBS += C:\opencv-build\bin\libopencv_core401.dll
#LIBS += C:\opencv-build\bin\libopencv_highgui401.dll
#LIBS += C:\opencv-build\bin\libopencv_imgcodecs401.dll
#LIBS += C:\opencv-build\bin\libopencv_imgproc401.dll
#LIBS += C:\opencv-build\bin\libopencv_features2d401.dll
#LIBS += C:\opencv-build\bin\libopencv_video401.dll
#LIBS += C:\opencv-build\bin\libopencv_videoio401.dll
#LIBS += C:\opencv-build\bin\libopencv_dnn401.dll
#LIBS += C:\opencv-build\bin\libopencv_flann401.dll
#LIBS += C:\opencv-build\bin\libopencv_gapi401.dll
#LIBS += C:\opencv-build\bin\libopencv_ml401.dll
#LIBS += C:\opencv-build\bin\libopencv_objdetect401.dll
#LIBS += C:\opencv-build\bin\libopencv_photo401.dll
#LIBS += C:\opencv-build\bin\libopencv_stitching401.dll


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
