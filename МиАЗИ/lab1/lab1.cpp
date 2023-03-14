#include <iostream>
#include <string>
#include <vector>
#include "windows.h"

using namespace std;

char 
    alfis[34]{ 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П',
               'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ь', 'Ы', 'Э', 'Ю', 'Я', ' ' },
    alfp1[34]{ 'Б', 'Ю', 'Г', 'Ы', 'Е', 'Ь', 'З', 'Ш', 'Й', 'Ц', 'Л', 'Ф', 'Н', 'Т', 'П', 'Р', 'С',
               'О', 'У', 'М', 'Х', 'К', 'Ч', 'И', 'Щ', 'Ж', 'Ъ', 'Д', 'Э', 'В', 'Я', ' ', 'А', 'Ё' },
    alfp2[34]{ 'О', 'П', 'М', 'Н', 'Х', 'Л', 'И', 'Й', 'Ж', 'З', 'Д', 'Е', 'В', 'Г', 'А', 'Б', 'Ю',
               'Я', 'Ы', 'Э', 'Ь', ' ', 'Ш', 'Щ', 'Ц', 'Ч', 'Ф', 'К', 'Т', 'У', 'Р', 'С', 'Ъ', 'Ё' };

string ecrypt(string message) {
    string ecrmessage;
    char sym;
    for (int i = 0; i < message.size(); i++) {
        sym = message[i];
        for (int j = 0; j < 34; j++) {
            if (sym == alfis[j]) {
                if (i % 4 == 0 || i % 4 == 1)
                    ecrmessage.push_back(alfp1[j]);
                else
                    ecrmessage.push_back(alfp2[j]);
                break;
            }
        }
    }
    return ecrmessage;
}

string decrypt(string message) {
    string decrmessage;
    char sym;
    for (int i = 0; i < message.size(); i++) {
        sym = message[i];
        for (int j = 0; j < 34; j++) {
            if (i % 4 == 0 || i % 4 == 1) {
                if (sym == alfp1[j]) {
                    decrmessage.push_back(alfis[j]);
                    break;
                }
            }
            else {
                if (sym == alfp2[j]) {
                    decrmessage.push_back(alfis[j]);
                    break;
                }
            }
        }
    }
    return decrmessage;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string message, message1, message2;
    cout << "Введите сообщение (в верхнем регистре): " << endl;
    getline (cin, message);
    message1 = ecrypt(message);
    message2 = decrypt(message1);
    cout << "\nЗашифрованная строка:\n" << message1 << endl;
    cout << "\nРасшифрованная строка:\n" << message2 << endl;
}