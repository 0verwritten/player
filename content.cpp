#include "content.h"
#include "ui_content.h"

content::content(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::content)
{
    ui->setupUi(this);
}

content::~content()
{
    delete ui;
}
