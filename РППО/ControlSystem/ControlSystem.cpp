#include <stdexcept>
#include <limits>
#include "controlSystem.h"

using namespace std;

void ControlSystem::printNameSystem() {
	system("cls");
	cout << "//--- СИСТЕМА АВТОРЕГУЛИРОВАНИЯ ТЕМПЕРАТУРЫ И ВЛАЖНОСТИ В СКЛАДАХ ---//\n" << endl;
}

void ControlSystem::menu() {
	int numMenu;
	bool isNum = false;
	pair <Storage*, bool> addStorageRet;

	printNameSystem();
	cout << "1. Добавить склад" << endl
	     << "2. Список складов" << endl
	     << "0. Выход" << endl
	     << "\nВведите номер пунтка меню: ";
	cin >> numMenu;
	if (isValidValueEntered()) {
		switch (numMenu) {
		case 1:
			try {
				addStorageRet = addStorage();
				isNum = addStorageRet.second;
			}
			catch (invalid_argument const& ex) {
				cout << ex.what() << endl;
			}
			if (isNum) {
				storages.push_back(addStorageRet.first);
				cout << "\nСклад успешно добавлен";
			}
			cout << "\nНажмите Enter чтобы вернуться" << endl;
			cin.get();
			cin.get();
			menu();
			break;
		case 2:
			try { listStorages(storages); }
			catch (invalid_argument const& ex) {
				cout << ex.what() << endl;
				cout << "\nНажмите Enter чтобы вернуться" << endl;
				cin.get();
				cin.get();
			}
			menu();
			break;
		case 0:
			break;
		default:
			printNameSystem();
			cout << "Вы ввели неправильный пункт меню" << endl;
			cout << "Нажмите Enter чтобы попробовать заново" << endl;
			cin.get();
			cin.get();
			menu();
			break;
		}
	}
	else {
		printNameSystem();
		cout << "Вы ввели неправильный пункт меню" << endl;
		cout << "Нажмите Enter чтобы попробовать заново" << endl;
		cin.get();
		menu();
	}

}

pair <Storage*, bool> ControlSystem::addStorage() {
	string name;
	int minTemp, maxTemp, minWet, maxWet;

	printNameSystem();
	cout << "--- ДОБАВЛЕНИЕ СКЛАДА ---" << endl;
	cout << "\nВведите имя склада: ";
	cin >> name;
	cout << "Минимальная температура на складе (-35 - 40): ";
	cin >> minTemp;
	if (!isValidValueEntered() || minTemp < -35 || minTemp>40) {
		throw invalid_argument("\nАгрумент должен быть числом. Склад не добавлен.");
	}
	cout << "Максимальная температура на складе (<50): ";
	cin >> maxTemp;
	if (!isValidValueEntered() || maxTemp <= minTemp || maxTemp > 50) {
		throw invalid_argument("\nАгрумент должен быть числом (<50), больше минимальной температуры. Склад не добавлен.");
	}
	cout << "Минимальный процент влажности на складе (0-60): ";
	cin >> minWet;
	if (!isValidValueEntered() || minWet < 0 || minWet>60) {
		throw invalid_argument("\nАгрумент должен быть числом. Склад не добавлен.");
	}
	cout << "Максимальный процент влажности на складе (<100): ";
	cin >> maxWet;
	if (!isValidValueEntered() || maxWet <= minWet || maxWet > 100) {
		throw invalid_argument("\nАгрумент должен быть числом, больше минимальной влажности. Склад не добавлен.");
	}

	storage = new Storage(name, minTemp, maxTemp, minWet, maxWet);

	return make_pair(storage, true);
}

