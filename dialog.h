#ifndef DIALOG_H
#define DIALOG_H
#include "ball.h"
#include <QDialog>
#include <QPainter>
#include <QTimer>

/** @brief This Dialog class is for the visualization of the pool game.


    @author Archibald Weng
    @date April 2018
    */

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    /**add one ball to the visualization tool Dialog*/
    void addBall(Ball *b);
    /**set the friction to Dialog*/
    void setFriction(double friction=0.1){this->m_friction=friction;}

public slots:
    void nextFrame();
    void setBalls(std::vector<Ball*> balls);

protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::Dialog *ui;
    std::vector<Ball*> m_balls;
    double m_friction;
    int count;
};

#endif // DIALOG_H
