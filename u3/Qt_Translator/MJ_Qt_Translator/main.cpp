#include <QApplication>
#include <QPushButton>
#include <QTranslator>

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    QTranslator translator;
    translator.load("hellotr_la");
    app.installTranslator(&translator);

    QPushButton hola(QPushButton::tr("¡¡¡HOLA MUNDO!!!"));
    hola.resize(1335,695);

    hola.show();
    return app.exec();
}
