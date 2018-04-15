#-------------------------------------------------
#
# Project created by QtCreator 2018-03-24T22:44:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH +=  Core/ \
                LoginWidget/ \
                MainWidget/ \
                Controller/ \
                mode


CONFIG(debug, debug|release) {
    DESTDIR = ../bin/Debug
    LIBS += -L../bin/Debug
} else {
    DESTDIR = ../bin/Release
    LIBS += -L../bin/Release
}

TARGET = app
TEMPLATE = app

CONFIG += c++11

HEADERS += \
    Core/BaseWidget.h \
    LoginWidget/LoginWidget.h \
    MainWidget/MainWidget.h \
    MainWidget/IndexWidget.h \
    MainWidget/BusinessWidgetItem.h \
    App.h \
    Controller/LoginController.h \
    Core/Controller.h \
    MainWidget/ProfileWidget.h \
    mode/User.h

SOURCES += \
    LoginWidget/LoginWidget.cpp \
    main.cpp \
    MainWidget/MainWidget.cpp \
    MainWidget/IndexWidget.cpp \
    App.cpp \
    MainWidget/ProfileWidget.cpp

FORMS += \
    LoginWidget/LoginWidget.ui \
    MainWidget/MainWidget.ui \
    MainWidget/IndexWidget.ui \
    MainWidget/BusinessWidgetItem.ui \
    MainWidget/ProfileWidget.ui

RESOURCES += \
    res.qrc

OTHER_FILES +=
