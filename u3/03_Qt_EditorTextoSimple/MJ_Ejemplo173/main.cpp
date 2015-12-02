#include <QApplication>
#include <QTextEdit>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextEdit VentanaEditorTexto;
    VentanaEditorTexto.show();

    return app.exec();
}
