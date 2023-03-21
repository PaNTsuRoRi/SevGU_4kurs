#include <iostream>
#include <string>
#include <math.h>
#include "windows.h"

using namespace std;

const int p = 199;
const int q = 337;
const int n = p * q; //67063
const int Fn = (p - 1) * (q - 1); //66528
const int e = 13;
const int k = 2;
const int d = (k * Fn + 1) / e;

string encrypt(string message) {
    int res;
    char* result = new char[message.length()+1];
    for (int i = 0; i < message.length(); i++) {
        res = pow(result[i], e);
        result[i] = (char)(res % n);
    }
    return result;
}

string decrypt(string message) {
    int res;
    char* result = new char[message.length() + 1];
    for (int i = 0; i < message.length(); i++) {
        res = pow(result[i], d);
        result[i] = res % n;
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string message1, message2, message3;
    cout << "Введите сообщение:" << endl;
    getline(cin, message1);
    message2 = encrypt(message1);
    message3 = decrypt(message2);
    cout << "Открытые ключи: e = " << e << "; n = " << n << endl;
    cout << "Зашифованное сообщение: " << endl;
    cout << message2 << endl;
    cout << "Секретные ключи: d = " << d << "; n = " << n << endl;
    cout << "Расшифрованное сообщение: " << endl;
    cout << message3;
    cin.get();
}