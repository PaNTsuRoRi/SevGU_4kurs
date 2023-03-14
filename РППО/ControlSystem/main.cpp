#include "controlSystem.h"

void tests() {
    // Test 1
    cout << "Test 1" << endl;
    cout << "$Storage storage1;" << endl;
    Storage storage1;
    cout << "$storage1.infoStorage();" << endl;
    storage1.infoStorage();
    cout << "$storage1.setName(\"Склад1\");" << endl;
    storage1.setName("Склад1");
    cout << "$storage1.setMinTemp(15);" << endl;
    storage1.setMinTemp(15);
    cout << "$storage1.setMaxTemp(20);" << endl;
    storage1.setMaxTemp(20);
    cout << "$storage1.setMinWet(40);" << endl;
    storage1.setMinWet(40);
    cout << "$storage1.setMaxTemp(50);" << endl;
    storage1.setMaxWet(50);
    cout << "$storage1.infoStorage();" << endl;
    storage1.infoStorage();
    cout << endl << endl;

    // Test 2
    cout << "Test 2" << endl;
    cout << "&Storage storage2 = Storage(\"Склад2\", 10, 15, 45, 50);" << endl;
    Storage storage2 = Storage("Склад2", 10, 15, 45, 50);
    cout << "$storage2.infoStorage();" << endl;
    storage2.infoStorage();
    cout << endl << endl;

    // Test 3
    cout << "Test Simulation" << endl;
    cout << "Storage* storage3 = new Storage(\"Склад2\", 10, 15, 40, 45);" << endl;
    Storage* storage3 = new Storage("Склад2", 10, 15, 40, 45);
    cout << "ControlSystem controlSystem;" << endl;
    ControlSystem controlSystem;
    cout << "controlSystem.startSimulation(storage3);" << endl;
    cout << "\nНажмите Enter чтобы начать симуляцию";
    cin.get();
    controlSystem.startSimulation(storage3);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    ControlSystem controlSystem;
    controlSystem.menu();

	//tests();
}