#-------------------------------------------------
#
# Project created by QtCreator 2016-08-21T16:32:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZellerGUI
TEMPLATE = app


SOURCES += main.cpp\
        zellergui.cpp \
    ../src/gregorian.c

HEADERS  += zellergui.h \
    ../src/gregorian.h

FORMS    += zellergui.ui
