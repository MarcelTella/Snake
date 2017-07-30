#include <queue>
#include "Snake.h"
#include "Position.h"
#include "Board.h"

using namespace std;

Snake::Snake()
{
    _body.push(Position(3, 3));
    _body.push(Position(3, 4));
    _body.push(Position(3, 5));
}


void Snake::grow(const Position& food){
    _body.push(food);
}


bool Snake::advance(Board& board, const Direction dir){

    Position head = getHeadPosition();

    Position next = board.getNext(dir, head);

    if (amIDead()){
        return false;
    }

    if (board.isNextFood(head, dir)){
        grow(next);
        board.generateFood();
    }
    else{
        _body.push(next);
        _body.pop();
    }

    return true;
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

Position& Snake::getHeadPosition(){
    return _body.back();
}

