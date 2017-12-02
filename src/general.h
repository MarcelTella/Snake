#ifndef GENERAL_H
#define GENERAL_H

#include <Eigen/Dense>

typedef Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> MatrixXb;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};
const int KEYSTROKE_QUIT = 113;
const int KEYSTROKE_UP = 65;
const int KEYSTROKE_DOWN = 66;
const int KEYSTROKE_RIGHT = 67;
const int KEYSTROKE_LEFT = 68;

#endif
