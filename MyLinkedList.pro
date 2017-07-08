TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    llist.c

HEADERS += \
    llist.h

QMAKE_CFLAGS += -std=c11
