#ifndef GENERAL_H
#define GENERAL_H

#include <Eigen/Dense>
#include <string>

using namespace std;

typedef Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> MatrixXb;
enum Direction{LEFT, RIGHT, TOP, BOTTOM};

const int BOARD_SIZE = 25;
const float DEFAULT_SPEED_FIRST_LEVEL = 200; // ms per time unit

const int KEYSTROKE_QUIT = 113;
const char KEYSTROKE_UP = 'w';
const char KEYSTROKE_DOWN = 's';
const char KEYSTROKE_RIGHT = 'd';
const char KEYSTROKE_LEFT = 'a';

const string SNAKE_WINDOW_NAME = "Snake";

void showInstructions();
float levelSelection();
bool isAnyPossibleLevel(const int level);
void configureKeystrokeCapturing();
void gameOver();
#endif
