#ifndef SOURCEDESTINATIONTABLE_H
#define SOURCEDESTINATIONTABLE_H
#include <QDialog>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QHBoxLayout>
#include<QPushButton>

class sourcedestinationtable : public QDialog {
    Q_OBJECT

public:
    sourcedestinationtable(QWidget *parent = nullptr);
    ~sourcedestinationtable();

private:
    QTableWidget *table;

};

#endif // SOURCEDESTINATIONTABLE_H
