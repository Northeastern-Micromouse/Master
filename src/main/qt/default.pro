TEMPLATE = app
TARGET = micromouse

QT = core gui

SOURCES +=  main.cpp \
    window.cpp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    window.h