void ControlSystem::listStorages(vector <Storage*> storages) {
	int numMenu;
	int numStorage;
	printNameSystem();
	cout << "--- СПИСОК СКЛАДОВ ---" << endl;
	for (int i = 0; i < storages.size(); i++) {
		cout << i+1 << " - " << storages[i]->getName() << endl;
	}
	cout << "\n1. Выбрать склад" << endl
	     << "0. Назад" << endl
	     << "\nВведите номер пунтка меню: ";
	cin >> numMenu;

	if (isValidValueEntered()) {
		switch (numMenu) {
		case 1:
			cout << "Введите номер склада: ";
			cin >> numStorage;
			if (!isValidValueEntered() || numStorage > storages.size() || storages.empty()) {
				throw invalid_argument("\nСклада с таким номером не существует");
			}
			numStorage--;
			storage = storages[numStorage];
			menuInfoStorage(storage);
			listStorages(storages);
			break;
		case 0:
			break;
		default:
			printNameSystem();
			cout << "Вы ввели неправильный пункт меню" << endl;
			cout << "Нажмите Enter чтобы попробовать заново" << endl;
			cin.get();
			cin.get();
			listStorages(storages);
			break;
		}
	}
	else {
		printNameSystem();
		cout << "Вы ввели неправильный пункт меню" << endl;
		cout << "Нажмите Enter чтобы попробовать заново" << endl;
		cin.get();
		listStorages(storages);
	}
}

void ControlSystem::menuInfoStorage(Storage* storage){
	int numMenu;
	printNameSystem();
	storage->infoStorage();
	cout << "\n1. Переименовать склад" << endl
		 << "2. Изменить параметры температуры и влажности" << endl
		 << pMenuTempSystem(storage->getTempSystem()->getIsWorking()) << endl
		 << pMenuWetSystem(storage->getWetSystem()->getIsWorking()) << endl
	 	 << "5. Запустить симуляцию" << endl
		 << "0. Назад" << endl
	     << "\nВведите номер пунтка меню: ";
	cin >> numMenu;

	switch (numMenu) {
	case 1:
		renameStorage(storage);
		menuInfoStorage(storage);
		break;
	case 2:
		try { changeParameters(storage); }
		catch(invalid_argument const& ex) {
			cout << ex.what() << endl;
		}
		cout << "\nНажмите Enter чтобы вернуться" << endl;
		cin.get();
		cin.get();
		menuInfoStorage(storage);
		break;
	case 3:
		edTempSystem(storage);
		menuInfoStorage(storage);
		break;
	case 4:
		edWetSystem(storage);
		menuInfoStorage(storage);
		break;
	case 5:
		startSimulation(storage);
		menuInfoStorage(storage);
		break;
	case 0:
		break;
	default:
		cout << "Вы ввели неправильный пункт меню" << endl;
		cout << "Нажмите Enter чтобы попробовать заново" << endl;
		cin.get();
		cin.get();
		listStorages(storages);
		break;
	}
}

void ControlSystem::renameStorage(Storage* storage) {
	string name;
	cout << "\nВведите новое имя склада: ";
	cin >> name;
	storage->setName(name);
}

void ControlSystem::changeParameters(Storage* storage) {
	int minTemp, maxTemp, minWet, maxWet;
	cout << "Минимальная температура (-35 - 40): ";
	cin >> minTemp;
	if (!isValidValueEntered() || minTemp < -35 || minTemp>40) {
		throw invalid_argument("\nАгрумент должен быть числом  (-35 - 40). Параметры не изменены");
	}
	cout << "Максимальная температура (<50): ";
	cin >> maxTemp;
	if (!isValidValueEntered() || maxTemp <= minTemp || maxTemp > 50) {
		throw invalid_argument("\nАгрумент должен быть числом (<50), больше минимальной температуры. Параметры не изменены");
	}
	cout << "Минимальный процент влажности (0-60): ";
	cin >> minWet;
	if (!isValidValueEntered() || minWet < 0 || minWet>60) {
		throw invalid_argument("\nАгрумент должен быть числом (0-60). Параметры не изменены");
	}
	cout << "Максимальный процент влажности (<100): ";
	cin >> maxWet;
	if (!isValidValueEntered() || maxWet <= minWet || maxWet > 100) {
		throw invalid_argument("\nАгрумент должен быть числом (<100), больше минимальной влажности. Параметры не изменены");
	}
	storage->setMinTemp(minTemp);
	storage->setMaxTemp(maxTemp);
	storage->setMinWet(minWet);
	storage->setMaxWet(maxWet);
}

