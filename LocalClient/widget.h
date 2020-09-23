#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
class QLocalSocket;
class LocalServer;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_conectar_clicked();

    void on_quitar_clicked();

    void on_anadir_clicked();

    void on_eliminar_clicked();

    void on_Enlazar_clicked();

    void on_calcular_clicked();

private:
    Ui::Widget *ui;
    QLocalSocket *mSocket;
    LocalServer *mLocalServer;
};

#endif // WIDGET_H
