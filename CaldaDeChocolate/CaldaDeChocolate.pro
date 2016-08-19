#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T18:43:54
#
#-------------------------------------------------

QT       -= gui

TARGET = CaldaDeChocolate
TEMPLATE = lib
CONFIG += plugin
DESTDIR = ../plugins
DEFINES += CALDADECHOCOLATE_LIBRARY

SOURCES += caldadechocolate.cpp

HEADERS += caldadechocolate.h\
        caldadechocolate_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/release/ -lBoloDecorator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/debug/ -lBoloDecorator
else:unix: LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/ -lBoloDecorator

INCLUDEPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
DEPENDPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
