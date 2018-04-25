#ifndef BALL_H
#define BALL_H

#include "coordinate.h"
#include <QPainter>

/** @brief Ball class used for store the info of ball json objects. It contains basic setters, getters and methods that detect and resolve
 *  wall-collison and balls-collisons.


    @author Archibald Weng
    @date April 2018
    */

class Ball
{

public:
    //Ball constructor
    Ball(QString colour = "yellow",
        Coordinate coordinate = Coordinate(1,1,1,1),
        unsigned int radius = 10,
        double mass = 1,
        double xVelocity = 0,
        double yVelocity = 0)
        :m_colour(colour),
         m_coordinate(coordinate),
         m_radius(radius),
         m_mass(mass),
         m_xVelocity(xVelocity),
         m_yVelocity(yVelocity){
    }

    ~Ball();

    /**move the ball's position base on its velocity*/
    void move();
    /**&display the ball itself on the dialog*/
    void render(QPainter &painter);
    /**check if the ball is touching the north wall*/
    bool isYCollisionUp();
    /**check if the ball is touching the south wall*/
    bool isYCollisionDown();
    /**check if the ball is touching the west wall*/
    bool isXCollisionLeft();
    /**check if the ball is touching the east wall*/
    bool isXCollisionRight();
    /**change the ball's direction if it is touching any wall*/
    void resolveWallCollision();
    /**check if the ball is colliding with another ball b*/
    bool isBallCollision(Ball &b);
    /**resolve the balls collision by changing both of the balls' directions and velocity based on physics*/
    void resolveCollision(Ball &b);
    /**simply reverse this ball's direction*/
    void reverseDirection();
    /**slows the ball down due to the friction of the table*/
    void slowDown(double friction);

    //getters
    QString getColor(){return m_colour;}
    Coordinate getCoordinate(){return m_coordinate;}
    unsigned int getRadius(){return m_radius;}
    double getMass(){return m_mass;}
    double getXVelocity(){return m_xVelocity;}
    double getYVelocity(){return m_yVelocity;}

    //setters
    void setColor(QString color){m_colour=color;}
    void setXVelocity(double xV){m_xVelocity=xV;}
    void setYVelocity(double yV){m_yVelocity=yV;}
    void setMass(double mass){m_mass=mass;}
    void setCoordinate(Coordinate c){m_coordinate=c;}
    void setRadius(unsigned int radius){m_radius=radius;}

private:
    QString m_colour;
    Coordinate m_coordinate;
    unsigned int m_radius;
    double m_mass;
    double m_xVelocity;
    double m_yVelocity;
};

#endif // BALL_H
