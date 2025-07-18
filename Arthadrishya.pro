QT       += core gui sql
QT += charts sql
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    compare.cpp \
    expert.cpp \
    finaldial.cpp \
    graph.cpp \
    history.cpp \
    main_moduleC.cpp \
    review.cpp \
    secdialog.cpp \
    taxdialog.cpp \
    thirddialog.cpp

HEADERS += \
    compare.h \
    expert.h \
    finaldial.h \
    graph.h \
    history.h \
    review.h \
    secdialog.h \
    taxdialog.h \
    thirddialog.h

FORMS += \
    compare.ui \
    expert.ui \
    finaldial.ui \
    graph.ui \
    history.ui \
    review.ui \
    secdialog.ui \
    taxdialog.ui \
    thirddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    res.qrc
