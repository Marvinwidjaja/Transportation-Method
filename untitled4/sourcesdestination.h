#ifndef SOURCESDESTINATION_H
#define SOURCESDESTINATION_H

#include <QWidget>

namespace Ui {
class SourcesDestination;
}

class SourcesDestination : public QWidget
{
    Q_OBJECT

public:
    explicit SourcesDestination(QWidget *parent = nullptr);
    ~SourcesDestination();

private:
    Ui::SourcesDestination *ui;
};

#endif // SOURCESDESTINATION_H
