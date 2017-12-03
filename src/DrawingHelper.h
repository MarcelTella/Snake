#ifndef DRAWING_HELPER_H
#define DRAWING_HELPER_H

#include "Board.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;

class DrawingHelper
{
    public:
    static void plot(const Board& board);
    static Mat createBoardImage(const Board& board, const int multiplier=8);
    static void paintCell(Mat& board, const Position p, const int multiplier, const int value);
};

#endif // DRAWING_HELPER_H
