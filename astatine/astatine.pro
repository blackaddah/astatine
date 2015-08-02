#-------------------------------------------------
#
# Project created by QtCreator 2015-07-19T19:55:33
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = astatine
TEMPLATE = app

SOURCES += main.cpp\
        astatine.cpp \
    settings.cpp \
    systray/systray.cpp \
    webview/awebpage.cpp \
    webview/awebview.cpp

HEADERS  += astatine.h \
    settings.h \
    systray/systray.h \
    webview/awebpage.h \
    webview/awebview.h

FORMS    += astatine.ui \
    settings.ui

RESOURCES += \
    astatine.qrc

RC_ICONS = res/astatine.ico

Release:DESTDIR     = $$PWD/bin/release
Release:UI_DIR      = $${DESTDIR}/.ui
Release:MOC_DIR     = $${DESTDIR}/.moc
Release:RCC_DIR     = $${DESTDIR}/.rcc
Release:OBJECTS_DIR = $${DESTDIR}/.obj

Debug:DESTDIR       = $$PWD/bin/debug
Debug:UI_DIR        = $${DESTDIR}/.ui
Debug:MOC_DIR       = $${DESTDIR}/.moc
Debug:RCC_DIR       = $${DESTDIR}/.rcc
Debug:OBJECTS_DIR   = $${DESTDIR}/.obj
