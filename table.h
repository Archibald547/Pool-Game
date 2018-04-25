#ifndef TABLE_H
#define TABLE_H
#include "QString"

/** @brief This is the class for table objects.


    @author Archibald Weng
    @date April 2018
    */

class Table
{
public:

    Table(QString color="blue",int width = 300, int height = 300, double friction = 0.2)
        :m_color(color),m_width(width),m_height(height),m_friction(friction){}
    ~Table(){delete this;}

    //getters
    QString getColor(){return m_color;}
    int getWidth(){return m_width;}
    int getHeight(){return m_height;}
    double getFriction(){return m_friction;}

    //setters
    void setColor(QString color){this->m_color=color;}
    void setWidth(int width){this->m_width=width;}
    void setHeight(int height){this->m_height=height;}
    void setFriction(double friction){this->m_friction=friction;}

private:
    QString m_color;
    int m_width;
    int m_height;
    double m_friction;
};

#endif // TABLE_H
