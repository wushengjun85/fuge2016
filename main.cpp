#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QApplication::setOverrideCursor(Qt::BlankCursor);//隐藏鼠标 光标
    //QWSServer::setCursorVisible(false);
#if 1
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
QFont font  = a.font();
font.setFamily("unifont");
a.setFont(font);
#endif

    return a.exec();
}


//QT += sql
//LIBS += -L./hwlib -ldev
//LIBS += -L./hwlib -lat
