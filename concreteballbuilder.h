#ifndef CONCRETEBALLBUILDER_H
#define CONCRETEBALLBUILDER_H
#include "gamefactory.h"
#include "ballbuilder.h"
#include "stage1factory.h"

/** @brief ConcreteBallBuilder class is the concrete builder class for object ball.


    @author Archibald Weng
    @date April 2018
    */


class concreteBallBuilder: public BallBuilder
{
public:
    concreteBallBuilder(Stage1Factory *factory):m_factory(factory){}
    /**build a ball*/
    virtual void buildBall(){this->ball=m_factory->createBall();}
    /**set the ball's coordinate*/
    virtual void buildCoordinate(Coordinate c){this->ball->setCoordinate(c);}
    /**set the ball's color*/
    virtual void buildColor(QString color){this->ball->setColor(color);}
    /**set the ball's mass*/
    virtual void buildMass(double mass){this->ball->setMass(mass);}
    /**set the ball's radius*/
    virtual void buildRadius(int radius){this->ball->setRadius(radius);}
    /**set the ball's x velocity*/
    virtual void buildXVelocity(double xV){this->ball->setXVelocity(xV);}
     /**set the ball's y velocity*/
    virtual void buildYVelocity(double yV){this->ball->setYVelocity(yV);}
    /**return the ball built by this builder*/
    virtual Ball* getBall(){return this->ball;}

protected:
    Ball *ball;
    GameFactory *m_factory;
};

#endif // CONCRETEBALLBUILDER_H
