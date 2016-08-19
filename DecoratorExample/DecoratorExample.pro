#-------------------------------------------------
#
# Project created by QtCreator 2016-08-19T16:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DecoratorExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/release/ -lIBolo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/debug/ -lIBolo
else:unix: LIBS += -L$$PWD/../build-IBolo-Desktop-Debug/ -lIBolo

INCLUDEPATH += $$PWD/../build-IBolo-Desktop-Debug
DEPENDPATH += $$PWD/../build-IBolo-Desktop-Debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/release/ -lBoloDecorator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/debug/ -lBoloDecorator
else:unix: LIBS += -L$$PWD/../build-BoloDecorator-Desktop-Debug/ -lBoloDecorator

INCLUDEPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
DEPENDPATH += $$PWD/../build-BoloDecorator-Desktop-Debug
