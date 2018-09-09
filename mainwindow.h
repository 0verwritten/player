#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QEvent>
#include <thread>
#include <windowdragger.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(std::thread*,QWidget *parent = nullptr);
    ~MainWindow();

public:
  void setContent(QWidget *w);


signals:
  void windowIconLeftClicked();
  void windowIconRightClicked();
  void windowIconDblClick();

public slots:
  void setWindowTitle(const QString &text);
  void setWindowIcon(const QIcon &ico);

//
private:
  bool can=false;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;
//
protected:
  virtual void changeEvent(QEvent *event);


private slots:
    void on_icon_clicked();

private:
    Ui::MainWindow *ui;
    std::thread* a;
};

#endif // MAINWINDOW_H
