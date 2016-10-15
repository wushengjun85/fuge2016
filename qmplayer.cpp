#include "qmplayer.h"
#include <iostream> 
#include <QTextCodec>
#include<QDebug>

#define BTN_SPACE_LENTH      50     /*用于控制按钮之间的间隔偏移量*/
QMPlayer::QMPlayer(QWidget *parent) :QWidget(parent)
{
    //resize(1024, 600);
   //setWindowTitle("mplayer");
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);
    playLabel = new QLabel(this);
    playLabel->setGeometry(QRect(0, 0, 860, 480));
    //playLabel->setPixmap(QPixmap("imagejy/mplayer.png"));
    playLabel->setStyleSheet("background-color:#000000;color:#ffffff;");

    ctlFrame = new QFrame(this);
    ctlFrame->setGeometry(QRect(0, 483, 1020, 115));
    ctlFrame->setFrameShape(QFrame::StyledPanel);
    ctlFrame->setFrameShadow(QFrame::Raised);

    currentlBar = new QSlider(ctlFrame);
    currentlBar->setGeometry(QRect(5, 5, 855, 18));
    currentlBar->setOrientation(Qt::Horizontal);
    connect(currentlBar, SIGNAL(sliderMoved(int)), this, SLOT(current(int)));

    percentLabel = new QLabel(ctlFrame);
    percentLabel->setGeometry(QRect(865, 2, 40, 18));

    timeLabel = new QLabel(ctlFrame);
    timeLabel->setGeometry(QRect(915, 2, 60, 18));

    stopBtn = new QPushButton("stop",ctlFrame);
    stopBtn->setText(QString::fromUtf8("停止"));
    stopBtn->setGeometry(QRect(10, 30, 80, 25));
    stopBtn->setEnabled(false);
    connect(stopBtn, SIGNAL(clicked()), this, SLOT(stop()));

    prevBtn = new QPushButton("prev",ctlFrame);
    prevBtn->setText(QString::fromUtf8("上一个"));
    prevBtn->setGeometry(QRect(110+BTN_SPACE_LENTH, 30, 80, 25));
    connect(prevBtn, SIGNAL(clicked()), this, SLOT(prev()));
    
    playBtn = new QPushButton("play",ctlFrame);
    playBtn->setText(QString::fromUtf8("播放"));
    playBtn->setGeometry(QRect(210+BTN_SPACE_LENTH*2, 30, 80, 25));
    playBtn->setEnabled(false);
    connect(playBtn, SIGNAL(clicked()), this, SLOT(pause()));

    nextBtn = new QPushButton("next", ctlFrame);
    nextBtn->setText(QString::fromUtf8("下一个"));
    nextBtn->setGeometry(QRect(310+BTN_SPACE_LENTH*3, 30, 80, 25));
    connect(nextBtn, SIGNAL(clicked()), this, SLOT(next()));
#if 0
    speedBtn = new QPushButton("speed", ctlFrame);
    speedBtn->setText(QString::fromUtf8("速度"));
    speedBtn->setGeometry(QRect(410, 30, 80, 25));
    connect(speedBtn, SIGNAL(clicked()), this, SLOT(setSpeed()));
