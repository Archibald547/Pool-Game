#ifndef BALLBUILDER_H
#define BALLBUILDER_H
#include "ball.h"

/** @brief Ballbuilder class is the abstract builder class for object ball.


    @author Archibald Weng
    @date April 2018
    */

class BallBuilder
{
public:
    /**build a ball*/
    virtual void buildBall(){}
    /**set the ball's coordinate*/
    virtual void buildCoordinate(Coordinate c){}
    /**set the ball's color*/
    virtual void buildColor(QString color){}
    /**set the ball's mass*/
    virtual void buildMass(double mass){}
    /**set the ball's radius*/
    virtual void buildRadius(int radius){}
    /**set the ball's x velocity*/
    virtual void buildXVelocity(double xV){}
    /**set the ball's y velocity*/
    virtual void buildYVelocity(double yV){}


protected:
    BallBuilder();
};

#endif // BALLBUILDER_H
