
TEMPLATE = app
TARGET = labo_toboggan
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += debug

MOC_DIR = moc
OBJECTS_DIR = obj

QT += testlib gui widgets

# Input
HEADERS += \
    src/display.h \
    src/mainwindow.h \
    src/pslideinterface.h \
    src/kid.h \
    src/toboganmanager.h
SOURCES += \
    src/display.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/pslideinterface.cpp \
    src/kid.cpp \
    src/toboganmanager.cpp
RESOURCES += toboggan.qrc
