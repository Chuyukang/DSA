
class Point
{
    int x, y;

public:
    Point();
    Point(int _x, int _y);
    Point &operator=(Point p);
    void setX(int _x);
    void setY(int _y);
    void increaseX(int _dx);
    void increaseY(int _dy);
    int getX();
    int getY();
};