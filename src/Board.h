#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
using namespace Eigen;

typedef Matrix<bool, Dynamic, Dynamic> MatrixXb;

class Board
{
    int _sizeX;
    int _sizeY;

    public:
    Board(int sizeX, int sizeY);
    MatrixXb print();
};

#endif // BOARD_H
