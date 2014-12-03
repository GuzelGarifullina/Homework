#-------------------------------------------------
#
# Project created by QtCreator 2014-12-03T21:37:14
#
#-------------------------------------------------

QT       -= gui

TARGET = list_Int
TEMPLATE = lib

DEFINES += LIST_INT_LIBRARY

SOURCES += list_int.C

HEADERS += list_int.h\
        list_int_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
