#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T02:37:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Infotainment
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    navigationdialog.cpp \
    carsettingsdialog.cpp

HEADERS  += mainwindow.h \
    navigationdialog.h \
    carsettingsdialog.h

FORMS    += mainwindow.ui \
    navigationdialog.ui \
    carsettingsdialog.ui

CONFIG += c++11

QT += webkitwidgets

DISTFILES += \
    xc60dash.jpg

RESOURCES += \
    infotainmentresources.qrc
