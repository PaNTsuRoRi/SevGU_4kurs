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

    cout << "1. ������ ����" << endl
         << "2. �����" << endl
         << "\n������� ����� ����: ";
    cin >> numMenu;

    switch (numMenu) {
    case 1:
        newGame();
        cout << "\n������� Enter ����� �������� � ������� ����" << endl;
        cin.get();
        cin.get();
        game();
        break;
    case 2:
        break;
    default:
        cout << "�� ����� ������������ ����� ����" << endl;
        cout << "������� Enter ����� ����������� ������" << endl;
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
    int hod = 0; //������� �����
    bool mark = true; //����� ��� �����
    char h1;  //������ �������� ������
    int m; //������ �������� �����
    int x; //��� �����

    system("cls");
    cout << "������� ��� ������ 1" << endl;
    cin >> name;
    Nickname g1('X', name);
    cout << "������� ��� ������ 2" << endl;
    cin >> name;
    Nickname g2('O', name);
    system("cls");

    while (mark) {
        if (!k) {
            cout << "������ ��� ������ ������! " << endl; k = true;
            cout << "\n";
        }
        board1();
        a1.printCell();
        cout << "������� ����� ������" << endl;

        if (hod % 2 == 0) {
            h1 = g1.getSymb();
            cout << "��� ������ " << g1.getName() << ", ��� ������ " << g1.getSymb() << endl;
        }
        else {
            h1 = g2.getSymb();
            cout << "��� ������ " << g2.getName() << ", ��� ������ " << g2.getSymb() << endl;
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