#ifndef SNAKE_H
#define SNAKE_H

#include <queue>
#include "Position.h"
#include "Board.h"
using namespace std;

class Snake
{
    queue<Position> _body;

    public:
    Snake();

    void grow(const Position& food);
    bool advance(Board& b, const Direction dir);
    bool amIDead();

    Position& getHeadPosition();
    int length() const {return _body.size();}
};

#endif // SNAKE_H
