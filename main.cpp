#include "mainwindow.h"
#include "content.h"
#include <thread>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::thread *th;
    MainWindow w(th);
    content *c = new content(w.player,w.list);
    w.setContent(c);
    w.show();


    return a.exec();
}
