#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QDebug>
#include<inputhook.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    InputHook *getHk() const;

private:
    Ui::Dialog *ui;
    InputHook *hk;
    unsigned long long EventCount;
    int show_line;

private slots:
    void MouseEvent(const HE_Mouse &m);
    void KeyboardEvent(const HE_Keyboard &k);
    void on_pushButton_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
};

#endif // DIALOG_H
