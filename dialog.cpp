#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_balls({})
{
    ui->setupUi(this);
    this->resize(1000, 600);
    this->setStyleSheet("background-color: #82CAFF;");
}

void Dialog::addBall(Ball *b){
     m_balls.push_back(b);
}

void Dialog::setBalls(std::vector<Ball *> balls){
     this->m_balls=balls;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::nextFrame()
{
    update();
}

void Dialog::paintEvent(QPaintEvent *event)
{

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));

    //frame rate 1000/80
    timer->start(80);

    QPainter painter(this);
    QString warning = "Colliding!";

    //solve balls collision and wall collision
    for (int i=0;i<(int)m_balls.size();i++){
        m_balls[i]->resolveWallCollision();
        for(int j=i+1;j<(int)m_balls.size();j++){
            if(m_balls[i]->isBallCollision(*m_balls[j])&&i!=j){
                qWarning() << warning;
                qWarning() << count;
                count++;
                m_balls[i]->resolveCollision(*m_balls[j]);
            }
        }
    }

    //move the balls and slow them down due to friction
    for (auto & b: m_balls){
        b->move();
        b->render(painter);
        b->slowDown(m_friction);
    }

}
