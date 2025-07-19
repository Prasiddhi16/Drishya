TEMPLATE = app
TARGET = goalspages

QT += widgets sql
CONFIG += c++17

QMAKE_CXXFLAGS += -O0

SOURCES += \
    main_moduleA.cpp \
    visions.cpp \
    profile.cpp \
    insertt.cpp \
    goaldata.cpp

HEADERS += \
    visions.h \
    profile.h \
    insertt.h \
    goaldata.h

FORMS += \
    visions.ui \
    profile.ui \
    insertt.ui

RESOURCES += \
    resource.qrc

# Optional macOS bundle settings
macx:CONFIG += app_bundle
macx:QMAKE_INFO_PLIST = Info.plist

# Optional Windows executable setting
win32:CONFIG += embed_manifest_exe
