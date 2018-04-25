#ifndef COORDINATE_H
#define COORDINATE_H
#include <stdlib.h>

/** @brief Coordinate class is for ball class to have a convienent way to store its position info.


    @author Archibald Weng
    @date April 2018
    */

class Coordinate
{
public:
    Coordinate();
    Coordinate(unsigned
        int xCoordinate,
        unsigned int yCoordinate,
        unsigned int frameWidth,
        unsigned int frameHeight)
        :m_xCoordinate(xCoordinate),
         m_yCoordinate(yCoordinate),
         m_frameWidth(frameWidth),
         m_frameHeight(frameHeight){
    }

    ~Coordinate();
    /**return the X coordinate in Qt rendering version*/
    int getQtRenderingXCoordinate();
    /**return the Y coordinate in Qt rendering version*/
    int getQtRenderingYCoordinate();

    /**change the X coordinate with 'change' parameter*/
    void changeInXCoordinate(int change);
    /**change the Y coordinate with 'change' parameter*/
    void changeInYCoordinate(int change);
    /**set Y coordinate to zere*/
    void setYCoordinateToZero(int offset);

    unsigned int getXCoordinate(){return m_xCoordinate;}
    unsigned int getYCoordinate(){return m_yCoordinate;}
    unsigned int getFrameHeight(){return m_frameHeight;}
    unsigned int getFrameWidth(){return m_frameWidth;}

    void setXCoordinate(unsigned int x){m_xCoordinate=x;}
    void setYCoordinate(unsigned int y){m_yCoordinate=y;}


private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_frameWidth;
    unsigned int m_frameHeight;
};

#endif // COORDINATE_H
