#ifndef TABLEOPERATIONS_H
#define TABLEOPERATIONS_H
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHBoxLayout>
#include<QPushButton>
#include<vector>
#include<QMessageBox>
#include<QTextEdit>
#include<string>
enum boolean{FALSE,TRUE};

class tableoperations : public QDialog {
    Q_OBJECT

public:
    tableoperations(QWidget *parent = nullptr, int a=3, int b=3);
    ~tableoperations();
    std::vector<std::vector<int>> getcost();
    std::vector<int> getsource();
    std::vector<int> getdestination();
private slots:
    void calculate();

private:
    QTableWidget *input_table;
    QPushButton *calc_button;
    QTextEdit *result;

};

#endif // TABLEOPERATATIONS_H