#endif

    quitBtn = new QPushButton("return",ctlFrame);
    quitBtn->setText(QString::fromUtf8("返回"));
    quitBtn->setGeometry(QRect(410+BTN_SPACE_LENTH*4, 30, 80, 25));
    connect(quitBtn, SIGNAL(clicked()), this, SLOT(quit()));

    voiceLabel = new QLabel("voice:", ctlFrame);
    voiceLabel->setText(QString::fromUtf8("音量"));
    voiceLabel->setGeometry(QRect(10, 80, 60, 25));

    volumeSlider = new QSlider(ctlFrame);
    volumeSlider->setGeometry(QRect(72, 82, 200, 25));
    volumeSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(100);
    volumeSlider->setEnabled(false);
    connect(volumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeVolume(int)));

    volumeLabel = new QLabel(ctlFrame);
    volumeLabel->setGeometry(QRect(295, 80, 60, 25));
    volumeLabel->setText(QString::number(100));

    playList = new QListWidget(this);
    playList->setGeometry(QRect(860, 1, 164, 455));
    connect(playList, SIGNAL(itemDoubleClicked(QListWidgetItem *)), this, SLOT(playListItem(QListWidgetItem *))); 

    addBtn = new QPushButton(QIcon("imagejy/add.png"), "", this);
    addBtn->setGeometry(QRect(865, 455, 32, 32));
    addBtn->setStyleSheet("border-style:none");
    connect(addBtn, SIGNAL(clicked()), this, SLOT(addItem())); 

    delBtn = new QPushButton(QIcon("imagejy/remove.png"), "", this);
    delBtn->setGeometry(QRect(982, 455, 32, 32));
    delBtn->setStyleSheet("border-style:none");
    connect(delBtn, SIGNAL(clicked()), this, SLOT(delItem())); 

	p=NULL;
}

/*************************************************

Function:next

Description:play the next movie/song

*************************************************/
void QMPlayer::next()
{
    if (playList->count() != 0) {
        if(playList->currentRow() == playList->count() - 1 || playList->currentRow() < 0)
            playList->setCurrentRow(0);
        else
            playList->setCurrentRow(playList->currentRow() + 1);
        
        play(playList->currentItem()->text());
        playBtn->setText("pause");
        playBtn->setText(QString::fromUtf8("暂停"));
    }
}

/*************************************************

Function:prev

Description:play the previous movie/song

*************************************************/
void QMPlayer::prev()
{
    std::cout<<"127\n";
    std::cout<<playList->currentRow()<<"\n";
    if (playList->count() != 0) {
        if(playList->currentRow() <= 0){
            playList->setCurrentRow(playList->count() - 1);
            std::cout<<"131\n";
        }
        else{
            playList->setCurrentRow(playList->currentRow() - 1);
            std::cout<<"135\n";
        }
        std::cout<<"["<<playList->currentItem()->text().toStdString()<<"]"<< "\n";
        std::cout<<"138\n";
        play(playList->currentItem()->text());
        std::cout<<"139\n";
        playBtn->setText("pause");
        playBtn->setText(QString::fromUtf8("暂停"));
    }
}

/*************************************************

Function:addItem

Description:add a item in the playlist

*************************************************/
void QMPlayer::addItem()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "choose movie/song", "/media/", "Movie/Song (*.mp4 *.mp3 *.mpg)");
    if(fileNames.count() != 0)
        playList->addItems(fileNames);
}

/*************************************************

Function:delItem

Description:delete a item in the playlist

*************************************************/
void QMPlayer::delItem()
{
    if(playList->currentRow() == -1)
        QMessageBox::warning(this, "note", "not select or playList is null", QMessageBox::Yes);
    else
        playList->takeItem(playList->currentRow());
}

/*************************************************

Function:playListItem

Description:play a item in the playlist

*************************************************/
void QMPlayer::playListItem(QListWidgetItem *item)
{
    play(item->text());
    playBtn->setText("pause");
    playBtn->setText(QString::fromUtf8("暂停"));
}

/*************************************************

Function:play

Description:call mplayer to play movie/song

*************************************************/

void QMPlayer::play(QString fileName)
{
    std::cout<<"198\n";
    if (p != NULL)
        p->kill();
  std::cout<<"201\n";
    p = new QProcess(this);
    connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve())); 

    QStringList args;

    args << "-slave";
    args << "-quiet";
#if 0
    args<<"-wid"<<QString::number(playLabel->winId(),10);
    args << "-zoom";
    args << "-x";
    args << "640";
    args << "-y";
    args << "480";
