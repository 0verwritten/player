#include "addmusic.h"
#include "ui_addmusic.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>


addMusic::addMusic(QMediaPlayer* p,QMediaPlaylist* l,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addMusic)
{
    ui->setupUi(this);
    player=p;
    list=l;
    this->setWindowFlags(Qt::WindowCloseButtonHint);

    //finish name of musics

    for(int i=0;i<list->mediaCount();i++){
    QTableWidgetItem* it=new QTableWidgetItem();
    it->setText(list->media(i).canonicalUrl().fileName());
    QMessageBox::information(this,"",list->media(i).canonicalUrl().fileName());
    it->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->tableWidget->setItem(i,0,it);
    }
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

void addMusic::on_pushButton_clicked()
{

    QUrl u = QFileDialog::getOpenFileUrl();
    list->addMedia(QMediaContent(u));
    ui->tableWidget->setRowCount(list->mediaCount());

    //finish name of musics

    for(int i=0;i<list->mediaCount();i++){
    QTableWidgetItem* it=new QTableWidgetItem();
    it->setText(list->media(i).canonicalUrl().fileName());
    it->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->tableWidget->setItem(i,0,it);
    }
}

void addMusic::on_tableWidget_cellClicked(int row, int column)
{
    cur=row;

}

void addMusic::on_tableWidget_cellDoubleClicked(int row, int column)
{
    list->setCurrentIndex(row);
    player->play();
}
