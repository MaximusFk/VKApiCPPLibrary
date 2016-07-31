#-------------------------------------------------
#
# Project created by QtCreator 2016-07-30T22:27:13
#
#-------------------------------------------------

QT       -= core gui

TARGET = VKApiCPPLibrary
TEMPLATE = lib
CONFIG += staticlib

SOURCES += vkapicpplibrary.cpp

HEADERS += vkapicpplibrary.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
