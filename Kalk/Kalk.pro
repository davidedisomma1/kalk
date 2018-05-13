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
    Grafica/listmodel.cpp\
    Logica/tag.cpp \
    Logica/linea.cpp \
    Grafica/inputpunto.cpp \
    Logica/spezzata.cpp \
    Grafica/dialog.cpp \
    Logica/rettangolo.cpp

HEADERS  += Logica/punto.h \
    Grafica/listmodel.h \
    Logica/tag.h \
    Logica/linea.h \
    Grafica/inputpunto.h \
    Logica/spezzata.h \
    Grafica/dialog.h \
    Logica/rettangolo.h

FORMS    += Grafica/mainwindow.ui
