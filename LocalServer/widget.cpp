#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QLocalSocket>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <stdio.h>
#include<QJsonObject>
#include <QJsonDocument>
using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mSocket= new QLocalSocket(this);
    mLocalServer= new LocalServer(this);

    connect(mSocket,&QLocalSocket::readyRead,[&]{QTextStream T(mSocket);
        QString algo= T.readAll();

         call(algo);});

    this->setWindowTitle("Servidor");
}

Widget::~Widget()
    {
        delete ui;
    }

void Widget::on_iniciar_clicked()
    {
       if( ! mLocalServer->listen(ui->servidor->text()))
        {
            QMessageBox::critical(this,"Error",mLocalServer->errorString());
        }
       else
        {
            QMessageBox::information(this,"Servidor","iniciado");
            conectar();
        }
    }




void Widget::on_enviar_clicked()
    {
        mLocalServer->envia(ui->msj->text());
    }

void Widget::on_quitar_clicked()
    {
        mLocalServer->close();
        close();
    }
void Widget::call(QString info)
    {

        QJsonDocument doc1 = QJsonDocument::fromJson(info.toUtf8());
        try
            {
               QJsonObject orden_aux = doc1.object();// orden es un objeto json
               orden=&orden_aux;

               ui->CONSOLE->addItem("Ejecutar: "+value("orden") +" "+ value("inicio")+" " +value("final") );
               if(comprobar("enlazar"))
                   {

                   }
               if(comprobar("eliminar"))
                   {

                   }
               if(comprobar("crear"))
                   {

                   }
               if(comprobar("calculo"))
                   {

                   }


            }
       catch(int e){
                ui->CONSOLE->addItem("Error al asignar el puntero");
            }





    }
QString Widget::value(QString valor)
    {
        try{
                QJsonValue algo = orden->value(valor);
                return algo.toString();
            }
        catch (int e)
            {

            }

    }
bool Widget::comprobar(QString valor)
    {
        return QString::compare(value("orden"),valor);

    }

void Widget::conectar(){

    mSocket->connectToServer("user");

}
