#ifndef THENODE_H
#define THENODE_H

#include <QWidget>
#include<QPainter>
#include "Grafo.hpp"
#include<string>
#include<math.h>
#define Defaul_Radius 20
#define FontType "times"
#include<QtDesigner/QDesignerCustomWidgetInterface>
class Graph : public QWidget//,public QDesignerCustomWidgetInterface
{
    Q_OBJECT
   // Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit Graph(QWidget *parent = nullptr);
    void addNode(int x,int y,int value);
    void setRadius(int rad);
    void addEdge(int a,int b,int value);
    void setSize(int x,int y);
    DoubleList<QPoint>* Points;
protected:
    void paintEvent(QPaintEvent* event);
private:

    int *radius;
    DoubleList<int>* Edges;
    DoubleList<QPoint> *stringPoint;
    DoubleList<int>* stringValues;
    QColor giveColor();
    int *Xlen=new int(800);
    int *Ylen=new int(800);

    int *currentValue =0;
};

#endif // THENODE_H
