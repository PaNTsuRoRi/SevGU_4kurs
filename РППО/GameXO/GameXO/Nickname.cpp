#include "Nickname.h"
#include <string>

using namespace std;

void Nickname::setName(string name) {
    g_name = name;
}
string Nickname::getName() {
    return g_name;
}
char Nickname::getSymb() {
    return g_symbol;
}
Nickname::Nickname(char g_symbol, string g_name) {
    this->g_name = g_name;
    this->g_symbol = g_symbol;
}
Nickname::~Nickname() {
    g_symbol = ' ';
    g_name = "";
}