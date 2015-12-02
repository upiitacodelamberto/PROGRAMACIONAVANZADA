//Ejemplo 174
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[]){
    QApplication mi_aplicacion(argc,argv);
    QWidget *mi_widget=new QWidget;
    mi_widget->setGeometry(300,200,220,190);
    QLabel *mi_etiqueta=new QLabel("HOLA MUNDO",mi_widget);
    mi_etiqueta->setGeometry(30,10,100,40);
    QPushButton *mi_boton=new QPushButton("SALIR",mi_widget);
    mi_boton->setGeometry(10,50,100,30);
    QObject::connect(mi_boton,SIGNAL(clicked()),&mi_aplicacion,SLOT(quit()));
    mi_widget->show();
    return mi_aplicacion.exec();
}
