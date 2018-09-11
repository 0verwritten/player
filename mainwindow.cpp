#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "addmusic.h"
#include <QGraphicsDropShadowEffect>

MainWindow::MainWindow(std::thread* b,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player=new QMediaPlayer();
    list=new QMediaPlaylist();
    player->setPlaylist(list);
    a=b;
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    // append minimize button flag in case of windows,
    // for correct windows native handling of minimize function
  #if defined(Q_OS_WIN)
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
  #endif
    setAttribute(Qt::WA_TranslucentBackground);

    // add window shadow
    if (   QSysInfo::productType().toLower() != "windows"
       || (QSysInfo::productType().toLower() == "windows" && QSysInfo::productVersion().toInt() > 7) ) {

       //shadow under window title text
       //QGraphicsDropShadowEffect *textShadow = new QGraphicsDropShadowEffect;
       //textShadow->setBlurRadius(4.0);
       //textShadow->setColor(QColor(0,0,0));
       //textShadow->setOffset(0.0);
       //ui->titleText->setGraphicsEffect(textShadow);

       //window shadow
       QGraphicsDropShadowEffect *windowShadow = new QGraphicsDropShadowEffect;
       windowShadow->setBlurRadius(9.0);
       windowShadow->setColor(palette().color(QPalette::Highlight));
       windowShadow->setOffset(0.0);
       ui->windowFrame->setGraphicsEffect(windowShadow);
    }

    // watch mouse clicks on icon label and fire own signals


  }

  void MainWindow::changeEvent(QEvent *event)
  {
    if (event->type() == QEvent::WindowStateChange) {
      if (windowState().testFlag(Qt::WindowNoState)) {
        event->ignore();
      }
    }
    event->accept();
  }

  void MainWindow::setContent(QWidget *w)
  {
    ui->windowContent->setMargin(0);
    ui->windowContent->addWidget(w);
  }

  void MainWindow::setWindowTitle(const QString &text)
  {
    ui->titleText->setText(text);
  }

  //void MainWindow::setWindowIcon(const QIcon &ico)
  //{
  //  ui->icon->setIcon(ico.pixmap(16,16));
  //}

  MainWindow::~MainWindow(){
      delete ui;
  }

  //
  void MainWindow::mousePressEvent(QMouseEvent *event) {

      if(event->y()<=30){
          can=true;
  m_nMouseClick_X_Coordinate = event->x();
  m_nMouseClick_Y_Coordinate = event->y();
      }
      else{
          can=false;
      }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if(can==false)
        return;
  move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
//

void MainWindow::on_icon_clicked()
{
    addMusic* log=new addMusic(player,list);
    a=new std::thread([&](){log->runThread();});
    log->show();
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}
