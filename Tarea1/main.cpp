#include "mainwindow.h"
#include <QApplication>
#include "grafo.cpp"
using namespace std;

int main(int argc, char *argv[])
{


    Grafo<int> milton;
    milton.add(1);
    milton.add(2);
    milton.enlazar(1,2);


    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

