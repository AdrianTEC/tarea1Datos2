#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QLocalSocket>
#include <QTextStream>

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
        mLocalServer->envia("anadir");
    }

void Widget::on_eliminar_clicked()
    {
        mLocalServer->envia("eliminar");
    }

void Widget::on_Enlazar_clicked()
    {
        mLocalServer->envia("enlazar");
    }

void Widget::on_calcular_clicked()
{
    mLocalServer->envia("calculo");
}
