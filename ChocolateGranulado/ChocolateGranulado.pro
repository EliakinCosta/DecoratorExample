#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T18:44:21
#
#-------------------------------------------------

QT       -= gui

TARGET = ChocolateGranulado
TEMPLATE = lib
CONFIG += plugin
DESTDIR = ../plugins
DEFINES += CHOCOLATEGRANULADO_LIBRARY

SOURCES += chocolategranulado.cpp

HEADERS += chocolategranulado.h\
        chocolategranulado_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/release/ -lBoloDecorator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/debug/ -lBoloDecorator
else:unix: LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/ -lBoloDecorator

INCLUDEPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
DEPENDPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
