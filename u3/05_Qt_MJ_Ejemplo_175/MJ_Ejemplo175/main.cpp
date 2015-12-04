#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QFont>
//#define ORIGINAL
#define MODIFICADO
int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QWidget *mi_widget=new QWidget();
    QLabel *mi_etiqueta=new QLabel("HOLA MUNDO",mi_widget);
    mi_etiqueta->setFont(QFont("Arial",22,QFont::Normal));
#ifdef ORIGINAL
    mi_etiqueta->setGeometry(20,10,200,50);
#endif
#ifdef MODIFICADO
    mi_etiqueta->setGeometry(100,10,800,400);
#endif
    QPushButton *boton=new QPushButton("SALIR",mi_widget);
    boton->setGeometry(50,100,100,30);
    boton->setFont(QFont("Time",18,QFont::Bold));
    QObject::connect(boton,SIGNAL(clicked()),
                     &app,SLOT(quit()));
    mi_widget->show();
    return app.exec();
}
