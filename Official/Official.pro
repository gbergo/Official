TEMPLATE = app
TARGET = Official
INCLUDEPATH += .
CONFIG += c++11
QT += widgets

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#Input
SOURCES += main.cpp \
    matricekalk.cpp \
    matrice_input.cpp \
    tastiera.cpp

HEADERS += \
    matricekalk.h \
    matrice_input.h \
    tastiera.h

FORMS += \
    mainwindow.ui
