#-------------------------------------------------
#
# Project created by QtCreator 2016-09-15T21:33:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZellerGUI
TEMPLATE = app


SOURCES += main.cpp\
        zellergui.cpp \
    ../src/gregorian.c \
    ../util/getdate.c

HEADERS  += zellergui.h \
    ../src/gregorian.h \
    ../util/getdate.h

FORMS    += zellergui.ui

RESOURCES += \
    icons/icons.qrc \
    translations/hun.qrc

TRANSLATIONS += hun.ts
