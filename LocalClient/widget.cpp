#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>
#include<QJsonObject>
#include <QJsonDocument>

Widget::Widget(QWidget *parent) :QWidget(parent),ui(new Ui::Widget)
    {
        ui->setupUi(this);

        mSocket= new QLocalSocket(this);

        mLocalServer= new LocalServer(this);
        mLocalServer->listen("user");

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
        close();
    }

void Widget::on_anadir_clicked()
    {
        mLocalServer->envia(NewOrden("anadir",ui->newnodo->value(),0));

    }

void Widget::on_eliminar_clicked()
    {
        mLocalServer->envia(NewOrden("eliminar",ui->byenodo->value(),0));
    }

void Widget::on_Enlazar_clicked()
    {
        mLocalServer->envia(NewOrden("enlazar",ui->inicioe->value(),ui->finale->value()));
    }

void Widget::on_calcular_clicked()
    {
        mLocalServer->envia(NewOrden("calculo",ui->inicioC->value(),ui->finalC->value()));
    }

QString Widget::NewOrden(QString a,int b, int c){
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

