#include "dialog.h"
#include "ui_dialog.h"
#include <QTextCodec.h>
#include <QtXml>
#include <qmessagebox.h>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
void Dialog::setDoc(QString all)
{
        QDomDocument doc;
        QString errorStr;
        int errorLine;
        int errorCol;
        if (!doc.setContent(all,true,&errorStr,&errorLine,&errorCol)) {return;  }//将内容读到doc中
       QDomElement docElem = doc.documentElement();  //返回根元素
       QDomNode n = docElem.firstChild();   //返回根节点的第一个子节点
       while(!n.isNull())   //节点不为空
        {           
           if (n.isElement())  //如果节点是元素
           {
           QDomElement e = n.toElement();  //将其转换为元素
           QString str=e.toElement().tagName();
          if("title"==str) ui->title->setText(e.toElement().text());
          else if("link"==str && e.attributeNode("rel").nodeValue()=="image") ui->link->setText(e.attributeNode("href").nodeValue());
          else if("summary"==str) ui->summary->setText(e.toElement().text());
          else if("attribute"==str)
          {
             QString s=e.attributeNode("name").nodeValue();
             if("isbn10"==s)ui->isbn10->setText(e.text());
             else if("pages"==s)ui->pages->setText(e.text());
             else if("author"==s)ui->author->setText(e.text());
             else if("price"==s)ui->price->setText(e.text());
             else if("publisher"==s)ui->publisher->setText(e.text());
             else if("pubdate"==s)ui->pubdate->setText(e.text());
          }
           }
            n = n.nextSibling();
       }
}
Dialog::~Dialog()
{
    delete ui;
}

