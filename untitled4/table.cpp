#include "table.h"

table::table(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant table::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int table::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int table::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant table::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
