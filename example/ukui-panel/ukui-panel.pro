QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ukuipanel_debug.cpp

HEADERS += \
    mainwindow.h \
    ukuipanel_debug.h

FORMS += \
    mainwindow.ui

INSTALLS += target
