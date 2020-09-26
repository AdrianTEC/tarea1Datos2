#include "widget.h"


using namespace std;
/**
 * Constructor
 * @brief Widget::Widget
 * @param parent
 * @author Adrian Gonzalez
 */
Widget::Widget(QWidget *parent) :QWidget(parent),ui(new Ui::Widget)
    {
        ui->setupUi(this);
        mSocket= new QLocalSocket(this);
        grafo= new Grafo<int>;
        mLocalServer= new LocalServer(this);
        connect(mSocket,&QLocalSocket::readyRead,[&]{QTextStream T(mSocket);QString algo= T.readAll();call(algo);});
        this->setWindowTitle("Servidor");
    }

Widget::~Widget()
    {
        delete ui;
    }
/**
 * @brief Widget::on_iniciar_clicked
 *  * @author Adrian Gonzalez
 */
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


/**
 * @brief Widget::on_enviar_clicked
 * @name ENVIAR
 * @author Adrian Gonzalez
 *
 */

void Widget::on_enviar_clicked()
    {
        mLocalServer->envia(ui->msj->text());
    }
/**
 * @brief Widget::on_quitar_clicked
  * @author Adrian Gonzalez
 */
void Widget::on_quitar_clicked()
    {
        mLocalServer->close();
        close();
    }
/**
 * @brief Widget::call
 * @param info
 * @name CALL
 * @author Adrian Gonzalez
 */

void Widget::call(QString info)
    {

        QJsonDocument doc1 = QJsonDocument::fromJson(info.toUtf8());

               QJsonObject orden_aux = doc1.object();// orden es un objeto json
               orden=&orden_aux;

               ui->CONSOLE->addItem("Ejecutar: "+value("orden") +" "+ value("inicio")+" " +value("final") );
               if(comprobar("enlazar"))
                   {
                            grafo->fixRelationShip(value("inicio").toInt(),value("final").toInt(),2);
                   }

               if(comprobar("crear"))
                   {

                            int algo=value("inicio").toInt();
                            grafo->AddNode(algo);

                   }
               if(comprobar("calculo"))
                   {

                               DoubleList<int>*  resultado ;

                               DoubleList<DoubleList<double>>* algo=grafo->getRelations();
                               resultado= getPath(Floyd(*algo),value("inicio").toInt(),value("final").toInt());
                               QString res ="";
                               for(int i =0; i< resultado->getLen();i++)
                               {
                                   res+= QString::number(*resultado->get(i));
                                   res+="-";
                               }
                               mLocalServer->envia(res);

                    }








    }
/**
 * @brief Widget::value
 * @param valor
 * @return
 * @author Adrian Gonzalez
 */
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
/**
 * @brief Widget::comprobar
 * @param valor
 * @return
 * @author Adrian Gonzalez
 */
bool Widget::comprobar(QString valor)
    {
        QString algo= value("orden");
        return algo==valor;

    }

void Widget::conectar(){



}

void Widget::on_escu_clicked()
{
    mSocket->connectToServer(ui->user->text());
}
