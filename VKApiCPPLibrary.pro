#-------------------------------------------------
#
# Project created by QtCreator 2016-07-30T22:27:13
#
#-------------------------------------------------

QT       -= core gui

TARGET = VKApiCPPLibrary
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

SOURCES += vkapicpplibrary.cpp \
    ivkobject.cpp \
    audio.cpp \
    account.cpp \
    vkobjectfactory.cpp \
    message.cpp \
    photo.cpp \
    video.cpp \
    user.cpp \
    attachments.cpp

HEADERS += vkapicpplibrary.h \
    ivkobject.h \
    audio.h \
    json.hpp \
    account.h \
    vkobjectfactory.h \
    Error.h \
    permissions.h \
    message.h \
    photo.h \
    video.h \
    user.h \
    attachments.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
