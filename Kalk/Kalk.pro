#-------------------------------------------------
#
# Project created by QtCreator 2018-03-02T09:56:06
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
TEMPLATE = app


SOURCES += main.cpp\
    Logica/punto.cpp \
    Grafica/mainwindow.cpp

HEADERS  += Logica/punto.h \
    Grafica/mainwindow.h

FORMS    += Grafica/mainwindow.ui
