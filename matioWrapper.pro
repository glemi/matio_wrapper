#-------------------------------------------------
#
# Project created by QtCreator 2013-10-06T16:26:16
#
#-------------------------------------------------

QT       -= gui

TARGET = matioWrapper
TEMPLATE = lib

DEFINES += MATIOWRAPPER_LIBRARY

SOURCES += matiowrapper.cpp \
    matfile.cpp \
    matvar.cpp

HEADERS += matiowrapper.h\
        matiowrapper_global.h \
    matfile.h \
    matvar.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../matio-1.5.2/src/.libs/release/ -lmatio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../matio-1.5.2/src/.libs/debug/ -lmatio
else:unix: LIBS += -L$$PWD/../matio-1.5.2/src/.libs/ -lmatio

INCLUDEPATH += $$PWD/../matio-1.5.2/src
DEPENDPATH += $$PWD/../matio-1.5.2/src

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../matio-1.5.2/src/.libs/release/matio.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../matio-1.5.2/src/.libs/debug/matio.lib
else:unix: PRE_TARGETDEPS += $$PWD/../matio-1.5.2/src/.libs/libmatio.a
