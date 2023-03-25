#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "windows.h"

using namespace std;

int p = 31;
int q = 3;
int a = 5;

int getSum(unsigned char sym) {
    string buf;
    int sum = (int)sym;
    int s = 0;
    buf.reserve(numeric_limits<unsigned int>::digits);
    do {
        buf += char('0' + sum % 2);
        sum = sum / 2;
    } while (sum > 0);
    for (int i = 0; i < buf.size(); i++) {
        if (buf[i] = '1') s++;
    }
    return s;
}

int getHash(string str) {
    int hash = 0;
    for (int i = 0; i < str.length() + 1; i++) {
        hash += getSum(str[i]);
    }
    return hash;
}

vector<int> genSignature(string str, int x) {
    int hash = getHash(str);
    if (hash == 0) 
        hash = 1;
    int k = rand() * (q - 1) + 1;
    int r = pow(a, k);
    r %= p;
    int r1 = r % q;
    if (r1 == 0) return genSignature(str, x);
    int s = (x * r1 + k * hash) % q;
    if (s == 0) return genSignature(str, x);
    return { r1, s };
}

string checkSignature(string str, int r1, int s, int y) {
    if (r1 < 0 || r1 > q || s < 0 || s > q) 
        return "Подпись не прошла проверку!\n";
    int hash = getHash(str);
    if (hash == 0) 
        hash = 1;
    int v = pow(hash, q - 2);
    v %= q;
    int z1 = (s * v) % q;
    int z2 = ((q - r1) * v) % q;
    int u = pow(y, z2);
    u %= p;
    u *= pow(a, z1);
    u %= q;
    bool res = u == r1;
    if (res)
        return "Подпись прошла проверку!\n";
    return "Подпись не прошла проверку!\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    string str;
    vector<int> vec;
    int r1, s;

    int x = rand() % 3 + 1;
    int y = pow(a, x);
    y = y % p;

    cout << "Введите строку для генеации подписи:" << endl;
    getline(cin, str);
    printf("\np = %d; | q = %d | a = %d | x = %d | y = %d\n\n", p, q, a, x, y);
    vec = genSignature(str, x);
    r1 = vec[0];
    s = vec[1];
    cout << "Сгенерированная подпись:" << endl;
    printf("r1 = %d | s = %d\n\n", r1, s);
    cout << "Проверка подписи: " << endl;
    cout << "При r1: " << checkSignature(str, r1, s, y) << endl;;
    cout << "При r1+1: " << checkSignature(str, r1 + 1, s, y) << endl;

    cin.get();
}