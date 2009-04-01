# -------------------------------------------------
# Project created by QtCreator 2009-03-31T00:51:17
# -------------------------------------------------
TARGET = RatingWidgetPlugin
TEMPLATE = lib
CONFIG += designer \
    plugin \
    debug
DEFINES += RATINGWIDGETPLUGIN_LIBRARY
SOURCES += RatingWidget.cpp \
    ratingwidgetplugin.cpp
HEADERS += RatingWidgetPlugin_global.h \
    RatingWidget.h \
    ratingwidgetplugin.h
target.path = /home/jokerwww/.kde4/lib/kde4/plugins/designer
INSTALLS += target
RESOURCES += icons.qrc
