# ybatterymonitor.pro

TEMPLATE = app
TARGET = ybatterymonitor
INCLUDEPATH += .

# Input
HEADERS += BatteryMonitor.h main.h
SOURCES += BatteryMonitor.cpp main.cpp

QT += widgets
CONFIG += link_pkgconfig
PKGCONFIG += sdl2
