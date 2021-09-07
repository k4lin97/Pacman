QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Ghosts/ghost.cpp \
    Ghosts/blueghost.cpp \
    Ghosts/orangeghost.cpp \
    Ghosts/pinkghost.cpp \
    Ghosts/redghost.cpp \
    Player/player.cpp \
    Player/pacman.cpp \
    SinglePlayer/gamemanager.cpp \
    SinglePlayer/map.cpp \
    SinglePlayer/closewindow.cpp \
    MainMenu/choosewindow.cpp \
    Drawing/gamedrawer.cpp \
    main.cpp \
    MultiPlayer/maingameclient.cpp \
    MultiPlayer/maingamemanager.cpp \
    MultiPlayer/multiplayergamemanager.cpp \
    MultiPlayer/networkconnection.cpp \
    MultiPlayer/secondgameclient.cpp \
    MultiPlayer/secondgamemanager.cpp

HEADERS += \
    Ghosts/blueghost.h \
    Ghosts/ghost.h \
    Ghosts/orangeghost.h \
    Ghosts/pinkghost.h \
    Ghosts/redghost.h \
    Player/player.h \
    Player/pacman.h \
    SinglePlayer/gamemanager.h \
    SinglePlayer/map.h \
    SinglePlayer/closewindow.h \
    MainMenu/choosewindow.h \
    Drawing/gamedrawer.h \
    MultiPlayer/maingameclient.h \
    MultiPlayer/maingamemanager.h \
    MultiPlayer/multiplayergamemanager.h \
    MultiPlayer/networkconnection.h \
    MultiPlayer/secondgameclient.h \
    MultiPlayer/secondgamemanager.h

FORMS += \
    Forms/choosewindow.ui \
    Forms/closewindow.ui \
    Forms/gamemanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

LIBS += -lws2_32
