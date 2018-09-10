#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>

#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class content;
}

class content : public QWidget
{
    Q_OBJECT   

public:
    explicit content(QMediaPlayer*,QMediaPlaylist*,QWidget *parent = nullptr);
    ~content();

private:
    Ui::content *ui;
    QMediaPlayer* player;
    QMediaPlaylist* list;
};

#endif // CONTENT_H
