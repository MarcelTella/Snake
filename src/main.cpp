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
    int c;
    Board b(25, 25);

    namedWindow("Window HighGui Snake", 1);

    initscr();
    noecho();
    cbreak();
    timeout(50);

    bool gameOn = true;
    std::cout << "Instructions: Right(a), Left(d), Up(w), Down(s). Press q to exit. " << std::endl;
    char input;
    cin >> input;

    while(gameOn){
        b.plot();
        gameOn = b.iterate();
        waitKey(1);

        refresh();
        c = getch();
        if (c == KEYSTROKE_QUIT){
            return EXIT_SUCCESS;
        }
        else if (c == 'w' ){
            b.setUserGivenDirection(TOP);
        }
        else if (c == 's'){
            b.setUserGivenDirection(BOTTOM);
        }
        else if (c == 'a'){
            b.setUserGivenDirection(LEFT);
        }
        else if (c == 'd'){
            b.setUserGivenDirection(RIGHT);
        }

    }
    endwin();

    cout << "------------Game Over------------" << endl;
    return EXIT_SUCCESS;
}
