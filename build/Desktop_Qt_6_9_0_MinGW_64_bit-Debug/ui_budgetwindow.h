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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_budgetWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView = new QTableView(frame);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color:black;"));

        verticalLayout_2->addWidget(tableView);


        verticalLayout->addWidget(frame);

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
        label->setText(QCoreApplication::translate("budgetWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#ffffff;\">Expense Review</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class budgetWindow: public Ui_budgetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUDGETWINDOW_H
