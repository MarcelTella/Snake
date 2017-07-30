#include <iostream>
#include "Board.h"
using namespace std;

Board::Board(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}


MatrixXb Board::print()
{
    MatrixXb board(_sizeX, _sizeY);
    cout << board << endl;
}
