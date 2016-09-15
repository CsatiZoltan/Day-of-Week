TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/gregorian.c \
    src/main.c \
    util/getDate.c

HEADERS += \
    util/getDate.h \
    src/gregorian.h

