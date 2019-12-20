#include "sourcedestinationtable.h"
#include"tableoperatations.h"
#include <cmath>
sourcedestinationtable::sourcedestinationtable(QWidget *parent) : QDialog(parent) {

    table = new QTableWidget;
    table->setRowCount(5);
    table->setColumnCount(1);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(table);

    setLayout(layout);
}

sourcedestinationtable::~sourcedestinationtable() {
    delete table;
}
