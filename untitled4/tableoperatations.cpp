#include "tableoperatations.h"
#include <cmath>
#include<form.h>
#include<QPushButton>
#include<QMessageBox>
#include<QString>
#include<vector>
#include<QLabel>
#include<QTextEdit>
#include<string>
#include<iostream>
tableoperatations::tableoperatations(QWidget *parent, int a, int b) : QDialog(parent)
{
    table = new QTableWidget;
    table->setRowCount(a+1);
    table->setColumnCount(b+1);
    for(int i=0;i<b;++i){
        table->setHorizontalHeaderItem(i, new QTableWidgetItem);
        Q_ASSUME(table->model()->setHeaderData(i,Qt::Horizontal,QStringLiteral("D%1").arg(i+1)));
    }
    for(int i=0;i<a;++i){
        table->setVerticalHeaderItem(i, new QTableWidgetItem);
        Q_ASSUME(table->model()->setHeaderData(i,Qt::Vertical,QStringLiteral("S%1").arg(i+1)));
    }
    table->setVerticalHeaderItem(a, new QTableWidgetItem);
    table->model()->setHeaderData(a,Qt::Vertical,QStringLiteral("Source"));
    table->setHorizontalHeaderItem(b, new QTableWidgetItem);
    table->model()->setHeaderData(b,Qt::Horizontal,QStringLiteral("Destination"));
    table->removeCellWidget(a,b);
    button1 = new QPushButton("Calculate", this);
//    button1->setText("Calculate");
    connect(button1, SIGNAL (clicked()),this, SLOT (calculate()));
    result=new QTextEdit("");
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);
    layout->addWidget(button1);
    layout->addWidget(result);
    setLayout(layout);
}

std::vector<std::vector<int>>  tableoperatations::getcost()
{
    std::vector<std::vector <int>> cost;
    for(int i=0;i<this->table->rowCount()-1;i++)
    {
        std::vector <int> row;
        for(int j=0;i<this->table->columnCount()-1;j++)
        {
            row.push_back(this->table->item(i, j)->text().toInt());
        }
        cost.push_back(row);
    }
    return cost;
}

std::vector<int> tableoperatations::getsource()
{
    std::vector <int> source;
    int row = this->table->rowCount() - 1;
    for(int i=0;i<this->table->columnCount() - 1;i++)
    {
        source.push_back(this->table->item(row, i)->text().toInt());
    }
    return source;
}

std::vector<int> tableoperatations::getdestination()
{
    std::vector <int> destination;
    int column=this->table->columnCount() - 1;
    for(int j=0;j<this->table->columnCount();j++)
    {
        destination.push_back(this->table->item(j, column)->text().toInt());
    }
    return destination;
}


void tableoperatations::calculate()
{
    int sum = 0;
    std::vector<std::vector<int>> cost = getcost();
    QString str;
    for (int i = 0; i < cost.size(); i++)
    {
        for (int j = 0; j < cost[i].size(); j++)
        {
            cost[i][j];
        }
    }

//    std::vector<int> source = getsource();
//    std::vector<int> destination=getdestination();
//    for(int i=0,j=0;(i<table->rowCount() && j< table->columnCount());)
//    {
//        if (source[i]<destination[j])
//        {
//        sum+=cost[i][j]*source[i];
//        destination[j]-=source[i];
//        i++;
//        }
//        else if(source[i]>destination[j])
//            {
//                sum+=cost[i][j]*destination[j];
//                source[i]-=destination[j];
//                j++;
//            }
//            else
//                if(source[i]==destination[j])
//            {
//                        sum+=cost[i][j]*destination[j];
//                        i++;
//                        j++;
//                }
//    }
//     int i = 42;
//     QString s = QString::number(i);
//     result->setText(std::to_string(i).c_str());
//       result->setText("sd");


}

tableoperatations::~tableoperatations() {
    delete table;
}
