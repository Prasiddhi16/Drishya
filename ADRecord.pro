QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IncomeExpenseTracker
TEMPLATE = app

SOURCES +=
main_moduleB.cpp
RecordWindow.cpp
HEADERS += \
    RecordWindow.h

FORMS += \
    RecordWindow.ui
