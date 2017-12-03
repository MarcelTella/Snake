#include "general.h"
#include "DrawingHelper.h"

void DrawingHelper::paintCell(Mat& board, const Position p, const int multiplier, const int value){
    for (int i=0; i<multiplier; i++){
        for (int j=0; j<multiplier; j++){
            // Note that the board goes by rows=y, cols=x.
            board.at<uchar>((p.y*multiplier)+j, (p.x*multiplier)+i) = value;
        }
    }
}

Mat DrawingHelper::createBoardImage(const Board& board, const int multiplier){
    int sizeX = board.getSizeX();
    int sizeY = board.getSizeY();
    Mat boardImage = Mat::zeros(multiplier*sizeX, multiplier*sizeY, CV_8UC1);

    Position food = board.getFood();
    DrawingHelper::paintCell(boardImage, food, multiplier, FOOD_LEVEL);

    queue<Position> snakePositions = board.getSnakePositions();
    for (int i=0; snakePositions.size(); i++){
        Position thisPosition = snakePositions.front();
        DrawingHelper::paintCell(boardImage, thisPosition, multiplier, SNAKE_LEVEL);
        snakePositions.pop();
    }

    return boardImage;
}

void DrawingHelper::plot(const Board& board){
    Mat image = DrawingHelper::createBoardImage(board);
    imshow(SNAKE_WINDOW_NAME, image);
}
