#include "widget.h"
#include "ui_widget.h"
#include "localserver.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mLocalServer= new LocalServer(this);
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
