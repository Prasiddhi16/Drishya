TEMPLATE = app
TARGET = itsdrishya

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
    welwindow.cpp \
    RecordWindow.cpp \
    compare.cpp \
    expense.cpp \
    expert.cpp \
    finaldial.cpp \
    goaldata.cpp \
    graph.cpp \
    Help.cpp \
    history.cpp \
    historypage.cpp \
    insertt.cpp \
    profile.cpp \
    review.cpp \
    secdialog.cpp \
    taxdialog.cpp\
    thirddialog.cpp \
    visions.cpp




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
    welwindow.h \
    RecordWindow.h \
    compare.h \
    expense.h \
    expert.h \
    finaldial.h \
    goaldata.h \
    graph.h \
    Help.h \
    history.h \
    historypage.h \
    insertt.h \
    profile.h \
    review.h \
    secdialog.h \
    taxdialog.h \
    thirddialog.h \
    visions.h


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
    welwindow.ui \
    RecordWindow.ui \
    compare.ui \
    expense.ui \
    expert.ui \
    finaldial.ui \
    graph.ui\
    Help.ui\
    history.ui\
    historypage.ui\
    insertt.ui\
    profile.ui \
    review.ui \
    secdialog.ui \
    taxdialog.ui\
    thirddialog.ui\
    visions.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    finallogo.qrc \
    gyanibhai.qrc \
    img.qrc \
    mam.qrc \
    moneybg.qrc \
    welcom.qrc \
    images.qrc\
    res.qrc \

