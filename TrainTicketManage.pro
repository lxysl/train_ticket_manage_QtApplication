#-------------------------------------------------
#
# Project created by QtCreator 2019-07-02T15:49:43
#
#-------------------------------------------------

QT       += core gui sql
RC_FILE = logo.rc


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrainTicketManage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    form.cpp \
    subwindow.cpp \
    triwindow.cpp \
    confirmrefund.cpp

HEADERS += \
    form.h \
    subwindow.h \
    triwindow.h \
    confirmrefund.h \
    journey.h \
    passenger.h

FORMS += \
    form.ui \
    subwindow.ui \
    triwindow.ui \
    confirmrefund.ui
