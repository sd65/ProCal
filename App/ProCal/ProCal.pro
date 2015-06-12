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
    core/programmation.cpp \
    core/projet.cpp \
    core/tache.cpp \
    ui/ajouterTacheUnitaire.cpp \
    ui/ajouterTacheComposite.cpp \
    ui/ajouterActivite.cpp \
    ui/ajouterProjet.cpp \
    ui/mainWindow.cpp \
    ui/mainWindowProjet.cpp \
    ui/programmerUneTache.cpp \
    ui/uiHelpers.cpp

HEADERS  += \
    core/headers/evenement.h \
    core/headers/programmation.h \
    core/headers/projet.h \
    core/headers/tache.h \
    ui/headers/ajouterTacheUnitaire.h \
    ui/headers/ajouterTacheComposite.h \
    ui/headers/ajouterActivite.h \
    ui/headers/ajouterProjet.h \
    ui/headers/mainWindow.h \
    ui/headers/mainWindowProjet.h \
    ui/headers/programmerUneTache.h \
    ui/headers/uiHelpers.h

FORMS    += \
    ui/ajouterTacheUnitaire.ui \
    ui/ajouterTacheComposite.ui \
    ui/ajouterActivite.ui \
    ui/ajouterProjet.ui \
    ui/mainWindow.ui \
    ui/mainWindowProjet.ui \
    ui/programmerUneTache.ui

RESOURCES += \
    ui/icons/iconsressourcefile.qrc

ICON = ui/icon/icon.icns
