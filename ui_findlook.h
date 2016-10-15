/********************************************************************************
** Form generated from reading UI file 'findlook.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDLOOK_H
#define UI_FINDLOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FindLook
{
public:
    QPushButton *pushButton;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *FindLook)
    {
        if (FindLook->objectName().isEmpty())
            FindLook->setObjectName(QString::fromUtf8("FindLook"));
        FindLook->resize(1024, 600);
        pushButton = new QPushButton(FindLook);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(950, 550, 51, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/imagejy/back.png);"));
        lcdNumber = new QLCDNumber(FindLook);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(20, 570, 101, 31));
        lcdNumber->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setDigitCount(8);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2 = new QLCDNumber(FindLook);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(0, 540, 141, 31));
        lcdNumber_2->setAutoFillBackground(false);
        lcdNumber_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lcdNumber_2->setFrameShape(QFrame::NoFrame);
        lcdNumber_2->setSmallDecimalPoint(false);
        lcdNumber_2->setNumDigits(10);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        pushButton_2 = new QPushButton(FindLook);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(557, 405, 39, 27));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"border-image: url(:/new/prefix1/imagejy/licheng.png);"));
        label = new QLabel(FindLook);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(603, 408, 83, 30));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 italic 18pt \"Ubuntu\";"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(FindLook);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(807, 408, 83, 30));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 italic 18pt \"Ubuntu\";"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(FindLook);

        QMetaObject::connectSlotsByName(FindLook);
    } // setupUi

    void retranslateUi(QDialog *FindLook)
    {
        FindLook->setWindowTitle(QApplication::translate("FindLook", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("FindLook", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FindLook", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FindLook: public Ui_FindLook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDLOOK_H
