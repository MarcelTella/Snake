#ifndef POSITION_H
#define POSITION_H

#include <iostream>
using namespace std;

struct Position
{
    int x;
    int y;
    Position(){ x = 0; y = 0;}
    Position(const int& xVal, const int& yVal){ x = xVal; y = yVal;}
    bool operator==(const Position p) const{ return (p.x == x) && (p.y == y); }
    friend ostream& operator << (ostream& o, const Position p){ o << p.x << " " << p.y << endl;}
};

#endif // POSITION_H
