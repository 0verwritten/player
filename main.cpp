#include "mainwindow.h"
#include "content.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    content *c = new content();
    w.setContent(c);
    w.show();

    return a.exec();
}
