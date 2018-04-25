#ifndef STAGE1FACTORY_H
#define STAGE1FACTORY_H
#include "gamefactory.h"

/** @brief This is the concrete factory class in abstract factory method.


    @author Archibald Weng
    @date April 2018
    */

class Stage1Factory: public GameFactory
{
public:
    Stage1Factory();
    /**creation of the table object*/
    Table* createTable(){m_table=new Table();return this->m_table;}
    /**creation of the ball object*/
    Ball* createBall(){m_ball=new Ball();return this->m_ball;}

protected:
    Table* m_table;
    Ball* m_ball;
};

#endif // STAGE1FACTORY_H
