#include "coordinate.h"

Coordinate::Coordinate()
{

}

Coordinate::~Coordinate()
{

}

int Coordinate::getQtRenderingXCoordinate()
{
    return m_xCoordinate;
}

int Coordinate::getQtRenderingYCoordinate()
{
    return m_frameHeight - m_yCoordinate;
}

void Coordinate::changeInXCoordinate(int change){
    m_xCoordinate += change;
}

void Coordinate::changeInYCoordinate(int change){
    m_yCoordinate += change;
}

void Coordinate::setYCoordinateToZero(int offset){
    m_yCoordinate = offset;
}
