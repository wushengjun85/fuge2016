#include "telephone.h"
#include "ui_telephone.h"
//#include"hwlib/libat.h"

#include"hwlib/libfgs.h"

#include<QPaintEvent>

#include<QPainter>
#include<QTimer>

extern int ttyNum;
uchar telguaduanflag;

Telephone::Telephone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Telephone)
{
    ui->setupUi(this);


    QTimer *timertel = new QTimer(this);   //声明一个定时器
    connect(timertel, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新
    timertel->start(1000);

//    //初始化串口

//    ttyNum = Open_Gprs();
//    Gprs_Init(ttyNum);

}

Telephone::~Telephone()
{
    delete ui;
}



//void Telephone::on_pushButton_3_clicked()
//{

//    Gprs_close(ttyNum);

//    this->close();
//}

//void Telephone::on_pushButton_clicked()//打电话
//{
//    Call(ttyNum);
//}

void Telephone::on_pushButton_2_clicked()//挂电话
{
    //ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(./imagejy/zw/guaduans.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");

    Chup(ttyNum);

    //切换声道
    Audio_to_ARM();

    //Gprs_close(ttyNum);

    //ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(./imagejy/zw/guaduanh.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");


    this->close();
}


void Telephone::paintEvent(QPaintEvent *event)
{
    QPainter paintertel(this);
    QPixmap pixtel;

    pixtel.load("./imagejy/zw/telobj.bmp");
    paintertel.drawPixmap(0,0,1024,600,pixtel);
}
