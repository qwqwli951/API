#-------------------------------------------------
#
# Project created by QtCreator 2012-12-14T12:42:31
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = API
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    images.qrc
