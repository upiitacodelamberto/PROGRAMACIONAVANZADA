#include <QApplication>
#include <QPushButton>


int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QPushButton boton("BOTON QPUSHBUTTON");
    boton.resize(200,100);
    boton.show();

    return app.exec();
}
