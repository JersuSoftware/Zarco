#-------------------------------------------------
#
# Project created by QtCreator 2015-10-27T17:31:20
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Grafos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    graph.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
