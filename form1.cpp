#include "form1.h"
#include "form02.h"
#include "ui_form1.h"
#include "QDebug"
#include "QFileDialog"
#include "QMessageBox"

/* msMinuto quantidade de milissegundos que um minuto tem 1m->60000ms
  msHora quantidade de milissegundos que uma hora tem 1h->3600000ms
 */
#define msMinuto 60000
#define msHora 3600000

form1::form1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::form1)
{
    ui->setupUi(this);
    ui->cMsg->hide();
}

form1::~form1()
{
    delete ui;
}


void form1::on_pushButton_clicked()
{

    // Iniciando validação de lineEdit e comboBox
    if(nTempo == false && uTempo.isEmpty()){
        QMessageBox::information(this,"Informação","Digite a quantidade de tempo e selecione unidade de tempo","sim");
    }
    if(nTempo != 0 && uTempo.isEmpty()){
        QMessageBox::information(this,"Informação","Selecione unidade de tempo","sim");
    }
    if(nTempo == false && !uTempo.isEmpty()){
        QMessageBox::information(this,"Informação","Digite a quantidade de tempo","sim");
    }
    if(nTempo < 0 && !uTempo.isEmpty()){
        QMessageBox::information(this,"Informação","Quantidade de tempo não pode ser negativo ou zero","sim");
    }
    if(nTempo > 0 && !uTempo.isEmpty() && mp3.isEmpty()){
        QMessageBox::information(this,"Informação","Escolha música para despertalo quando seu tempo de estudo acabar","sim");
    }
    if(nTempo > 0 && !uTempo.isEmpty() && !mp3.isEmpty()){
        QMessageBox::StandardButton opcao = QMessageBox::question(this,"Informação","Deseja alterar os dados preenchidos antes do temporizador começar?",QMessageBox::Yes|QMessageBox::No);
        if(opcao == QMessageBox::No){
                if(uTempo == "minutos"){
                    nTempo *= msMinuto;
                    //Passando quantidade de tempo em milissegundos para o form02 no cunstrutor
                    close();// Fechando form1.ui
                     form02 *form2 = new form02(this,nTempo,msg,mp3);
                    form2->show();            }
                if(uTempo == "horas"){
                    nTempo = nTempo * msHora;
                    //Passando quantidade de tempo em milissegundos para o form02 no cunstrutor
                    hide();
                    form02 *form2 = new form02(this,nTempo);
                    form2->show();
            }
        }

    }

}

// Pegando valores de lineEdit e comboBox
void form1::on_lineEdit_cursorPositionChanged(int arg1)
{
    arg1 = ui->lineEdit->text().toInt();
    nTempo = arg1;
}

void form1::on_comboBox_activated(QString arg1)
{
    arg1 = ui->comboBox->currentText();

    uTempo = arg1;
}



void form1::on_radioButton_clicked()
{
    ui->cMsg->show();
}


void form1::on_radioButton_2_clicked()
{
    ui->cMsg->hide();
}

void form1::on_cMsg_cursorPositionChanged()
{
    int maxDletra=100;
    if(ui->cMsg->toPlainText().length()>maxDletra){
        ui->cMsg->textCursor().deletePreviousChar();
    }
    msg = ui->cMsg->toPlainText();
}


void form1::on_btn_mp3_clicked()
{
    mp3 = QFileDialog::getOpenFileName(this,tr("escolher música"),"/home/",tr("Música(*.mp3)"));
    if(!mp3.isEmpty()){
        ui->btn_mp3->setText("mp3 escolhida");
    }
}

