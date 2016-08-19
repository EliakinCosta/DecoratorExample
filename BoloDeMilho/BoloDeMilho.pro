#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T18:32:21
#
#-------------------------------------------------

QT       -= gui

TARGET = BoloDeMilho
TEMPLATE = lib

DEFINES += BOLODEMILHO_LIBRARY

SOURCES += bolodemilho.cpp

HEADERS += bolodemilho.h\
        bolodemilho_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/release/ -lIBolo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/debug/ -lIBolo
else:unix: LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/ -lIBolo

INCLUDEPATH += $$PWD/../build-IBolo-Desktop-Debug
DEPENDPATH += $$PWD/../build-IBolo-Desktop-Debug
