TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3

SOURCES += main.cpp \
    bst.cpp \
    parser.cpp \
    torchard.cpp \
    tnode.cpp

HEADERS += \
    tnode.h \
    bst.h \
    torchard.h \
    parser.h
