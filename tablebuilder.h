#ifndef TABLEBUILDER_H
#define TABLEBUILDER_H
#include "QString"

/** @brief Tablebuilder class is the abstract builder class for object table.


    @author Archibald Weng
    @date April 2018
    */

class TableBuilder
{
public:
    /**build a table*/
    virtual void buildTable(){}
    /**set the table's width*/
    virtual void builWidth(int width){}
    /**set the table's height*/
    virtual void buildHeight(int height){}
    /**set the table'scolor*/
    virtual void buildBackgroundColor(QString color){}
    /**set the table's friction*/
    virtual void buildFriction(double friction){}

protected:
    TableBuilder();
};

#endif // TABLEBUILDER_H
