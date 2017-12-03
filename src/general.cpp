#include <iostream>
#include "general.h"
#include <ncurses.h>
#include "Board.h"

using namespace std;

void showInstructions(){
    cout << "Instructions: Right(a), Left(d), Up(w), Down(s). Press q to exit." << endl;
    cout << "Note: Click in the terminal to take control of the snake." << endl;
}

bool isAnyPossibleLevel(const int level){
    return (level == 1 || level == 2 || level==3 || level==4);
}

float levelSelection(){
    cout << "Choose the difficulty level 1, 2, 3 or 4: ";
    float defaultSpeedFirstLevel = 200; // ms per time unit
    while(true){
        int level;
        cin >> level;

        if (isAnyPossibleLevel(level)){
            return defaultSpeedFirstLevel/level;
            break;
        }

        cout << endl << "Wrong input.";
    }
}
