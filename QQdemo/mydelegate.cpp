#include "mydelegate.h"

Mydelegate::Mydelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}
QWidget* Mydelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    //设置显示数据的组件
    QComboBox* combox = new QComboBox(parent);
    combox->addItems(item_name);
    combox->setEditable(edit);
    return combox;
}

void Mydelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    //从数据模型中获取数值，设置为编辑器的显示值
    QString str = index.model()->data(index, Qt::EditRole).toString();
    QComboBox* comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentText(str);
}

void Mydelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    //将代理组件的数据保存到数据模型中
    QComboBox* comboBox = static_cast<QComboBox*>(editor);

    QString str = comboBox->currentText();

    model->setData(index, str, Qt::EditRole);
}

void Mydelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

void Mydelegate::set_items(QStringList name, bool edit_)
{
    item_name = name;
    edit = edit_;
}
