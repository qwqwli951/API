#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    MainWindow w;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));
    w.setWindowTitle(QObject::tr("查询图书信息"));
    w.setFixedSize( w.width (),w.height ());//固定窗口大小
    w.show();   
    return a.exec();
}
