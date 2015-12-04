#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/********************************************************************************
** Form generated from reading UI file 'designerEcj696.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DESIGNERECJ696_H
#define DESIGNERECJ696_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCerrar;
    QAction *actionCopiar;
    QAction *actionPegar;
    QAction *actionCerrar_2;
    QAction *actionAbrir_2;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuAbrir;
    QMenu *menuEditar;
    QMenu *menuVista;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName(QStringLiteral("actionCerrar"));
        actionCopiar = new QAction(MainWindow);
        actionCopiar->setObjectName(QStringLiteral("actionCopiar"));
        actionPegar = new QAction(MainWindow);
        actionPegar->setObjectName(QStringLiteral("actionPegar"));
        actionCerrar_2 = new QAction(MainWindow);
        actionCerrar_2->setObjectName(QStringLiteral("actionCerrar_2"));
        actionAbrir_2 = new QAction(MainWindow);
        actionAbrir_2->setObjectName(QStringLiteral("actionAbrir_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 150, 75, 23));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(3, 0, 311, 101));
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(140, 150, 82, 17));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(250, 150, 70, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menuAbrir = new QMenu(menuArchivo);
        menuAbrir->setObjectName(QStringLiteral("menuAbrir"));
        menuEditar = new QMenu(menubar);
        menuEditar->setObjectName(QStringLiteral("menuEditar"));
        menuVista = new QMenu(menubar);
        menuVista->setObjectName(QStringLiteral("menuVista"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuEditar->menuAction());
        menubar->addAction(menuVista->menuAction());
        menuArchivo->addAction(menuAbrir->menuAction());
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar_2);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionAbrir_2);
        menuAbrir->addSeparator();
        menuEditar->addAction(actionCopiar);
        menuEditar->addSeparator();
        menuEditar->addAction(actionPegar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionCerrar->setText(QApplication::translate("MainWindow", "Guardar", 0));
        actionCopiar->setText(QApplication::translate("MainWindow", "Copiar", 0));
        actionPegar->setText(QApplication::translate("MainWindow", "Pegar", 0));
        actionCerrar_2->setText(QApplication::translate("MainWindow", "Cerrar", 0));
        actionAbrir_2->setText(QApplication::translate("MainWindow", "Abrir", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        radioButton->setText(QApplication::translate("MainWindow", "RadioButton", 0));
        checkBox->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
        menuAbrir->setTitle(QApplication::translate("MainWindow", "Nuevo", 0));
        menuEditar->setTitle(QApplication::translate("MainWindow", "Editar", 0));
        menuVista->setTitle(QApplication::translate("MainWindow", "Vista", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DESIGNERECJ696_H

#endif // MAINWINDOW_H

