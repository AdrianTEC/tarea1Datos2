#include "widget.h"
#include "ui_widget.h"
#include <QLocalSocket>
#include <QTextStream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket= new QLocalSocket(this);
    connect(mSocket,&QLocalSocket::readyRead,[&]{
        QTextStream T(mSocket);
        ui->CONSOLE->addItem(T.readAll());
    });
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

}
