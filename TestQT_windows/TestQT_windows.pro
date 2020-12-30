#-------------------------------------------------
#
# Project created by QtCreator 2020-06-30T18:49:40
#
#-------------------------------------------------
QT += serialport
QT       += core gui
QT += webkit

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = TestQT_windows
TEMPLATE = app





CONFIG += no_keywords # Python redefines some qt keywords
INCLUDEPATH += /usr/include/python3.5m
LIBS += -lpython3.5m






SOURCES += main.cpp\
        mainwindow.cpp \
    avto.cpp \
    msg.cpp \
    avtoquatro.cpp \
    mathmodel.cpp \
    mathmodel_quatro.cpp \
    user.cpp \
    tpoint.cpp

HEADERS  += mainwindow.h \
    avto.h \
    msg.h \
    usb.h \
    avtoquatro.h \
    mathmodel.h \
    mathmodel_quatro.h \
    user.h \
    tpoint.h

FORMS    += mainwindow.ui

DISTFILES += \
    test1.py
