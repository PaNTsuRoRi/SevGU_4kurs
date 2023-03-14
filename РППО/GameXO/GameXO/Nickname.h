#pragma once
#include <string>

using namespace std;

class Nickname {
private:
    char g_symbol;
    string g_name;
public:
    void setName(string name);
    string getName();
    char getSymb();
    Nickname(char g_symbol, string g_name);
    ~Nickname();
};