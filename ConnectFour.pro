#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T15:09:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConnectFour
TEMPLATE = app


SOURCES += main.cpp\
    coin.cpp \
    mygraphicsview.cpp \
    mygraphicsscene.cpp

HEADERS  += \
    coin.h \
    mygraphicsview.h \
    mygraphicsscene.h

FORMS    +=

RESOURCES += \
    coins.qrc

CONFIG+= static
