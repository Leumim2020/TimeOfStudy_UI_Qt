#ifndef FORM02_H
#define FORM02_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class form02;
}

class form02 : public QDialog
{
    Q_OBJECT

public:
    explicit form02(QWidget *parent = nullptr,int tempo=0,QString msg="",QString cMp3="");
    ~form02();
public slots:
    void showTimer();
    void closerForm02_showForm3();
public:
    QTimer *t;
    int qtempo;
    QString mensagem,mP3;
private slots:

    void on_btn_pausar_clicked();
    void on_btn_retomar_clicked();
    void on_btn_interromper_clicked();

private:
    Ui::form02 *ui;

};

#endif // FORM02_H
