#ifndef GENERAL_H
#define GENERAL_H

#include <Eigen/Dense>

typedef Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> MatrixXb;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};
const int KEYSTROKE_QUIT = 113;
const char KEYSTROKE_UP = 'w';
const char KEYSTROKE_DOWN = 's';
const char KEYSTROKE_RIGHT = 'd';
const char KEYSTROKE_LEFT = 'a';

void showInstructions();
float levelSelection();
bool isAnyPossibleLevel(const int level);

#endif
