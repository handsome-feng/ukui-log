QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    ukuimenu_debug.cpp

HEADERS += \
    log.h \
    mainwindow.h \
    ukuimenu_debug.h

FORMS += \
    mainwindow.ui

INSTALLS += target
