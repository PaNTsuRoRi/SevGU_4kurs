#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int rounds = 18;

string encrypt(string message) {
    char* result = new char[message.length() + 1]();
    for (int i = 0; i < message.length(); i++) {
        for (int j = 0; j < rounds; j++) {

        }
    }
    return result;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string message1, message2, message3;
	cout << "Введите сообщение: " << endl;
	getline(cin, message1);
	message2 = encrypt(message1);
	message3 = encrypt(message2);
	cout << "Зашифрованное сообщение: " << endl;
	cout << message2;
	cout << "Расшифрованное сообщение: " << endl;
	cout << message3;
}