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

using namespace std;
using namespace Eigen;
using namespace cv;

Board::Board(const int& sizeX, const int& sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    generateFood();
    _s = Snake();
    _dir = TOP;
}

void Board::print()
{
    MatrixXb board(_sizeX, _sizeY);
    board(_food.x, _food.y) = true;
    cout << board << endl;
}

Position Board::getNext(const Direction dir, const Position pos) const {
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

    if (next == _food){
        return true;
    }
    return false;
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

Mat Board::createBoardImage(const int multiplier) const{
    Mat boardImage = Mat::zeros(multiplier*_sizeX, multiplier*_sizeY, CV_8UC1);

    Position food = getFood();
    paintCell(boardImage, food, multiplier, FOOD_LEVEL);

    queue<Position> snakePositions = _s.getPositions();
    for (int i=0; snakePositions.size(); i++){
        Position thisPosition = snakePositions.front();
        paintCell(boardImage, thisPosition, multiplier, SNAKE_LEVEL);
        snakePositions.pop();
    }

    return boardImage;
}

void Board::paintCell(Mat& board, const Position p, const int multiplier, const int value) const{
    for (int i=0; i<multiplier; i++){
        for (int j=0; j<multiplier; j++){
            // Note that the board goes by rows=y, cols=x.
            board.at<uchar>((p.y*multiplier)+j, (p.x*multiplier)+i) = value;
        }
    }
}

void Board::plot() const{
    Mat image = createBoardImage();
    imshow("Window HighGui Snake", image);
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
