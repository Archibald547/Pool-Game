#ifndef CONCRETETABLEBUILDER_H
#define CONCRETETABLEBUILDER_H
#include "tablebuilder.h"
#include "gamefactory.h"
#include "stage1factory.h"

/** @brief ConcreteTableBuilder class is the concrete builder class for object table.


    @author Archibald Weng
    @date April 2018
    */

class ConcreteTableBuilder: public TableBuilder
{
public:
    /**set the factory*/
    ConcreteTableBuilder(Stage1Factory *facotry):m_factory(facotry){}
    /**build a table from the facotry*/
    virtual void buildTable(){this->m_table = m_factory->createTable();}
    /**set the table's width*/
    virtual void buildWidth(int width){this->m_table->setWidth(width);}
    /**set the table's height*/
    virtual void buildHeight(int height){this->m_table->setHeight(height);}
    /**set the table'scolor*/
    virtual void buildBackgroundColor(QString color){this->m_table->setColor(color);}
    /**set the table's friction*/
    virtual void buildFriction(double friction){this->m_table->setFriction(friction);}
    /**get this table's pointer*/
    virtual Table* getTable(){return this->m_table;}


protected:
    GameFactory *m_factory;
    Table *m_table;
};

#endif // CONCRETETABLEBUILDER_H
