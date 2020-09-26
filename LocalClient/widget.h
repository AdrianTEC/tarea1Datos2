#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPainter>
#include<QPaintEvent>
#include<Pintor.h>
#include<QLineEdit>

namespace Ui {
class Widget;
}
class QLocalSocket;
class LocalServer;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_conectar_clicked();

    void on_quitar_clicked();

    void on_anadir_clicked();

    void on_eliminar_clicked();

    void on_Enlazar_clicked();

    void on_calcular_clicked();


    QString NewOrden(QString a,int b, int c,int d);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QLocalSocket *mSocket;
    LocalServer *mLocalServer;
    Graph * graph;
    QString getLineEditText(QLineEdit* lineEdit);
    DoubleList<DoubleList<int>>* historialPosiciones;
    Grafo<int>* grafo;

    void AddEdge();

    void on_getRoute_clicked();

    void addNodeImage();
};

#endif // WIDGET_H
