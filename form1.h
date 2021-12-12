#ifndef FORM1_H
#define FORM1_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class form1; }
QT_END_NAMESPACE

class form1 : public QWidget
{
    Q_OBJECT

public:
    form1(QWidget *parent = nullptr);
    ~form1();

public:
    int nTempo=false;
    QString uTempo,msg="Parabéns você terminou seu tempo de estudo",mp3;
private slots:
    void on_pushButton_clicked();
    void on_lineEdit_cursorPositionChanged(int arg1);
    void on_comboBox_activated(QString arg1);
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_cMsg_cursorPositionChanged();
    void on_btn_mp3_clicked();

private:
    Ui::form1 *ui;

};
#endif // FORM1_H
