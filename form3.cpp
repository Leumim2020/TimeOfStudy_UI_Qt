#include "form3.h"
#include "ui_form3.h"
#include "form1.h"
#include "QMediaPlayer"
#include "QtPrintSupport/QPrinter"
form3::form3(QWidget *parent,QString msg,QString mp3Player) :
    QDialog(parent),
    ui(new Ui::form3)
{
    ui->setupUi(this);
    ui->textEdit->setText(msg);
    QMediaPlayer *mp3 = new QMediaPlayer(this);
    mp3->setMedia(QUrl::fromLocalFile(mp3Player));
    mp3->play();
}

form3::~form3()
{
    delete ui;
}

void form3::on_btn_reiniciar_clicked()
{
   form1 *f = new form1;
   f->nTempo=false;
   f->show();
    close();
}


void form3::on_btn_fechar_clicked()
{
    j1 = new form1(this);
    close();
}

