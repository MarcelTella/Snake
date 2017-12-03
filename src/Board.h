#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
#include "Position.h"
#include "Snake.h"
#include "general.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace Eigen;
using namespace cv;

const int FOOD_LEVEL = 128;
const int SNAKE_LEVEL = 255;

class Board
{
    int _sizeX;
    int _sizeY;
    Position _food;
    Snake _s;
    Direction _dir;

    public:
    Board(const int& sizeX, const int& sizeY);
    Position getNext(const Direction dir, const Position pos) const;
    bool isNextFood(const Position& head, const Direction dir) const;
    void print();
    Position getFood() const{ return _food; }
    void plot() const;
    bool iterate();
    void setUserGivenDirection(const Direction& d);
    bool processKeystroke(const int keyPressed);

    private:
    void generateFood();
    Position generateRandomFood() const;
    Position advanceLeft(const Position pos) const;
    Position advanceRight(const Position pos) const;
    Position advanceTop(const Position pos) const;
    Position advanceBottom(const Position pos) const;
    Position createFood() const;

    Mat createBoardImage(const int multiplier=8) const;
    void paintCell(Mat& board, const Position p, const int multiplier, const int value) const;


};

#endif // BOARD_H
