QT += core gui
QT += widgets
QT += svg
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += rtti

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../DialogWindows/create.cpp \
    ../libfly/felement.cpp \
    ../libfly/finstrument.cpp \
    ../libfly/fkey.cpp \
    ../libfly/flines.cpp \
    ../libfly/fnotes.cpp \
    ../libfly/fpause.cpp \
    ../libfly/ftakt.cpp \
    ../libfly/fvirtualnotepaper.cpp \
    main.cpp \
    mainwindow.cpp \
    muswidgets.cpp \
    viewpaper.cpp

HEADERS += \
    ../DialogWindows/create.h \
    ../libfly/felement.h \
    ../libfly/finstrument.h \
    ../libfly/fkey.h \
    ../libfly/flines.h \
    ../libfly/fnotes.h \
    ../libfly/fpause.h \
    ../libfly/ftakt.h \
    ../libfly/fvirtualnotepaper.h \
    mainwindow.h \
    muswidgets.h \
    viewpaper.h

FORMS += \
    ../DialogWindows/create.ui \
    mainwindow.ui \
    muswidgets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
