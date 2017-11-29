#include <iostream>
#include <Eigen/Dense>
#include "Board.h"
#include "Position.h"
#include "Maths.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace Eigen;
using namespace cv;

Board::Board(const int& sizeX, const int& sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    generateFood();
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

bool Board::isNextFood(const Position& head, const Direction dir) const{
    Position next = getNext(dir, head);

    if (next == _food){
        return true;
    }
    return false;
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

Position Board::createFood() const{
    int x = rand() % _sizeX;
    int y = rand() % _sizeY;

    // Case snake is over it.
    return Position(x, y);
}

void Board::generateFood(){
    _food = createFood();
}

Mat Board::createBoardImage() const{
    //cout << _sizeX << endl;
    //cv::Mat board = cv::Mat::zeros(_sizeX, _sizeY, CV_8UC3);
    Mat bo;
    bo = Mat::zeros(500, 500, CV_32F);

    //Position food = getFood();
    //board.at<uchar>(food.x, food.y) = FOOD_LEVEL;

    return bo;
}

/*
void Board::plot() const{
    Mat image = createBoardImage();
    imshow("Snake", image);
}
*/
