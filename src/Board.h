#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
#include "Position.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace Eigen;
using namespace cv;

typedef Matrix<bool, Dynamic, Dynamic> MatrixXb;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};

const int FOOD_LEVEL = 128;
const int SNAKE_LEVEL = 255;

class Board
{
    int _sizeX;
    int _sizeY;
    Position _food;

    public:
    Board(const int& sizeX, const int& sizeY);
    Position getNext(const Direction dir, const Position pos) const;
    bool isNextFood(const Position& head, const Direction dir) const;
    void print();
    void generateFood();
    Position getFood() const{ return _food; }
    //void plot() const;

    private:
    Position advanceLeft(const Position pos) const;
    Position advanceRight(const Position pos) const;
    Position advanceTop(const Position pos) const;
    Position advanceBottom(const Position pos) const;
    Position createFood() const;
    Mat createBoardImage() const;
};

#endif // BOARD_H
