#include <QApplication>
#include <Grafica/dialog.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog m;
    m.show();
    return app.exec();
}
