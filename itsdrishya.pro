
QT       += core gui
QT       += widgets sql charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analysiswindow.cpp \
    budgetwindow.cpp \
    homewindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    monthlywindow.cpp \
    revwindow.cpp \
    signwindow.cpp \
    weeklywindow.cpp \
    welwindow.cpp

HEADERS += \
    analysiswindow.h \
    budgetwindow.h \
    homewindow.h \
    loginwindow.h \
    mainwindow.h \
    monthlywindow.h \
    revwindow.h \
    signwindow.h \
    weeklywindow.h \
    welwindow.h

FORMS += \
    analysiswindow.ui \
    budgetwindow.ui \
    homewindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    monthlywindow.ui \
    revwindow.ui \
    signwindow.ui \
    weeklywindow.ui \
    welwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gyanibhai.qrc \
    img.qrc \
    mam.qrc \
    moneybg.qrc \
    welcom.qrc
