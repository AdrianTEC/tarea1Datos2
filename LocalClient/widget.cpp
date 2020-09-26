#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
#include<QJsonObject>
#include <QJsonDocument>
#include <math.h>
#include <iostream>
#include<Graph.h>

Widget::Widget(QWidget *parent) :QWidget(parent),ui(new Ui::Widget)
    {
        ui->setupUi(this);

        mSocket= new QLocalSocket(this);

        mLocalServer= new LocalServer(this);

        graph=new Graph(ui->canva);

        grafo= new Grafo<int>;

        this->setWindowTitle("Visualizar Grafos");
        connect(mSocket,&QLocalSocket::readyRead,[&]{QTextStream T(mSocket);ui->CONSOLE->addItem(T.readAll());});
    }

Widget::~Widget()
    {
        delete ui;
    }

void Widget::on_conectar_clicked()
    {

        mSocket->connectToServer(ui->servidor->text());
    }


void Widget::on_quitar_clicked()
    {
        mLocalServer->close();
        free(mSocket);
        free(mLocalServer);


        close();
    }
/**
 * @brief Widget::on_anadir_clicked
 */
void Widget::on_anadir_clicked()
    {

        try{
         int algo =graph->Points->getLen();
            mLocalServer->envia(NewOrden("crear",ui->newnodo->value(),algo,0));

            addNodeImage();
            }

        catch(int e)
            {
            addNodeImage();
            }


    }

void Widget::on_eliminar_clicked()
    {

    }

void Widget::on_Enlazar_clicked()
    {
        if(ui->inicioe->value()!=ui->finale->value())
        {

            int algo =graph->Points->getLen();
            if(ui->inicioe->value() <algo && ui->finale->value()<algo)
                {

                mLocalServer->envia(NewOrden("enlazar",ui->inicioe->value(),ui->finale->value(),ui->value->value()));
                AddEdge();

                }




        }

    }

void Widget::on_calcular_clicked()
    {
        mLocalServer->envia(NewOrden("calculo",ui->inicioC->value(),ui->finalC->value(),0));
    }




void Widget::AddEdge()
    {
        graph->addEdge(ui->inicioe->value(),ui->finale->value(), ui->value->value() );
        graph->update();
        grafo->fixRelationShip(ui->inicioe->value(),ui->finale->value(),ui->value->value() );
    }

void Widget::on_getRoute_clicked()
    {

    }

void Widget::addNodeImage()
    {
        int x;
        int y ;

        x = rand()%700+20;
        y = rand()%220+40;
        DoubleList<int> pos;
        pos.add(x);
        pos.add(y);
        historialPosiciones->add( pos );
        int algo = graph->Points->getLen();
        grafo->AddNode(algo);

        graph->addNode(x,y,ui->newnodo->value());
        graph->update();
    }
QString Widget::NewOrden(QString a,int b, int c,int d)
    {
        QJsonObject comand
            {
              {"orden",a},
              {"inicio",QString::number(b) },
              {"valor",QString::number(d) },
              {"final",QString::number(c) }
            };
        QJsonDocument doc(comand);
        QString strJson(doc.toJson(QJsonDocument::Compact));
        return strJson;
    }


void Widget::on_pushButton_clicked()
{
    mLocalServer->listen(ui->nombre->text());
}
