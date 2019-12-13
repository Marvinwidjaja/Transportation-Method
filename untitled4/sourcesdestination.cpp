#include "sourcesdestination.h"
#include "ui_sourcesdestination.h"

SourcesDestination::SourcesDestination(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourcesDestination)
{
    ui->setupUi(this);
}

SourcesDestination::~SourcesDestination()
{
    delete ui;
}
