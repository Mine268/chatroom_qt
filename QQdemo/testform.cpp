#include "testform.h"
#include "ui_testform.h"

TestForm::TestForm(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::TestForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
}

TestForm::~TestForm()
{
    delete ui;
}
