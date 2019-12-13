#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLineEdit>
#include <QTabWidget>
#include "form.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class QPushButton;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    Form *obj;
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

public:
    Ui::MainWindow *ui;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *button1;
};
#endif // MAINWINDOW_H
