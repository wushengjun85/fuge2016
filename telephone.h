#ifndef TELEPHONE_H
#define TELEPHONE_H

#include <QDialog>

namespace Ui {
class Telephone;
}

class Telephone : public QDialog
{
    Q_OBJECT
    
public:
    explicit Telephone(QWidget *parent = 0);
    ~Telephone();
    
private slots:


    //void on_pushButton_3_clicked();

   // void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Telephone *ui;

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // TELEPHONE_H
