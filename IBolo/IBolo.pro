#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T18:27:45
#
#-------------------------------------------------

QT       -= gui

TARGET = IBolo
TEMPLATE = lib

DEFINES += IBOLO_LIBRARY

SOURCES += ibolo.cpp

HEADERS += ibolo.h\
        ibolo_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
