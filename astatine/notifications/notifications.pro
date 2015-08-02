TARGET = $$qtLibraryTarget(cutiens)
TEMPLATE = lib
CONFIG += plugin

HEADERS += $$[QT_INSTALL_HEADERS]/QtWebKit/qwebkitplatformplugin.h \
    notificationsplugin.h

SOURCES += \
    notificationsplugin.cpp

Release:DESTDIR     = $$PWD/../bin/release/webkit
Release:UI_DIR      = $${DESTDIR}/.ui
Release:MOC_DIR     = $${DESTDIR}/.moc
Release:RCC_DIR     = $${DESTDIR}/.rcc
Release:OBJECTS_DIR = $${DESTDIR}/.obj

Debug:DESTDIR       = $$PWD/bin/debug/webkit
Debug:UI_DIR        = $${DESTDIR}/.ui
Debug:MOC_DIR       = $${DESTDIR}/.moc
Debug:RCC_DIR       = $${DESTDIR}/.rcc
Debug:OBJECTS_DIR   = $${DESTDIR}/.obj

include($$PWD/notification/notification.pri)
