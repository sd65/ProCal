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
    core/tache.cpp \
    ui/ajouteractivite.cpp \
    ui/ajouterprojet.cpp \
    ui/mainwindowprojet.cpp \
    ui/ajouterTacheUnitaire.cpp

HEADERS  += \
    ui/headers/mainwindow.h \
    core/headers/evenement.h \
    core/headers/programmation.h \
    core/headers/projet.h \
    core/headers/tache.h \
    ui/headers/ajouteractivite.h \
    ui/headers/ajouterprojet.h \
    ui/headers/mainwindowprojet.h \
    ui/headers/ajouterTacheUnitaire.h

FORMS    += \
    ui/mainwindow.ui \
    ui/ajouteractivite.ui \
    ui/ajouterprojet.ui \
    ui/mainwindowprojet.ui \
    ui/ajouterTacheUnitaire.ui

RESOURCES += \
    ui/icons/iconsressourcefile.qrc

DISTFILES +=
