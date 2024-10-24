QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += /usr/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../auxilary/matrix/matrix.cc \
    ../../../brick_game/BrickGame.cc \
    ../../../brick_game/snake/Snake.cc \
#    ../../../brick_game/tetris/tetris.c \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../../auxilary/matrix/matrix.h \
    ../../../brick_game/BrickData.h \
    ../../../brick_game/BrickGame.h \
    ../../../brick_game/snake/Snake.h \
#    ../../../brick_game/tetris/tetris.h \
    gamescene.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../resources/img.qrc
