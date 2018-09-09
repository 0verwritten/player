#ifndef ADDMUSIC_H
#define ADDMUSIC_H

#include <QDialog>

namespace Ui {
class addMusic;
}

class addMusic : public QDialog
{
    Q_OBJECT

public:
    explicit addMusic(QWidget *parent = nullptr);
    ~addMusic();
    void runThread();

private:
    Ui::addMusic *ui;
};

#endif // ADDMUSIC_H
