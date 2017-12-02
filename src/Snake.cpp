#include <queue>
#include "Snake.h"
#include "Position.h"
#include "Board.h"
#include "general.h"

using namespace std;

Snake::Snake()
{
    _body.push(Position(3, 3));
    _body.push(Position(4, 3));
    _body.push(Position(5, 3));
}

void Snake::grow(const Position& food){
    _body.push(food);
}

bool Snake::overFood(const Position foodPosition) const{
    queue<Position> snakePositions = getPositions();
    for (int i=0; snakePositions.size(); i++){
        Position thisPosition = snakePositions.front();
        if (thisPosition == foodPosition) return true;
        snakePositions.pop();
    }
    return false;
}

void Snake::advance(const Position& next){
    _body.push(next);
    _body.pop();
}

bool Snake::amIDead(){
    Position head = getHeadPosition();

    queue<Position> copyQueue = _body;
    int queueLengthNoHead = copyQueue.size()-1;

    for(int i=1; i<queueLengthNoHead; i++){
        if (copyQueue.front() == head){
            return true;
        }
        copyQueue.pop();
    }
    return false;
}

Position Snake::getHeadPosition(){
    return _body.back();
}

queue<Position> Snake::getPositions() const{
    return _body;
}
