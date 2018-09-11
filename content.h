#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>

#include <thread>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class content;
}

class content : public QWidget
{
    Q_OBJECT   

public:
    explicit content(QMediaPlayer*,QMediaPlaylist*,std::thread*,QWidget *parent = nullptr);
    ~content();

private slots:
    void move_position(qint64);

    void duration_changed(qint64);

    void on_pushButton_clicked();

    void changed_media(const QMediaContent&);


    void on_volue_sliderMoved(int position);

    void on_position_sliderMoved(int position);

    void on_next_clicked();

    void on_previous_clicked();

private:
    Ui::content *ui;
    QMediaPlayer* player;
    std::thread* a;
    QMediaPlaylist* list;
};

#endif // CONTENT_H
