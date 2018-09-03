#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>

namespace Ui {
class content;
}

class content : public QWidget
{
    Q_OBJECT   

public:
    explicit content(QWidget *parent = nullptr);
    ~content();

private:
    Ui::content *ui;
};

#endif // CONTENT_H
