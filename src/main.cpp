#include <iostream>
#include <Eigen/Dense>
#include "Board.h"
#include "Snake.h"
#include "general.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

using namespace Eigen;
using namespace std;

int main(){
    Board b(BOARD_SIZE, BOARD_SIZE);

    showInstructions();
    float timeoutTime = levelSelection();

    // Timeout must be done in the main.
    configureKeystrokeCapturing();
    timeout(timeoutTime);

    bool gameOn = true;
    int keyPressed;
    while(gameOn){
        b.iterateAndDraw();
        keyPressed = getch();
        gameOn = gameOn && !b.processKeystroke(keyPressed);
    }
    endwin();

    gameOver();
    return EXIT_SUCCESS;
}
