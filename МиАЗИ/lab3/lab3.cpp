#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int rounds = 18;

byte fun(char sym) {
	return (byte)(sym << 3);
}

string encrypt(string message) {
	char res;
    char* result = new char[message.length() + 1];
	message.copy(result, message.length() + 1);
	result[message.length()] = '\0';
    for (int i = 0; i < message.length(); i+=2) {
        for (int j = 0; j < rounds; j++) {
			res = result[i];
			result[i] = (char)(fun(result[i]) ^ result[i + 1]);
			result[i + 1] = res;
        }
		res = result[i];
		result[i] = result[i + 1];
		result[i + 1] = res;
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
	cout << "\nРасшифрованное сообщение: " << endl;
	cout << message3;
	cin.get();
}