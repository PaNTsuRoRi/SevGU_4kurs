#pragma once
#include "Nickname.h"

class Logic {
private:
    char cel[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
public:
    int wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
    bool setCell(int a, char s);
    char getCell(int a);
    int test();
    void printCell();
    void printWin(int x, int hod, Nickname g1, Nickname g2);
};