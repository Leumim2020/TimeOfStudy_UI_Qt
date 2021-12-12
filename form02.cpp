#include "form02.h"
#include "form3.h"
#include "ui_form02.h"
#include "QMessageBox"
#include "QTimer"
#include "QDateTime"

form02::form02(QWidget *parent,int tempo,QString msg,QString cMp3) :
    QDialog(parent),
    ui(new Ui::form02)
{
    ui->setupUi(this);
    // Parâmetro int tempo recebe tempo em milissegundos
    qtempo=tempo;
    mensagem=msg;
    mP3=cMp3;
    t = new QTimer(this);
    // Tempo start
    connect(t,SIGNAL(timeout()),this,SLOT(showTimer()));
    t->start(1000);

}

form02::~form02()
{
    delete ui;
}

void form02::showTimer(){

    QTime tempoAtual(0,0,0);
    QTime t;
    qtempo-=1000;
    /* Convertendo milissegundos e mostrar correspondência a unidade horas ou minutos
      exemplo add.MSecs(60000s) return 1m */
    t = tempoAtual.addMSecs(qtempo);
    QString txtTempo = t.toString("hh:mm:ss");
    ui->label->setText(txtTempo);
   // Se qtempo=0 tempo acabou destruindo form02 e mostrar form3
    if(qtempo==0){
        close();
        closerForm02_showForm3();
    }
}
void form02::closerForm02_showForm3(){
    form3 frm3(this,mensagem,mP3);
    frm3.exec();
}
void form02::on_btn_pausar_clicked()
{
    // parar tempo
    t->stop();
    ui->btn_pausar->hide();
    ui->btn_retomar->show();
}
void form02::on_btn_retomar_clicked()
{
    // retomar tempo
    t->start(1000);
    ui->btn_retomar->hide();
    ui->btn_pausar->show();
}

void form02::on_btn_interromper_clicked()
{
    // interromper tempo
    t->stop();
    QMessageBox::StandardButton opcao = QMessageBox::question(this,"Informação","Tem a certeza que pretende interromper o seu tempo de estudo?",QMessageBox::Yes|QMessageBox::No);
    if(opcao==QMessageBox::Yes){
        // Destruindo form02.ui e consequentemente interrompendo tempo
        t->stop();
        close();
        form3 *frm3 = new form3(this,"Tempo de estudo interrompido");
        frm3->show();
    }
    if(opcao==QMessageBox::No){
        t->start();
    }
}

