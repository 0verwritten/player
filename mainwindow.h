#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MouseButtonSignaler: public QObject
{
  Q_OBJECT

public:
  MouseButtonSignaler(QObject * parent = 0) : QObject(parent) {}
  void installOn(QWidget * widget) { widget->installEventFilter(this); }

protected:
  virtual bool eventFilter(QObject * obj, QEvent * ev) Q_DECL_OVERRIDE {
    if ((   ev->type() == QEvent::MouseButtonPress
         || ev->type() == QEvent::MouseButtonRelease
         || ev->type() == QEvent::MouseButtonDblClick)
        && obj->isWidgetType()) {
      emit mouseButtonEvent(static_cast<QWidget*>(obj),
                            static_cast<QMouseEvent*>(ev));
    }
    return false;
  }
signals:
  void mouseButtonEvent(QWidget *, QMouseEvent *);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
  void setContent(QWidget *w);

private:
  void styleWindow(bool bActive, bool bNoState);

signals:
  void windowIconLeftClicked();
  void windowIconRightClicked();
  void windowIconDblClick();

public slots:
  void setWindowTitle(const QString &text);
  void setWindowIcon(const QIcon &ico);

private slots:
  void on_applicationStateChanged(Qt::ApplicationState state);
  void on_minimizeButton_clicked();
  void on_restoreButton_clicked();
  void on_closeButton_clicked();
  void on_windowTitlebar_doubleClicked();

  void on_pushButton_clicked();

protected:
  virtual void changeEvent(QEvent *event);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
