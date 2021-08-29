#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QComboBox>
#include <QObject>
#include <QStyledItemDelegate>
class Mydelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit Mydelegate(QObject* parent = nullptr);
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
        const QModelIndex& index) const Q_DECL_OVERRIDE;

    void setEditorData(QWidget* editor, const QModelIndex& index) const override;

    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const override;

    virtual void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;

    void set_items(QStringList, bool);

private:
    QStringList item_name;
    bool edit;
};

#endif // MYDELEGATE_H
