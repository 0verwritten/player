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

    ui->tableWidget->setRowCount(list->mediaCount());
    for(int i=0;i<list->mediaCount();i++){
    QTableWidgetItem* it=new QTableWidgetItem();
    it->setText(list->media(i).canonicalUrl().fileName());
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
    for(int i=0;i<list->mediaCount();i++){
    QTableWidgetItem* it=new QTableWidgetItem();
    QString file = list->media(i).canonicalUrl().fileName();
    for(int i=file.length();i!=0;i--){
        if(file[i]=='.'){
            file.remove(i,file.length()-i);
            break;
        }
    }
    it->setText(file);
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

void addMusic::on_pushButton_2_clicked()
{
    list->removeMedia(cur);
    ui->tableWidget->removeRow(cur);
}
