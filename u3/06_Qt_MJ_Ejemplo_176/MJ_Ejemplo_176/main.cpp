//Ejemplo  176
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QtGui>
#include <QFont>
#include <QVBoxLayout>

int main(int argc, char *argv[]){
    QApplication mi_aplicacion(argc,argv);
    QWidget window;
    QTextEdit *EditorTexto=new QTextEdit(&window);
    EditorTexto->setFont(QFont("Time",26,QFont::Bold));
    QPushButton *BotonSalida=new QPushButton("SALIR");
    BotonSalida->setFont(QFont("Arial",18,QFont::Bold));

    QObject::connect(BotonSalida,SIGNAL(clicked()),qApp,SLOT(quit()));

    QVBoxLayout plantilla;
    plantilla.addWidget(EditorTexto);
    plantilla.addWidget(BotonSalida);

    window.setLayout(&plantilla);

    window.show();
    return mi_aplicacion.exec();
}
