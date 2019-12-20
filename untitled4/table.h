#ifndef TABLE_H
#define TABLE_H

#include <QAbstractTableModel>

class table : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit table(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return 3;
    }

    int columnCount(const QModelIndex &parent = QModelIndex()) const override
    {
        return 3;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // TABLE_H
