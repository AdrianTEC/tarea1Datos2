#include "mainwindow.h"
#include <QApplication>
#include "grafo.cpp"
using namespace std;

int main(int argc, char *argv[])
{


    Grafo<int> milton;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

