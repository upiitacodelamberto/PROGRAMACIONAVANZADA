#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QMainWindow *Principal;
    Principal=new QMainWindow();
    Ui_MainWindow Menus;
    Menus.setupUi(Principal);
    Principal->show();
    return app.exec();
}
