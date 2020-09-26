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
        historialPosiciones= new DoubleList<DoubleList<int>>();
        mLocalServer= new LocalServer(this);
        mLocalServer->listen("user");
        graph=new Graph(ui->canva);

        grafo= new DGraph<int>;

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
        free(mSocket);
        free(mLocalServer);
        free(historialPosiciones);
        free(graph);
        free(grafo);
        close();
    }

void Widget::on_anadir_clicked()
    {

        try{
            mLocalServer->envia(NewOrden("anadir",ui->newnodo->value(),0));
            addNodeImage();
            }

        catch(int e)
            {
            addNodeImage();
            }


    }

void Widget::on_eliminar_clicked()
    {
        mLocalServer->envia(NewOrden("eliminar",ui->byenodo->value(),0));

    }

void Widget::on_Enlazar_clicked()
    {
        if(ui->inicioe->value()!=ui->finale->value())
        {
            mLocalServer->envia(NewOrden("enlazar",ui->inicioe->value(),ui->finale->value()));
            AddEdge();
        }

    }

void Widget::on_calcular_clicked()
    {
        mLocalServer->envia(NewOrden("calculo",ui->inicioC->value(),ui->finalC->value()));
    }




void Widget::AddEdge()
    {
        graph->addEdge(ui->inicioe->value(),ui->finale->value(), ui->value->value() );
        graph->update();
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



        graph->addNode(x,y,ui->newnodo->value());
        graph->update();
    }
QString Widget::NewOrden(QString a,int b, int c)
    {
        QJsonObject comand
            {
              {"orden",a},
              {"inicio",QString::number(b) },
              {"final",QString::number(c) }
            };
        QJsonDocument doc(comand);
        QString strJson(doc.toJson(QJsonDocument::Compact));
        return strJson;
    }

