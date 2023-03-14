#include "Logic.h"
#include "Nickname.h"
#include <iostream>

using namespace std;

bool Logic::setCell(int a, char s) //заполнение ячейки символами 'X' или 'O'
{
    if ((a >= 0) && (a < 9) && ((s == 'X') || (s == 'O')) && (cel[a] != 'X') && (cel[a] != 'O')) {
        cel[a] = s;
        return true;
    }
    return false;
}
char Logic::getCell(int a) //возращение значения ячейки с номером a
{
    return cel[a];
}
int Logic::test() //проверка на завершение игры, где 1 - ничья, 2 - победа, 0 - игры не завершена
{
    int t0, t1, t2;
    bool flag = false;
    for (int i = 0; i < 8; i++)
    {
        t0 = wins[i][0]; t1 = wins[i][1]; t2 = wins[i][2];
        if ((cel[t0] == cel[t1]) && (cel[t2] == cel[t1]) && ((cel[t0] == 'X') || (cel[t0] == 'O'))) return 2;
    }
    for (int i = 0; i < 9; i++) {
        if (cel[i] == ' ')  flag = true;
    }
    if (!flag) return 1;
    return 0;
}

void Logic::printCell() { //вывод поля на экран
    cout << "\n";
    for (int i = 0; i < 9; i++) {

        cout << "| " << cel[i] << " |";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
    cout << "\n";
}
void Logic::printWin(int x, int hod, Nickname g1, Nickname g2) {
    switch (x) {
    case 1:
        cout << "Игра окончена! Ничья!" << endl;
        break;
    case 2:
        if (hod % 2 == 0) cout << "Игра окончена! Победил " << g1.getName() << endl;
        else cout << "Игра окончена! Победил " << g2.getName() << endl;
        break;
    }
 }
