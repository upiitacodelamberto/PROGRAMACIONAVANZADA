#include <QApplication>
#include <QLabel>


int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QLabel *P=new QLabel("¡¡¡  HOLA MUNDO QT  !!!");
    P->resize(200,100);
    P->show();

    return app.exec();
}
