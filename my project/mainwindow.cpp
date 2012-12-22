#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_chaxun_clicked()
{
    if(ui->ID->text()!="")
    {
    S1="http://api.douban.com/book/subject/isbn/";
    S2=ui->ID->text();  //获取输入的ISBN
    //设置QTextCodec可以显示中文
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QNetworkRequest request;
    request.setUrl(QUrl(S1+S2));
    manager = new QNetworkAccessManager(this);  //新建QNetworkAccessManager对象
    connect(manager,SIGNAL(finished(QNetworkReply*)),  //关联信号和槽
                this,SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(request)); //发送请求
    }
    else{
        //如果不正确，弹出警告对话框
        QMessageBox::information(0,"error!",QString(QObject::tr("你没有输入ISBN\n请重新输入。")));
    }
}
void MainWindow::replyFinished(QNetworkReply *reply)
{
        QString all = reply->readAll();
        if("bad isbn"==all)  //如果输入错误，则关闭窗口并弹出错误对话框
        {
            QMessageBox::information(0, "error!",QString(QObject::tr("输入的ISBN有错误\n请重新输入")));
            ui->ID->clear();
            return;
        }
        else
        {
            my.setFixedSize( my.width (),my.height ());//固定窗口大小
            my.setDoc(all);
            my.show();
        }
        reply->deleteLater();   //最后要释放reply对象
}

