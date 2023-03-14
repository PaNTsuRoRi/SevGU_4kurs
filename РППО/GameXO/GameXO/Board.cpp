#include "Board.h"

using namespace std;

void Board::board1() {
    cout << " |-1-|-2-|-3-|" << endl;
    cout << " |-4-|-5-|-6-|" << endl;
    cout << " |-7-|-8-|-9-|" << endl;
}

void Board::game() {
    system("cls");
    int numMenu;

    cout << "1. Начать игру" << endl
         << "2. Выход" << endl
         << "\nВведите пункт меню: ";
    cin >> numMenu;

    switch (numMenu) {
    case 1:
        newGame();
        cout << "\nНажмите Enter чтобы вернется в главное меню" << endl;
        cin.get();
        cin.get();
        game();
        break;
    case 2:
        break;
    default:
        cout << "Вы ввели неправильный пункт меню" << endl;
        cout << "Нажмите Enter чтобы попробовать заново" << endl;
        cin.get();
        cin.get();
        game();
        break;
    }
}

void Board::newGame() {
    string name;
    Logic a1;

    bool k = true;
    int hod = 0; //счётчик ходов
    bool mark = true; //нужен для цикла
    char h1;  //хранит значение ячейки
    int m; //хранит введённое число
    int x; //для теста

    system("cls");
    cout << "Введите имя игрока 1" << endl;
    cin >> name;
    Nickname g1('X', name);
    cout << "Введите имя игрока 2" << endl;
    cin >> name;
    Nickname g2('O', name);
    system("cls");

    while (mark) {
        if (!k) {
            cout << "Ошибка при выборе ячейки! " << endl; k = true;
            cout << "\n";
        }
        board1();
        a1.printCell();
        cout << "Введите номер ячейки" << endl;

        if (hod % 2 == 0) {
            h1 = g1.getSymb();
            cout << "Ход игрока " << g1.getName() << ", ваш символ " << g1.getSymb() << endl;
        }
        else {
            h1 = g2.getSymb();
            cout << "Ход игрока " << g2.getName() << ", ваш символ " << g2.getSymb() << endl;
        }
        cin >> m;
        if (!isValidValueEntered()) {
            k = false;
        }
        if (!a1.setCell(m - 1, h1)) k = false;
        else {
            hod++;
            a1.setCell(m - 1, h1);
            x = a1.test();
            if (x != 0) {
                mark = false;
                hod--;
            }

        }
        system("cls");
    };

    a1.printCell();
    a1.printWin(x, hod, g1, g2);
}