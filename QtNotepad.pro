#-------------------------------------------------
#
# Project created by QtCreator 2023-01-13T09:56:17
#
#-------------------------------------------------

QT       += core gui printsupport   # allows qprint and  qprint dialog class
#for use the print we have to add print support to the  project file .pro
#include "C:\Windows\explorer.exe"


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtNotepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
