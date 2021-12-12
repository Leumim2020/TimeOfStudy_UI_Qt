#ifndef FORM3_H
#define FORM3_H

#include <QDialog>
#include <form1.h>
namespace Ui {
class form3;
}

class form3 : public QDialog
{
    Q_OBJECT

public:
    explicit form3(QWidget *parent = nullptr,QString msg="Parabéns você terminou seu tempo de estudo",QString mp3Play="");
    ~form3();
public:
    form1 *j1;
private slots:
    void on_btn_reiniciar_clicked();
    void on_btn_fechar_clicked();

private:
    Ui::form3 *ui;

};

#endif // FORM3_H
