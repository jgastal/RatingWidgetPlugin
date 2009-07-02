# -------------------------------------------------
# Project created by QtCreator 2009-03-31T00:51:17
# -------------------------------------------------
TARGET = RatingWidgetPlugin
TEMPLATE = lib
CONFIG += designer \
    plugin \
    release
DEFINES += RATINGWIDGETPLUGIN_LIBRARY
SOURCES += RatingWidget.cpp \
    ratingwidgetplugin.cpp
HEADERS += RatingWidgetPlugin_global.h \
    RatingWidget.h \
    ratingwidgetplugin.h
target.path = $$[INSTALL_PREFIX]/$$[QT_INSTALL_PLUGINS]/designer
headers.path = $$[INSTALL_PREFIX]/usr/include/
headers.files = $$HEADERS
INSTALLS += target headers
RESOURCES += icons.qrc
