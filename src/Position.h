#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int x;
    int y;
    Position(){ x = 0; y = 0;}
    Position(const int& xVal, const int& yVal){ x = xVal; y = yVal;}
    bool operator==(const Position p) const{ return (p.x == x) && (p.y == y); }
};

#endif // POSITION_H
