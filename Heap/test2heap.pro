TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    hnode.h \
    heap.h \
    horchard.h \
    tnode.h \
    parser.h

SOURCES += \
    horchard.cpp \
    main.cpp \
    parser.cpp \
    heap.cpp
