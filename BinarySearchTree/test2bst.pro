TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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

