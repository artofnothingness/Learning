TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

CONFIG += link_pkgconfig
PKGCONFIG += opencv

CONFIG -= qt

SOURCES += main.cpp
