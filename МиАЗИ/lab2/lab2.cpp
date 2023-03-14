#include <iostream>
#include <string>
#include <vector>
#include "windows.h"

using namespace std;

const int A = 6;
const int C = 4;
const int b = 8;
const int T0 = 8;
const int M = pow(2, b);

int gamma(int T) {
    return (A * T + C) % M;
}

int sumOne(unsigned char sym) {
    int result = 0;
    int intSym = (int)sym;
    string binary;
    while (intSym != 0) {
        binary = (intSym % 2 == 0 ? "0" : "1") + binary;
        intSym /= 2;
    }
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '1')
            result++;
    }
    while (binary.length() < 8) {
        binary = "0" + binary;
    }
    cout << "Двоичное представление '" << sym << "': " << binary << endl;
    cout << "Единиц: " << result << "\n" << endl;
    return result;
}

string encrypt(string message) {
    char* str = new char[message.length() + 1]();
    char* result = new char[message.length() + 1]();
    message.copy(str, message.length() + 1);
    int T = gamma(T0);
    cout << "\nКодирование:\n" << endl;
    for (int i = 0; i < message.length(); i++) {
        cout << "T[" << i << "]: " << T << endl;
        result[i] = (char)(T ^ str[i]);
        T = gamma(sumOne(str[i]));
    }
    cout << "Зашифрованное значение: " << result << endl;
    cout << "______________________________________\n" << endl;
    return result;
}

string decrypt(string message) {
    char* str = new char[message.length() + 1]();
    char* result = new char[message.length() + 1]();
    message.copy(str, message.length() + 1);
    int T = gamma(T0);
    cout << "\nДекодирование:\n" << endl;
    for (int i = 0; i < message.length(); i++) {
        cout << "T[" << i << "]: " << T << endl;
        result[i] = (char)(T ^ str[i]);
        T = gamma(sumOne((char)(T ^ str[i])));
    }
    cout << "Расшифрованное значение: " << result << endl;
    cout << "______________________________________\n" << endl;
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string message, message1, message2;
    cout << "Введите сообщение: " << endl;
    getline(cin, message);
    message1 = encrypt(message);
    message2 = decrypt(message1);
}