#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include "Board.h"

using namespace std;

HANDLE hConsole;

void test() {
    cout << "Тест 1" << endl;
    cout << "&Logic logic;" << endl;
    Logic logic;
    cout << "&Board board;" << endl;
    Board board;
    cout << "&Nickname nickname1 = Nickname('O', \"Игрок1\");" << endl;
    Nickname nickname1 = Nickname('O', "Игрок1");
    cout << "&Nickname nickname2 = Nickname('X', \"Игрок2\");" << endl;
    Nickname nickname2 = Nickname('X', "Игрок2");
    cout << "&cout << nickname1.getName();" << endl;
    cout << nickname1.getName();
    cout << "\n&cout << nickname1.getSymb();" << endl;
    cout << nickname1.getSymb();
    cout << "\n&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.setCell(0, nickname1.getSymb());" << endl;
    logic.setCell(0, nickname1.getSymb());
    cout << "&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.setCell(1, nickname2.getSymb());" << endl;
    logic.setCell(1, nickname2.getSymb());
    cout << "&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.setCell(3, nickname1.getSymb());" << endl;
    logic.setCell(3, nickname1.getSymb());
    cout << "&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.setCell(2, nickname2.getSymb());" << endl;
    logic.setCell(2, nickname2.getSymb());
    cout << "&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.setCell(6, nickname1.getSymb());" << endl;
    logic.setCell(6, nickname1.getSymb());
    cout << "&logic.printCell();" << endl;
    logic.printCell();
    cout << "&logic.printWin(2, 6, nickname1, nickname2);" << endl;
    logic.printWin(2, 6, nickname1, nickname2);
    cin.get();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Board board;
    board.game();

    //test();
}