void ControlSystem::edTempSystem(Storage* storage) {
	TempSystem* tempSystem = storage->getTempSystem();
	bool isWorking = tempSystem->getIsWorking();
	if (isWorking) tempSystem->disableSystem();
	else tempSystem->enableSystem();
}

void ControlSystem::edWetSystem(Storage* storage) {
	WetSystem* wetSystem = storage->getWetSystem();
	bool isWorking = wetSystem->getIsWorking();
	if (isWorking) wetSystem->disableSystem();
	else wetSystem->enableSystem();
}

void ControlSystem::startSimulation(Storage* storage) {
	TempSystem* tempSystem = storage->getTempSystem();
	WetSystem* wetSystem = storage->getWetSystem();

	printNameSystem();
	storage->infoStorage();

	if (tempSystem->getIsWorking()) {
		if (wetSystem->getIsWorking()) {
			workTempWetSystem(storage);
		}
		else workTempSystem(storage);
	}
	else if (wetSystem->getIsWorking())
		workWetSystem(storage);
}

void ControlSystem::workTempSystem(Storage* storage) {
	TempSystem* tempSystem = storage->getTempSystem();
	SensorTemp* sensorTemp = storage->getTempSystem()->getSensorTemp();
	int minTemp = storage->getMinTemp();
	int maxTemp = storage->getMaxTemp();
	int currentTemp = sensorTemp->getCurrentTemp();
	int temp = (minTemp + maxTemp) / 2;

	if (currentTemp > maxTemp) {
		tempSystem->enableAirCond();
		while (currentTemp > temp) {
			printNameSystem();
			storage->infoStorage();
			cout << "\nПодождите пока работает кондиционер...";
			Sleep(timeSleep);
			sensorTemp->setCurrentTemp(--currentTemp);
		}
		tempSystem->disableAirCond();
	}
	if (currentTemp < minTemp) {
		tempSystem->enableHeat();
		while (currentTemp < temp) {
			printNameSystem();
			storage->infoStorage();
			cout << "\nПодождите пока работает отопление...";
			Sleep(timeSleep);
			sensorTemp->setCurrentTemp(++currentTemp);
		}
		tempSystem->disableHeat();
	}
	if (currentTemp <= maxTemp && currentTemp >= minTemp) {
		printNameSystem();
		storage->infoStorage();
		cout << "\nТемпература оптимальна";
		cin.get();
		cin.get();
	}
}

void ControlSystem::workWetSystem(Storage* storage) {
	WetSystem* wetSystem = storage->getWetSystem();
	SensorWet* sensorWet = storage->getWetSystem()->getSensorWet();
	int minWet = storage->getMinWet();
	int maxWet = storage->getMaxWet();
	int currentWet = sensorWet->getCurrentWet();
	int wet = (minWet + maxWet) / 2;

	if (currentWet > maxWet) {
		wetSystem->enableVent();
		while (currentWet > wet) {
			printNameSystem();
			storage->infoStorage();
			cout << "\nПодождите пока работает вентиляция...";
			Sleep(timeSleep);
			sensorWet->setCurrentWet(--currentWet);
		}
		wetSystem->disableVent();
	}
	if (currentWet < minWet) {
		wetSystem->enableWet();
		while (currentWet < wet) {
			printNameSystem();
			storage->infoStorage();
			cout << "\nПодождите пока работает увлажнитель...";
			Sleep(timeSleep);
			sensorWet->setCurrentWet(++currentWet);
		}
		wetSystem->disableWet();
	}
	if (currentWet <= maxWet && currentWet >= minWet) {
		printNameSystem();
		storage->infoStorage();
		cout << "\nВлажность оптимальна";
		cin.get();
		cin.get();
	}
}

