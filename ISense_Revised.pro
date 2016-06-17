#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T22:18:00
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ISense_Revised
TEMPLATE = app


SOURCES += main.cpp\
    controller.cpp \
    iSense.cpp \
    connectioncontroller.cpp \
    mainmodel.cpp

HEADERS  += \
    controller.h \
    commons.h \
    iSense.h \
    connectioncontroller.h \
    mainmodel.h

FORMS    += \
    iSense.ui

RESOURCES += \
    icons.qrc \
    images.qrc
