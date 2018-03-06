TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    menu.cpp \
    card_service.cpp \
    card_file.cpp \
    tool.c

HEADERS += \
    menu.h \
    main.h \
    card_service.h \
    card_file.h \
    model.h \
    global.h
