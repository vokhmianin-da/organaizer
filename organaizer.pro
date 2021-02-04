TEMPLATE = app

QT += qml quick sql gui core
CONFIG += c++11

SOURCES += main.cpp \
    tasklist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    tasklist.h
