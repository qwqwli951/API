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
        if (!doc.setContent(all,true,&errorStr,&errorLine,&errorCol)) {return;  }//�����ݶ���doc��
       QDomElement docElem = doc.documentElement();  //���ظ�Ԫ��
       QDomNode n = docElem.firstChild();   //���ظ��ڵ�ĵ�һ���ӽڵ�
       while(!n.isNull())   //�ڵ㲻Ϊ��
        {           
           if (n.isElement())  //����ڵ���Ԫ��
           {
           QDomElement e = n.toElement();  //����ת��ΪԪ��
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

