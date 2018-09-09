#include "addmusic.h"
#include "ui_addmusic.h"

addMusic::addMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMusic)
{
    ui->setupUi(this);
}

addMusic::~addMusic()
{
    delete ui;
}

void addMusic::runThread(){
    while(true){
    int width=this->geometry().width();

    ui->tableWidget->setColumnWidth(0,width-40);
    }
}
