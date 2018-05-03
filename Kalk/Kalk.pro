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
    Grafica/mainkalk.cpp \
    Grafica/listmodel.cpp\
    Logica/tag.cpp \
    Logica/linea.cpp \
    Grafica/inputpunto.cpp

HEADERS  += Logica/punto.h \
    Grafica/mainwindow.h \
    Grafica/mainkalk.h \
    Grafica/listmodel.h \
    Logica/tag.h \
    Logica/linea.h \
    Grafica/inputpunto.h

FORMS    += Grafica/mainwindow.ui
