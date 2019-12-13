#ifndef TABLEOPERATATIONS_H
#define TABLEOPERATATIONS_H
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHBoxLayout>
#include<QPushButton>
#include<vector>
#include<QMessageBox>
#include<QTextEdit>

class tableoperatations : public QDialog {
    Q_OBJECT

public:
    tableoperatations(QWidget *parent = nullptr, int a=3, int b=3);
    ~tableoperatations();
    std::vector<std::vector<int>> getcost();
    std::vector<int> getsource();
    std::vector<int> getdestination();
private slots:
    void calculate();

private:
    QTableWidget *table;
    QPushButton *button1;
    QTextEdit *result;

};

#endif // TABLEOPERATATIONS_H
