#-------------------------------------------------
#
# Project created by QtCreator 2015-06-08T15:32:38
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProCal
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
    core/evenement.cpp \
    ui/mainwindow.cpp \
    core/programmation.cpp \
    core/projet.cpp \
    core/tache.cpp

HEADERS  += \
    ui/headers/mainwindow.h \
    core/headers/evenement.h \
    core/headers/programmation.h \
    core/headers/projet.h \
    core/headers/tache.h

FORMS    += \
    ui/mainwindow.ui