void ControlSystem::workTempWetSystem(Storage* storage) {
	TempSystem* tempSystem = storage->getTempSystem();
	SensorTemp* sensorTemp = storage->getTempSystem()->getSensorTemp();
	int minTemp = storage->getMinTemp();
	int maxTemp = storage->getMaxTemp();
	int currentTemp = sensorTemp->getCurrentTemp();
	int temp = (minTemp + maxTemp) / 2;

	WetSystem* wetSystem = storage->getWetSystem();
	SensorWet* sensorWet = storage->getWetSystem()->getSensorWet();
	int minWet = storage->getMinWet();
	int maxWet = storage->getMaxWet();
	int currentWet = sensorWet->getCurrentWet();
	int wet = (minWet + maxWet) / 2;

	if (currentTemp > maxTemp) {
		tempSystem->enableAirCond();
		if (currentWet > maxWet) {
			wetSystem->enableVent();
			while (currentTemp > temp || currentWet > wet) {
				printNameSystem();
				storage->infoStorage();
				cout << "\nПодождите пока работает кондиционер и вентиляция на складе...";
				Sleep(timeSleep);
				if (currentTemp > temp)
					sensorTemp->setCurrentTemp(--currentTemp);
				else tempSystem->disableAirCond();
				if (currentWet > wet)
					sensorWet->setCurrentWet(--currentWet);
				else wetSystem->disableVent();
			}
			wetSystem->disableVent();
		}
		else if (currentWet < minWet) {
			wetSystem->enableWet();
			while (currentTemp > temp || currentWet < wet) {
				printNameSystem();
				storage->infoStorage();
				cout << "\nПодождите пока работает кондиционер и увлажнитель на складе...";
				Sleep(timeSleep);
				if (currentTemp > temp)
					sensorTemp->setCurrentTemp(--currentTemp);
				else tempSystem->disableAirCond();
				if (currentWet < wet)
					sensorWet->setCurrentWet(++currentWet);
				else wetSystem->disableWet();
			}
			wetSystem->disableWet();
		}
		else workTempSystem(storage);
		tempSystem->disableAirCond();
	}
	else if (currentTemp < minTemp) {
		tempSystem->enableHeat();
		if (currentWet > maxWet) {
			wetSystem->enableVent();
			while (currentTemp < temp || currentWet > wet) {
				printNameSystem();
				storage->infoStorage();
				cout << "\nПодождите пока работает отопление и вентиляция на складе...";
				Sleep(timeSleep);
				if (currentTemp < temp)
					sensorTemp->setCurrentTemp(++currentTemp);
				else tempSystem->disableHeat();
				if (currentWet > wet)
					sensorWet->setCurrentWet(--currentWet);
				else wetSystem->disableVent();
			}
			wetSystem->disableVent();
		}
		else if (currentWet < minWet) {
			wetSystem->enableWet();
			while (currentTemp < temp || currentWet < wet) {
				printNameSystem();
				storage->infoStorage();
				cout << "\nПодождите пока работает отопление и увлажнитель на складе...";
				Sleep(timeSleep);
				if (currentTemp < temp)
					sensorTemp->setCurrentTemp(++currentTemp);
				else tempSystem->disableHeat();
				if (currentWet < wet)
					sensorWet->setCurrentWet(++currentWet);
				else wetSystem->disableWet();
			}
			wetSystem->disableWet();
		}
		else tempSystem->disableHeat();
		workTempSystem(storage);
	}
	else if (currentWet > maxWet || currentWet < minWet)
		workWetSystem(storage);
	if (currentTemp <= maxTemp && currentTemp >= minTemp && currentWet <= maxWet && currentWet >= minWet) {
		printNameSystem();
		storage->infoStorage();
		cout << "\nТемпература и влажность оптимальны";
		cin.get();
		cin.get();
	}
}

string ControlSystem::pMenuTempSystem(bool isWorking) {
	string str = "3. ";
	if (isWorking) {
		str += "Выключить систему регулирования температуры";
		return str;
	}
	str += "Включить систему регулирования температуры";
	return str;
}

string ControlSystem::pMenuWetSystem(bool isWorking) {
	string str = "4. ";
	if (isWorking) {
		str += "Выключить систему регулирования влажности";
		return str;
	}
	str += "Включить систему регулирования влажности";
	return str;
}