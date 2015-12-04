//Ejemplo 177
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char *argv[]){
    QApplication aplicacion(argc,argv);
    QWidget *miwidget=new QWidget;
    miwidget->setWindowTitle("Anote su peso");

    QSpinBox *spinBox=new QSpinBox;
    QSlider *slider=new QSlider(Qt::Vertical);
    spinBox->setRange(0,100);
    slider->setRange(0,100);

    QObject::connect(spinBox,SIGNAL(valueChanged(int)),
                     slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),
                     spinBox,SLOT(setValue(int)));
    spinBox->setValue(20);

    QHBoxLayout *plantilla=new QHBoxLayout;
    plantilla->addWidget(spinBox);
    plantilla->addWidget(slider);
    miwidget->setLayout(plantilla);

    miwidget->show();
    return aplicacion.exec();
}
