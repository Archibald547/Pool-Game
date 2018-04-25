#include "ball.h"
#include <stdio.h>
#include <math.h>
#include <QColor>
#include <QVector2D>



Ball::~Ball()
{

}

void Ball::move(){
    m_coordinate.changeInXCoordinate(m_xVelocity);
    m_coordinate.changeInYCoordinate(m_yVelocity);
}

void Ball::render(QPainter &painter){
    painter.setPen ( Qt::black );
    painter.setBrush( QBrush( QColor(m_colour) ) );
    painter.drawEllipse(m_coordinate.getQtRenderingXCoordinate() - (int) m_radius,
        m_coordinate.getQtRenderingYCoordinate() -(int) m_radius,
        m_radius * 2,
        m_radius * 2);
}

void Ball::resolveWallCollision(){
    if (isYCollisionUp()){
        m_yVelocity = -abs(m_yVelocity);
    }
    else if (isYCollisionDown()){
        m_yVelocity = abs(m_yVelocity);
    }
    else if(isXCollisionLeft()){
        m_xVelocity = abs(m_xVelocity);
    }
    else if(isXCollisionRight()){
        m_xVelocity = -abs(m_xVelocity);
    }
}


bool Ball::isYCollisionUp(){
    return m_coordinate.getQtRenderingYCoordinate() - (signed int)m_radius<= 0;
}
bool Ball::isYCollisionDown(){
    return m_coordinate.getQtRenderingYCoordinate() >= (signed int) (m_coordinate.getFrameHeight() - (signed int) m_radius);
}
bool Ball::isXCollisionLeft(){
    return m_coordinate.getQtRenderingXCoordinate() - (signed int)m_radius <= 0;
}
bool Ball::isXCollisionRight(){
    return m_coordinate.getQtRenderingXCoordinate() >= (signed int) (m_coordinate.getFrameWidth() - (signed int) m_radius);
}

bool Ball::isBallCollision(Ball &ball){
    double xd = (double)m_coordinate.getQtRenderingXCoordinate() - (double)ball.m_coordinate.getQtRenderingXCoordinate();
    double yd = (double)m_coordinate.getQtRenderingYCoordinate() - (double)ball.m_coordinate.getQtRenderingYCoordinate();
    double sumRadius = m_radius + ball.getRadius();
    double sqrRadius = sumRadius * sumRadius;
    double distSqr = (xd * xd) + (yd * yd);
    if (distSqr <= sqrRadius)
        return true;
    return false;
}

void Ball::resolveCollision(Ball &ball){
    //Properties of two colliding balls,
    //ball A
    QVector2D posA =  QVector2D(m_coordinate.getXCoordinate(), m_coordinate.getYCoordinate());
    QVector2D velA =  QVector2D(m_xVelocity, m_yVelocity);
    float massA =  m_mass;
    //and ball B
    QVector2D posB =  QVector2D(ball.m_coordinate.getXCoordinate(),ball.m_coordinate.getYCoordinate());
    QVector2D velB =  QVector2D(ball.m_xVelocity,ball.m_yVelocity);
    float massB =  ball.m_mass;

    //calculate their mass ratio
    float mR = massB / massA;

    //calculate the axis of collision
    QVector2D collisionVector = posB - posA;
    collisionVector.normalize();

   //the proportion of each balls velocity along the axis of collision
    double vA = QVector2D::dotProduct(collisionVector, velA);
    double vB = QVector2D::dotProduct(collisionVector, velB);
    //the balls are moving away from each other so do nothing
    if (vA <= 0 && vB >= 0) {
     return;
    }

    //The velocity of each ball after a collision can be found by solving the quadratic equation
    //given by equating momentum and energy before and after the collision and finding the velocities
    //that satisfy this
    //-(mR+1)x^2 2*(mR*vB+vA)x -((mR-1)*vB^2+2*vA*vB)=0
    //first we find the discriminant
    double a = -(mR + 1);
    double b = 2 * (mR * vB + vA);
    double c = -((mR - 1) * vB * vB + 2 * vA * vB);
    double discriminant = sqrt(b * b - 4 * a * c);
    double root = (-b + discriminant)/(2 * a);
    //only one of the roots is the solution, the other pertains to the current velocities
    if (root - vB < 0.01) {
      root = (-b - discriminant)/(2 * a);
    }

    //The resulting changes in velocity for ball A and B
    QVector2D deltaVA = mR * (vB - root) * collisionVector;
    QVector2D deltaVB = (root - vB) * collisionVector;

    m_xVelocity = m_xVelocity+deltaVA.x();
    m_yVelocity = m_yVelocity+deltaVA.y();
    ball.setXVelocity(ball.getXVelocity()+ deltaVB.x());
    ball.setYVelocity(ball.getYVelocity()+ deltaVB.y());

}

void Ball::reverseDirection(){
    this->m_xVelocity = -m_xVelocity;
    this->m_yVelocity = -m_yVelocity;
}

void Ball::slowDown(double friction){
    this->m_xVelocity *= 1-0.1*friction;
    this->m_yVelocity *= 1-0.1*friction;
}
