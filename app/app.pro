include(../defaults.pri)

CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle
CONFIG += qt

TEMPLATE = app

SOURCES += main.cpp

win32 {
CONFIG(debug):LIBS += -L../src/debug -lpathfinder
CONFIG(!debug):LIBS += -L../src/release -lpathfinder
}
macx {
CONFIG(debug):LIBS += -L../src -lpathfinder
CONFIG(!debug):LIBS += -L../src -lpathfinder
}
