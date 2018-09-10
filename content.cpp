#include "content.h"
#include "ui_content.h"

content::content(QMediaPlayer* p,QMediaPlaylist* l,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::content)
{
    ui->setupUi(this);
    player=p;
    list=l;
    player->setVolume(0);
}

content::~content()
{
    delete ui;
}
