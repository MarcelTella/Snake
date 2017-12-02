#ifndef SNAKE_H
#define SNAKE_H

#include <queue>
#include "Position.h"
//#include "Board.h"
#include "general.h"

using namespace std;

class Snake
{
    queue<Position> _body;

    public:
    Snake();

    void grow(const Position& food);
    bool overFood(const Position foodPosition) const;
    bool amIDead();
    void advance(const Position& next);

    Position getHeadPosition();
    int length() const {return _body.size();}
    queue<Position> getPositions() const;
};

#endif // SNAKE_H
