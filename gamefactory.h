#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H
#include "ball.h"
#include "table.h"

/** @brief This is the abstract factory class in abstract factory method.


    @author Archibald Weng
    @date April 2018
    */


class GameFactory
{
public:
    GameFactory();
    /**creation of the table object*/
    virtual Table* createTable(){}
    /**creation of the ball object*/
    virtual Ball* createBall(){}
};

#endif // GAMEFACTORY_H
