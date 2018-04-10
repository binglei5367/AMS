TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    menu.cpp \
    card_service.cpp \
    card_file.cpp \
    tool.cpp

HEADERS += \
    menu.h \
    main.h \
    card_service.h \
    card_file.h \
    model.h \
    global.h \
    tool.h
