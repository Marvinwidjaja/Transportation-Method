#include "form.h"
#include "ui_form.h"
#include "tableoperatations.h"
#include <QString>
#include <QLineEdit>
#include <QMessageBox>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    QString _nrows = ui->lineEdit->text();
    QString _ncolumns = ui->lineEdit_2->text();
    nrows = _nrows.toInt();
    ncolumns = _ncolumns.toInt();

    obj2=new tableoperatations(nullptr, nrows, ncolumns);
    obj2->show();
    close();
}
