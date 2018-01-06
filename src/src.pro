CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14
CONFIG += staticlib

TARGET   = pathfinder
TEMPLATE = lib

QMAKE_CXXFLAGS += -Wall

macx {
    QMAKE_CXXFLAGS += -stdlib=libc++
}

SOURCES += \
           pathfinder.cpp \
           point2d.cpp \
    readfile.cpp \
    node.cpp \
    workonfile.cpp

HEADERS += \
           pathfinder.h \
           point2d.h \
    readfile.h \
    node.h \
    workonfile.h
