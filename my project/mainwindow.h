#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include <QtNetwork>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Dialog my;
    QString S1;
    QString S2;
    QNetworkAccessManager *manager;
private slots:
    void on_chaxun_clicked();
    void replyFinished(QNetworkReply *);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
