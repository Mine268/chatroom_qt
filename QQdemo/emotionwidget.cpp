#include "emotionwidget.h"
#include "ui_emotionwidget.h"

EmotionWidget::EmotionWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::EmotionWidget)
{
    ui->setupUi(this);
    //    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setTableInfo();
    initEmotion();
}

EmotionWidget::~EmotionWidget()
{
    delete ui;
}

void EmotionWidget::setTableInfo()
{
    //设置table的行列数以及宽度等
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //不可编辑

    column = 12;
    row = emotion_num / column;
    if (emotion_num % column != 0)
        row += 1;
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(column);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(emotion_size.width());
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(emotion_size.height());
    //    this->setFixedHeight(emotion_size.height() * row + 10);
    this->setFixedWidth(emotion_size.width() * column + 24);
    this->setFixedHeight(300);
}
void EmotionWidget::addemotionitem(QString filename)
{
    // 获取当前添加到第几行第几列
    //    qDebug() << ui->tableWidget->rowCount() << ui->tableWidget->columnCount();

    int row_ = m_emotionList.size() / ui->tableWidget->columnCount();
    int column_ = m_emotionList.size() % ui->tableWidget->columnCount();

    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
    tableWidgetItem->setData(Qt::UserRole + 1, filename);

    ui->tableWidget->setItem(row_, column_, tableWidgetItem);
    tableWidgetItem->setTextAlignment(Qt::AlignCenter);
    // 因为表情大部分为gif图片格式，所以这里用QMovie来显示

    EmotionLabel* emotion = new EmotionLabel(filename, QSize(60, 60));

    ui->tableWidget->setCellWidget(row_, column_, emotion);
    m_emotionList.push_back(filename);
}
//初始化表情
void EmotionWidget::initEmotion()
{

    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    int count = 0;
    QString path = ":/emoijgit/%1@2x.gif";
    for (int i = 1; i < 272; i++) {
        if (QFile::exists(path.arg(i + 1)))
            addemotionitem(path.arg(i + 1)), count++;
    }
}

void EmotionWidget::on_tableWidget_cellClicked(int row, int column)
{
    //单击某个框
    if (ui->tableWidget->cellWidget(row, column)) {
        QString str = "<img src=\"%1\" />";
        emit sendgifpath(str.arg(ui->tableWidget->item(row, column)->data(Qt::UserRole + 1).toString()));
        this->close();
    }
}
