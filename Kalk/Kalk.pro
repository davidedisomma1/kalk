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
    Grafica/mainwindow.cpp \
    Grafica/inputpanelkalk.cpp \
    Grafica/mainkalk.cpp \
    Grafica/listmodel.cpp

HEADERS  += Logica/punto.h \
    Grafica/mainwindow.h \
    Grafica/inputpanelkalk.h \
    Grafica/mainkalk.h \
    Grafica/listmodel.h

FORMS    += Grafica/mainwindow.ui
