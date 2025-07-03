/********************************************************************************
** Form generated from reading UI file 'budgetwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUDGETWINDOW_H
#define UI_BUDGETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_budgetWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *frame_2;
    QFrame *frame_3;
    QTableView *tableView;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *budgetWindow)
    {
        if (budgetWindow->objectName().isEmpty())
            budgetWindow->setObjectName("budgetWindow");
        budgetWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(194, 196, 199, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        budgetWindow->setPalette(palette);
        centralwidget = new QWidget(budgetWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 160, 709, 291));
        frame->setMaximumSize(QSize(16777215, 297));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(20, 160, 661, 80));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(20, 20, 671, 261));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: #D9D9D9;"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        tableView = new QTableView(frame_3);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 11, 651, 241));
        tableView->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(185, 255, 199);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 50, 331, 81));
        budgetWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(budgetWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        budgetWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(budgetWindow);
        statusbar->setObjectName("statusbar");
        budgetWindow->setStatusBar(statusbar);

        retranslateUi(budgetWindow);

        QMetaObject::connectSlotsByName(budgetWindow);
    } // setupUi

    void retranslateUi(QMainWindow *budgetWindow)
    {
        budgetWindow->setWindowTitle(QCoreApplication::translate("budgetWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("budgetWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#000000;\">Expense Review</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class budgetWindow: public Ui_budgetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGETWINDOW_H
