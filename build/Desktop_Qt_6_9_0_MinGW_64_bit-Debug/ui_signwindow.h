/********************************************************************************
** Form generated from reading UI file 'signwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNWINDOW_H
#define UI_SIGNWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QPushButton *pushButton;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menusignin_page;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *signWindow)
    {
        if (signWindow->objectName().isEmpty())
            signWindow->setObjectName("signWindow");
        signWindow->resize(800, 600);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::BrushStyle::SolidPattern);
        palette.setBrush(QPalette::ColorGroup::Active, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Inactive, QPalette::ColorRole::Window, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Base, brush);
        palette.setBrush(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Window, brush);
        signWindow->setPalette(palette);
        centralwidget = new QWidget(signWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 0, 371, 521));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"background:#D9D9D9;\n"
"border-radius:50px\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 30, 321, 91));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 90, 201, 20));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 140, 61, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Trebuchet MS")});
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 170, 281, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("color:black;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 210, 61, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(50, 240, 281, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("color:black;"));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(50, 310, 281, 20));
        lineEdit_3->setStyleSheet(QString::fromUtf8("color:black;"));
        lineEdit_3->setEchoMode(QLineEdit::EchoMode::Password);
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 280, 91, 20));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 480, 61, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
""));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 350, 251, 20));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(50, 380, 281, 20));
        lineEdit_4->setStyleSheet(QString::fromUtf8("color:black;"));
        lineEdit_4->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(50, 440, 281, 20));
        lineEdit_5->setStyleSheet(QString::fromUtf8("color:black;"));
        lineEdit_5->setEchoMode(QLineEdit::EchoMode::Password);
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 410, 241, 20));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
""));

        horizontalLayout->addWidget(widget);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setPixmap(QPixmap(QString::fromUtf8(":/signin.jpg")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        signWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(signWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menusignin_page = new QMenu(menubar);
        menusignin_page->setObjectName("menusignin_page");
        signWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(signWindow);
        statusbar->setObjectName("statusbar");
        signWindow->setStatusBar(statusbar);

        menubar->addAction(menusignin_page->menuAction());

        retranslateUi(signWindow);

        QMetaObject::connectSlotsByName(signWindow);
    } // setupUi

    void retranslateUi(QMainWindow *signWindow)
    {
        signWindow->setWindowTitle(QCoreApplication::translate("signWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:700; color:#000000;\">Hello Friend!</span></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#54655b;\">Create an account to stay connected!</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Name:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Email:</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Password:</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("signWindow", "Sign in", nullptr));
        label_7->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Date Of Birth:</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("signWindow", "<html><head/><body><p><span style=\" font-size:14pt;\">Your Pet Name:</span></p><p><br/></p></body></html>", nullptr));
        label->setText(QString());
        menusignin_page->setTitle(QCoreApplication::translate("signWindow", "signin page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signWindow: public Ui_signWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNWINDOW_H
