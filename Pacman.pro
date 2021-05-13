QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blueghost.cpp \
    choosewindow.cpp \
    client.cpp \
    closewindow.cpp \
    gamedrawer.cpp \
    ghost.cpp \
    main.cpp \
    gamemanager.cpp \
    maingamemanager.cpp \
    map.cpp \
    multiplayergamemanager.cpp \
    networkconnection.cpp \
    orangeghost.cpp \
    pacman.cpp \
    pinkghost.cpp \
    player.cpp \
    redghost.cpp \
    secondgamemanager.cpp

HEADERS += \
    blueghost.h \
    choosewindow.h \
    client.h \
    closewindow.h \
    gamedrawer.h \
    gamemanager.h \
    ghost.h \
    maingamemanager.h \
    map.h \
    multiplayergamemanager.h \
    networkconnection.h \
    orangeghost.h \
    pacman.h \
    pinkghost.h \
    player.h \
    redghost.h \
    secondgamemanager.h

FORMS += \
    choosewindow.ui \
    closewindow.ui \
    gamemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

LIBS += -lws2_32
