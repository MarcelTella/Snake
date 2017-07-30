#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
#include "Position.h"

using namespace Eigen;

typedef Matrix<bool, Dynamic, Dynamic> MatrixXb;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};

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
    Position getFood(){ return _food; }

    private:
    Position advanceLeft(const Position pos) const;
    Position advanceRight(const Position pos) const;
    Position advanceTop(const Position pos) const;
    Position advanceBottom(const Position pos) const;
    Position createFood() const;

};

#endif // BOARD_H
