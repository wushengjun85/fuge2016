#ifndef _H_QMPLAYER_
#define _H_QMPLAYER_

#include <QtGui>

class QMPlayer:public QWidget
{
    Q_OBJECT
public:
    void play(QString fileName);
      QMPlayer(QWidget *parent = 0); 

private slots:
    void next();
    void prev();
    void pause();
    void stop();
    void setSpeed();
    void dataRecieve();
    void addItem();
    void delItem();
    void current(int);   
    void changeVolume(int);
    void playListItem(QListWidgetItem *);
    void quit();
private:
       QLabel *playLabel;
    QLabel *timeLabel;
    QLabel *percentLabel;
    QLabel *voiceLabel;
    QLabel *volumeLabel;
    
    QFrame *ctlFrame;
    QPushButton *playBtn;
    QPushButton *stopBtn;
    QPushButton *prevBtn;
    QPushButton *nextBtn;
    QPushButton *speedBtn;
    QPushButton *quitBtn;

    QSlider *currentlBar;
    QSlider *volumeSlider;

    QListWidget *playList;
    QPushButton *addBtn;
    QPushButton *delBtn;
    
    QProcess *p;
    QString currentStr;
    QString currentPercent;
    QString totalTime;
    QString fileName;
};

#endif /* _H_QMPLAYER_ */
