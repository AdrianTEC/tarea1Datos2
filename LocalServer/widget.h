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

    void on_quitar_clicked();

private:
    Ui::Widget *ui;
    LocalServer *mLocalServer;
    QLocalSocket *mSocket;
};

#endif // WIDGET_H
