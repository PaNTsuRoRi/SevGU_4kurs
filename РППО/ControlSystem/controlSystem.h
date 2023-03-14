#pragma once

#include <Windows.h>
#include <vector>
#include "storage.h"
#include "utils.h"

using namespace std;

class ControlSystem {
public:
	Storage* storage;
	vector <Storage*> storages;
	const int timeSleep = 1000;

	void printNameSystem();
	void menu();
	pair <Storage*, bool> addStorage();

	void listStorages(vector <Storage*> storages);
	void menuInfoStorage(Storage* storage);
	void renameStorage(Storage* storage);
	void changeParameters(Storage* storage);
	void edTempSystem(Storage* storage);
	void edWetSystem(Storage* storage);
	void startSimulation(Storage* storage);
	void workTempSystem(Storage* storage);
	void workWetSystem(Storage* storage);
	void workTempWetSystem(Storage* storage);

	string pMenuTempSystem(bool isWorking);
	string pMenuWetSystem(bool isWorking);
};