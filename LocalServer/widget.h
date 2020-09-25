#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
using namespace std;
namespace Ui {
class Widget;
}
class LocalServer;
class QLocalSocket;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void conectar();
private slots:
    void on_iniciar_clicked();

    void on_enviar_clicked();
    bool comprobar(QString valor);

    void on_quitar_clicked();
    void call(QString info);

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
    QLocalSocket *mSocket;
    QJsonObject* orden;
    QString value(QString valor);
};

#endif // WIDGET_H
