#include "showmessage.h"
#include "ui_showmessage.h"

showMessage::showMessage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::showMessage)
{
    ui->setupUi(this);
    //    ui->label->setWordWrap(true);
    //    connect(ui->label->document(), SIGNAL(contentsChanged()), this, SLOT(update_height()));
}

showMessage::~showMessage()
{
    delete ui;
}

void showMessage::setinfo(QString username_me, QString qStr, QString html)
{
    //读取内容
    QString info = "发送方: " + username_me + " " + qStr + "\n";
    ui->lineEdit->setText(info);
    ui->label->setText(html);
}
