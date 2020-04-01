#include "Point.h"

Point::Point(){}
Point::Point(int _x,int _y){
    x = _x; y = _y;
}
Point& Point::operator=(Point p){
    x = p.getX(); y = p.getY();
}
void Point::setX(int _x){ x = _x; }
void Point::setY(int _y){ y = _y; }
void Point::increaseX(int _dx){ x += _dx; }
void Point::increaseY(int _dy){ y += _dy; }
int Point::getX(){ return x; }
int Point::getY(){ return y; }