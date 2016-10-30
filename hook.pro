#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T15:16:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hook
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    inputhook.cpp \
    inputevent.cpp

HEADERS  += dialog.h \
    inputhook.h \
    inputevent.h

FORMS    += dialog.ui
