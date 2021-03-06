######################################################################
# Automatically generated by qmake (2.01a) ?? 10? 14 18:13:15 2016
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . hwlib
INCLUDEPATH += . hwlib


QT += sql
#LIBS += -L./hwlib -ldev
#LIBS += -L./hwlib -lat

LIBS += -L./hwlib -lfgs

# Input
HEADERS += camera.h \
           camera_thread.h \
           canread.h \
           common.h \
           mylib.h \
           qmplayer.h \
           signalcan.h \
           telephone.h \
           timesetup.h \
           timesetuptrue.h \
           ui_findlook.h \
           videodevice.h \
           widget.h \
           work.h \
           hwlib/libat.h \
           hwlib/libdev.h
FORMS += telephone.ui timesetup.ui timesetuptrue.ui widget.ui work.ui
SOURCES += camera.cpp \
           camera_thread.cpp \
           canread.cpp \
           main.cpp \
           qmplayer.cpp \
           signalcan.cpp \
           telephone.cpp \
           timesetup.cpp \
           timesetuptrue.cpp \
           videodevice.cpp \
           widget.cpp \
           work.cpp
RESOURCES += imagejy.qrc
