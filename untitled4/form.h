#ifndef FORM_H
#define FORM_H
#include "tableoperatations.h"
#include <QWidget>
namespace Ui {class Form;}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    tableoperatations * obj2;
    int nrows = 0;
    int ncolumns = 0;
    ~Form();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
