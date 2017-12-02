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
    Board b(25, 25);

    showInstructions();
    float timeoutTime = levelSelection();

    int c;
    namedWindow("Window HighGui Snake", 1);
    initscr();
    noecho();
    timeout(timeoutTime);

    bool gameOn = true;
    while(gameOn){
        b.plot();
        gameOn = b.iterate();
        waitKey(1);

        refresh();
        c = getch();
        gameOn = gameOn && !processKeystroke(b);
    }
    endwin();

    cout << "------------Game Over------------" << endl;
    return EXIT_SUCCESS;
}
