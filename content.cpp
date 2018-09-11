#include "content.h"
#include "ui_content.h"
#include <thread>
#include "addmusic.h"
#include "QMessageBox"

content::content(QMediaPlayer* p,QMediaPlaylist* l,std::thread* t,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::content)
{
    ui->setupUi(this);
    player=p;
    list=l;
    a=t;
    player->setVolume(0);
    connect(player,&QMediaPlayer::currentMediaChanged,this,&content::changed_media);
    connect(player,&QMediaPlayer::durationChanged,this,&content::duration_changed);
    connect(player,&QMediaPlayer::positionChanged,this,&content::move_position);
}

content::~content()
{
    delete ui;
}

void content::move_position(qint64 pos){
    ui->position->setValue(pos);
}

void content::on_pushButton_clicked()
{
    if(player->state()==player->PlayingState){
        player->pause();
        ui->pushButton->setIcon(QIcon(QPixmap(":/imgs/pla.png")));
        ui->pushButton->setIconSize(QSize(10,10));
        ui->pushButton->setStyleSheet("padding: 6px;");
    }
    else if (player->state()==player->PausedState){
        player->play();
        ui->pushButton->setIcon(QIcon(QPixmap(":/imgs/pause.png")));
        ui->pushButton->setIconSize(QSize(19,19));
        ui->pushButton->setStyleSheet("padding: 0px;");
    }
    if(player->currentMedia().canonicalUrl().toString()==""){
        addMusic* log=new addMusic(player,list);
        a=new std::thread([&](){log->runThread();});
        log->show();
    }
}

void content::changed_media(const QMediaContent& p){
    QString file=p.canonicalUrl().fileName();
    for(int i=file.length();i!=0;i--){
        if(file[i]=='.'){
            file.remove(i,abs(i-file.length()));
        }
    }
    ui->name->setText(file);
}

void content::duration_changed(qint64 pos){
    ui->position->setMaximum((int)player->duration());
}

void content::on_volue_sliderMoved(int position)
{
    player->setVolume(position);
}

void content::on_position_sliderMoved(int position)
{
    player->setPosition(position);
}

void content::on_next_clicked()
{
    list->next();
}

void content::on_previous_clicked()
{
    list->previous();
}
