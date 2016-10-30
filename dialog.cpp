#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    EventCount(0),
    show_line(100)
{
    ui->setupUi(this);
    setWindowFlags(Qt::MaximizeUsingFullscreenGeometryHint);
    this->hk = new InputHook();
    connect(hk,&InputHook::Mouse_Event,this,&Dialog::MouseEvent);
    connect(hk,&InputHook::Keyboard_Event,this,&Dialog::KeyboardEvent);
    this->ui->lineEdit->setText("100");



}

Dialog::~Dialog()
{
    delete this->hk;
    delete ui;
}

InputHook *Dialog::getHk() const
{
    return hk;
}

void Dialog::MouseEvent(const HE_Mouse &m)
{
    if(this->ui->checkBox->isChecked()){
        QString str = "Mouse ";
        if(m.button & 0x0001) str += "LEFT BUTTON DOWN   ";
        if(m.button & 0x0002) str += "LEFT BUTTON UP     ";
        if(m.button & 0x0004) str += "RIGHT BUTTON DOWN  ";
        if(m.button & 0x0008) str += "RIGHT BUTTON UP    ";
        if(m.button & 0x0010) str += "MIDDLE BUTTON DOWN ";
        if(m.button & 0x0020) str += "MIDDLE BUTTON UP   ";
        if(m.button & 0x0040) str += "BUTTON 4 DOWN      ";
        if(m.button & 0x0080) str += "BUTTON 4 UP        ";
        if(m.button & 0x0100) str += "BUTTON 5 DOWN      ";
        if(m.button & 0x0200) str += "BUTTON 5 UP        ";
        if(m.button & 0x0400) str += "WHEEL              ";
        str +="xpos[%1] ypos[%2] delta[%3] xmove[%4] ymove[%5]";
        str = str.arg(m.posx,4).arg(m.posy,4).arg(m.delta,3).arg(m.movex,3).arg(m.movey,3);
        this->ui->listWidget->insertItem(0,str);
        if(this->ui->listWidget->count() > show_line) delete this->ui->listWidget->item(show_line);
        ++EventCount;
        this->ui->pushButton->setText(QString::number(EventCount));
    }
}

void Dialog::KeyboardEvent(const HE_Keyboard &k)
{
    if(this->ui->checkBox_2->isChecked()){
        ++EventCount;
        this->ui->pushButton->setText(QString::number(EventCount));
    }
}

void Dialog::on_pushButton_clicked()
{
    EventCount = 0;
    this->ui->pushButton->setText("0");
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    show_line = arg1.toInt();
    if(show_line <1) show_line = 1;
    int cut_num = this->ui->listWidget->count();
    for(int i=show_line;i<cut_num;++i) delete ui->listWidget->item(show_line);
}
