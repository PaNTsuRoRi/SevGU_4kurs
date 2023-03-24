#include <iostream>
#include <string>
#include <math.h>
#include "windows.h"
#include "ap.hpp"

using namespace std;

const int p = 199;
const int q = 337;
const int n = p * q; //67063
const int Fn = (p - 1) * (q - 1); //66528
const int e = 5;
const int k = 2;
const int d = (k * Fn + 1) / e;



string encrypt(string message) {
    long long int res;
    char* result = new char[message.length() + 1];
    for (int i = 0; i < message.length() + 1; i++) {
        res = pow(message[i], e);
        result[i] = (char)(res % n);
    }
    return result;
}

string decrypt(string message) {
    ap_int<512> res;
    int res1;
    char* result = new char[message.length() + 1];
    for (int i = 0; i < message.length()+1; i++) {
        res = 1;
        res1 = (int)message[i];
        for (int j = 0; j < d; j++) {
            res = res * res1;
        }
        res = res % n;
        result[i] = (char)res;
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
    message3 = decrypt(message2); //"Привет мир! Hello world!";
    cout << "Открытые ключи: e = " << e << "; n = " << n << endl;
    cout << "Зашифованное сообщение: " << endl;
    cout << message2 << endl;
    cout << "Секретные ключи: d = " << d << "; n = " << n << endl;
    cout << "Расшифрованное сообщение: " << endl;
    cout << message3;
    cin.get();
}