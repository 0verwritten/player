#ifndef ADDMUSIC_H
#define ADDMUSIC_H

#include <QDialog>


#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class addMusic;
}

class addMusic : public QDialog
{
    Q_OBJECT

public:
    explicit addMusic(QMediaPlayer*,QMediaPlaylist*,QWidget *parent = nullptr);
    ~addMusic();
    void runThread();

private slots:
    void on_pushButton_clicked();

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::addMusic *ui;
    QMediaPlayer* player;
    QMediaPlaylist* list;
    int cur;
};

#endif // ADDMUSIC_H
