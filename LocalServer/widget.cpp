#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QLocalSocket>
#include <QMessageBox>
using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    mSocket= new QLocalSocket(this);
    mLocalServer= new LocalServer(this);
    //connect(mLocalServer, SIGNAL(newConnection()), this, SLOT(conectart()));
    connect(mSocket,&QLocalSocket::readyRead,[&]{QTextStream T(mSocket);ui->CONSOLE->addItem(T.readAll());});
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
        close();
    }
void Widget::conectar(){

    mSocket->connectToServer("user");

}