#endif	
    args << fileName;
    p->start("./mplayer", args);
    if (!p->waitForStarted())  
    {  
        std::cout << "start failed !\n";
        return ;  
    }  
    else
    {
         std::cout << "start ok!\n";
    }
      std::cout<<"229\n";
    playBtn->setEnabled(true);
    stopBtn->setEnabled(true);
    volumeSlider->setEnabled(true);
    addBtn->setEnabled(false);
    delBtn->setEnabled(false);

    timeLabel->show();
    percentLabel->show();
}

/*************************************************

Function:pause

Description:pause a playing movie/song

*************************************************/
void QMPlayer::pause()
{
    p->write("pause\n");
    //if (playBtn->text() == "play")
    if(playBtn->text()==QString::fromUtf8("播放"))
    {
        connect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve())); 
        dataRecieve();
        playBtn->setText("pause");
        playBtn->setText(QString::fromUtf8("暂停"));
    }
    else
    {
        disconnect(p, SIGNAL(readyReadStandardOutput()), this, SLOT(dataRecieve())); 
        playBtn->setText("play");
        playBtn->setText(QString::fromUtf8("播放"));
    }

}

/*************************************************

Function:stop

Description:stop a playing movie/song

*************************************************/
void QMPlayer::stop()
{

    std::cout<<"263\n";
    if(p!=NULL){

        p->write("quit\n");
        p->kill();
    }
    std::cout<<"270\n";
    p = NULL;
    std::cout<<"266\n";
    timeLabel->hide();
    percentLabel->hide();
    std::cout<<"269\n";
    playLabel->update();
    std::cout<<"271\n";
    playBtn->setEnabled(false);
    stopBtn->setEnabled(false);
    volumeSlider->setEnabled(false);
    addBtn->setEnabled(true);
    delBtn->setEnabled(true);
}

/*************************************************

Function:changeVolume

Description:change the volume

*************************************************/
void QMPlayer::changeVolume(int v)
{
    volumeLabel->setText(QString::number(v));
    p->write(QString("volume " + QString::number(v) + " 2\n").toUtf8());
}

/*************************************************

Function:setSpeed

Description:set the playing speed

*************************************************/
void QMPlayer::setSpeed()
{
    double speed=QInputDialog::getDouble(this, "set speed", "compare with nomal speed");
    if(speed > 0)
        p->write(QString("speed_set " + QString::number(speed) + " 2\n").toUtf8());
}

/*************************************************

Function:dataRecieve

Description:recieve the data from mplayer

*************************************************/
void QMPlayer::dataRecieve()
{
    p->write("get_time_length\n");
    p->write("get_time_pos\n");
    p->write("get_percent_pos\n");

    while (p->canReadLine()) {
        QByteArray b = p->readLine();
        b.replace(QByteArray("\n"), QByteArray(""));
        QString s(b);
        
        if (b.startsWith("ANS_TIME_POSITION")) {
            currentStr = s.mid(18);
            timeLabel->setText(currentStr + "s");
            currentlBar->setValue(s.mid(18).toFloat());
        }
        else if (b.startsWith("ANS_LENGTH")) {
            totalTime = s.mid(11);
            currentlBar->setRange(0, s.mid(11).toFloat());
        }
        else if(b.startsWith("ANS_PERCENT_POSITION")) {
            currentPercent = s.mid(21);
            percentLabel->setText(currentPercent + "%");
        }
    }

}

/*************************************************

Function:current

Description:get the current process from mplayer

*************************************************/

void QMPlayer::current(int value)
{
    p->write(QString("seek " + QString::number(value) + " 2\n").toUtf8());
}

/*************************************************

Function:quit

Description: quit mplayer,get back to yibiao
history:
2016/10/13 wangxw add

*************************************************/

void QMPlayer::quit()
{
    if(p!=NULL){

        p->write("quit\n");
        p->kill();
    }

    p=NULL;
    this->close();

}
