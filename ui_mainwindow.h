/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionboundary_show;
    QAction *actionboundary_hide;
    QAction *actionwireframe;
    QAction *actionshaded;
    QAction *actionorthographic;
    QAction *actionperspective;
    QAction *actioncube_hide;
    QAction *actioncube_show;
    QAction *actiontranceparancy_dialog;
    QAction *actiontriedron_hide;
    QAction *actiontriedron_show;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menuView;
    QMenu *menuview;
    QMenu *menushow_boundary;
    QMenu *menusolid;
    QMenu *menumodel;
    QMenu *menucube;
    QMenu *menutranceparancy;
    QMenu *menutrihedron;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(627, 415);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(13, 17, 23, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(19, 25, 34, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(16, 21, 28, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(6, 8, 11, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(9, 11, 15, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        MainWindow->setPalette(palette);
        actionboundary_show = new QAction(MainWindow);
        actionboundary_show->setObjectName(QString::fromUtf8("actionboundary_show"));
        actionboundary_hide = new QAction(MainWindow);
        actionboundary_hide->setObjectName(QString::fromUtf8("actionboundary_hide"));
        actionwireframe = new QAction(MainWindow);
        actionwireframe->setObjectName(QString::fromUtf8("actionwireframe"));
        actionshaded = new QAction(MainWindow);
        actionshaded->setObjectName(QString::fromUtf8("actionshaded"));
        actionorthographic = new QAction(MainWindow);
        actionorthographic->setObjectName(QString::fromUtf8("actionorthographic"));
        actionperspective = new QAction(MainWindow);
        actionperspective->setObjectName(QString::fromUtf8("actionperspective"));
        actioncube_hide = new QAction(MainWindow);
        actioncube_hide->setObjectName(QString::fromUtf8("actioncube_hide"));
        actioncube_show = new QAction(MainWindow);
        actioncube_show->setObjectName(QString::fromUtf8("actioncube_show"));
        actiontranceparancy_dialog = new QAction(MainWindow);
        actiontranceparancy_dialog->setObjectName(QString::fromUtf8("actiontranceparancy_dialog"));
        actiontriedron_hide = new QAction(MainWindow);
        actiontriedron_hide->setObjectName(QString::fromUtf8("actiontriedron_hide"));
        actiontriedron_show = new QAction(MainWindow);
        actiontriedron_show->setObjectName(QString::fromUtf8("actiontriedron_show"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 627, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        menubar->setPalette(palette1);
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuview = new QMenu(menuView);
        menuview->setObjectName(QString::fromUtf8("menuview"));
        menuview->setAutoFillBackground(true);
        menushow_boundary = new QMenu(menuview);
        menushow_boundary->setObjectName(QString::fromUtf8("menushow_boundary"));
        menusolid = new QMenu(menuview);
        menusolid->setObjectName(QString::fromUtf8("menusolid"));
        menumodel = new QMenu(menuview);
        menumodel->setObjectName(QString::fromUtf8("menumodel"));
        menucube = new QMenu(menuview);
        menucube->setObjectName(QString::fromUtf8("menucube"));
        menutranceparancy = new QMenu(menuview);
        menutranceparancy->setObjectName(QString::fromUtf8("menutranceparancy"));
        menutrihedron = new QMenu(menuview);
        menutrihedron->setObjectName(QString::fromUtf8("menutrihedron"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuView->menuAction());
        menuView->addAction(menuview->menuAction());
        menuview->addAction(menusolid->menuAction());
        menuview->addAction(menushow_boundary->menuAction());
        menuview->addAction(menumodel->menuAction());
        menuview->addAction(menucube->menuAction());
        menuview->addAction(menutranceparancy->menuAction());
        menuview->addAction(menutrihedron->menuAction());
        menushow_boundary->addAction(actionboundary_show);
        menushow_boundary->addAction(actionboundary_hide);
        menusolid->addAction(actionwireframe);
        menusolid->addAction(actionshaded);
        menumodel->addAction(actionorthographic);
        menumodel->addAction(actionperspective);
        menucube->addAction(actioncube_hide);
        menucube->addAction(actioncube_show);
        menutranceparancy->addAction(actiontranceparancy_dialog);
        menutrihedron->addAction(actiontriedron_hide);
        menutrihedron->addAction(actiontriedron_show);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "occt widget", nullptr));
        actionboundary_show->setText(QCoreApplication::translate("MainWindow", "boundary show", nullptr));
        actionboundary_hide->setText(QCoreApplication::translate("MainWindow", "boundary hide", nullptr));
        actionwireframe->setText(QCoreApplication::translate("MainWindow", "wireframe", nullptr));
        actionshaded->setText(QCoreApplication::translate("MainWindow", "shaded", nullptr));
        actionorthographic->setText(QCoreApplication::translate("MainWindow", "orthographic", nullptr));
        actionperspective->setText(QCoreApplication::translate("MainWindow", "perspective", nullptr));
        actioncube_hide->setText(QCoreApplication::translate("MainWindow", "cube hide", nullptr));
        actioncube_show->setText(QCoreApplication::translate("MainWindow", "cube show", nullptr));
        actiontranceparancy_dialog->setText(QCoreApplication::translate("MainWindow", "tranceparancy dialog", nullptr));
        actiontriedron_hide->setText(QCoreApplication::translate("MainWindow", "triedron hide", nullptr));
        actiontriedron_show->setText(QCoreApplication::translate("MainWindow", "triedron show", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuview->setTitle(QCoreApplication::translate("MainWindow", "view", nullptr));
        menushow_boundary->setTitle(QCoreApplication::translate("MainWindow", "boundary", nullptr));
        menusolid->setTitle(QCoreApplication::translate("MainWindow", "solid", nullptr));
        menumodel->setTitle(QCoreApplication::translate("MainWindow", "model", nullptr));
        menucube->setTitle(QCoreApplication::translate("MainWindow", "cube", nullptr));
        menutranceparancy->setTitle(QCoreApplication::translate("MainWindow", "tranceparancy", nullptr));
        menutrihedron->setTitle(QCoreApplication::translate("MainWindow", "triedron", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
