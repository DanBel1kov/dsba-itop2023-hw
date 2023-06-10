#ifndef READONLYDELEGATE_H
#define READONLYDELEGATE_H

#endif // READONLYDELEGATE_H
#include <QStyledItemDelegate>

class ReadOnlyDelegate : public QStyledItemDelegate
{
public:
    explicit ReadOnlyDelegate(QObject* parent = nullptr)
        : QStyledItemDelegate(parent)
    {
    }

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override
    {
        Q_UNUSED(parent);
        Q_UNUSED(option);
        Q_UNUSED(index);
        return nullptr;
    }
};
