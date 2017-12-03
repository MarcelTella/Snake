#include <iostream>
#include <Eigen/Dense>
#include "Position.h"
#include "Maths.h"
#include "Board.h"
#include "Snake.h"
#include <queue>
#include "general.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <ncurses.h>
#include <queue>
#include "DrawingHelper.h"

using namespace std;
using namespace Eigen;
using namespace cv;

Board::Board(const int& sizeX, const int& sizeY){
    _sizeX = sizeX;
    _sizeY = sizeY;
    generateFood();
    _s = Snake();
    _dir = TOP;
}

Position Board::getNext(const Direction dir, const Position& pos) const {
    Position newPos;
    switch (dir) {
        case LEFT: newPos = advanceLeft(pos);
            break;
        case RIGHT: newPos = advanceRight(pos);
            break;
        case TOP: newPos = advanceTop(pos);
            break;
        case BOTTOM: newPos = advanceBottom(pos);
            break;
    }

    return newPos;
}

bool Board::isNextFood(const Position& head, const Direction dir) const{
    Position next = getNext(dir, head);
    return (next == _food);
}

Position Board::advanceLeft(const Position pos) const {
    int newX = modulo(pos.x-1, _sizeX);
    Position newPosition(newX, pos.y);
    return newPosition;
}

Position Board::advanceRight(const Position pos) const {
    int newX = modulo(pos.x+1, _sizeX);
    Position newPosition(newX, pos.y);
    return newPosition;
}

Position Board::advanceTop(const Position pos) const {
    int newY = modulo(pos.y-1, _sizeY);
    Position newPosition(pos.x, newY);
    return newPosition;
}

Position Board::advanceBottom(const Position pos) const {
    int newY = modulo(pos.y+1, _sizeY);
    Position newPosition(pos.x, newY);
    return newPosition;
}

Position Board::generateRandomFood() const{
    int x = rand() % _sizeX;
    int y = rand() % _sizeY;
    return Position(x, y);
}

Position Board::createFood() const{
    Position food = generateRandomFood();
    while(_s.overFood(food)){
        food = generateRandomFood();
    }
    return food;
}

bool Board::iterate(){
    Position head = _s.getHeadPosition();
    Position next = getNext(_dir, head);

    if (_s.amIDead()){
        return false;
    }

    if (isNextFood(head, _dir)){
        _s.grow(next);
        generateFood();
    }
    else{
        _s.advance(next);
    }

    return true;
}

void Board::generateFood(){
    _food = createFood();
}

void Board::setUserGivenDirection(const Direction& d){
    if (!(d == TOP && _dir == BOTTOM) &&
        !(d == BOTTOM && _dir == TOP) &&
        !(d == LEFT && _dir == RIGHT) &&
        !(d == RIGHT && _dir == LEFT))
        _dir = d;
}

bool Board::processKeystroke(const int keyPressed){
    if (keyPressed == KEYSTROKE_QUIT){
        return EXIT_FAILURE;
    }
    else if (keyPressed == KEYSTROKE_UP ){
        setUserGivenDirection(TOP);
    }
    else if (keyPressed == KEYSTROKE_DOWN){
        setUserGivenDirection(BOTTOM);
    }
    else if (keyPressed == KEYSTROKE_LEFT){
        setUserGivenDirection(LEFT);
    }
    else if (keyPressed == KEYSTROKE_RIGHT){
        setUserGivenDirection(RIGHT);
    }

    return EXIT_SUCCESS;
}

bool Board::iterateAndDraw(){
    bool gameOn;
    gameOn = iterate();
    DrawingHelper::plot(*this);
    waitKey(1); // Visualization update

    refresh(); // Keystroke capturing system
    return gameOn;
}

queue<Position> Board::getSnakePositions() const{
    return _s.getPositions();
}

int Board::getSizeX() const{
    return _sizeX;
}

int Board::getSizeY() const{
    return _sizeY;
}
