#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"

using namespace std;

int p = 31;
int q = 3;
int a = 5;

int getSum(char sym) {

}

int getHash(string str) {
    
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));
    int x = rand() % 3 + 1;
    int y = pow(a, x);
    y = y % p;
}