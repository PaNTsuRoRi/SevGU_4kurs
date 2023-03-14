#include "storage.h"
#include "controlSystem.h"

Storage::Storage() {
	name = "";
	minTemp = 0;
	maxTemp = 30;
	minWet = 40;
	maxWet = 70;
	tempSystem = new TempSystem();
	wetSystem = new WetSystem();
}

Storage::Storage(string name, int minTemp, int maxTemp, int minWet, int maxWet) {
	this->name = name;
	this->minTemp = minTemp;
	this->maxTemp = maxTemp;
	this->minWet = minWet;
	this->maxWet = maxWet;
	tempSystem = new TempSystem();
	wetSystem = new WetSystem();
}

string Storage::getName() {
	return this->name;
}

int Storage::getMinTemp() {
	return this->minTemp;
}

int Storage::getMaxTemp() {
	return this->maxTemp;
}

int Storage::getMinWet() {
	return this->minWet;
}

int Storage::getMaxWet() {
	return this->maxWet;
}

TempSystem* Storage::getTempSystem() {
	return this->tempSystem;
}

WetSystem* Storage::getWetSystem() {
	return this->wetSystem;
}

void Storage::setName(string name) {
	this->name = name;
}

void Storage::setMinTemp(int minTemp) {
	this->minTemp = minTemp;
}

void Storage::setMaxTemp(int maxTemp) {
	this->maxTemp = maxTemp;
}

void Storage::setMinWet(int minWet) {
	this->minWet = minWet;
}

void Storage::setMaxWet(int maxWet) {
	this->maxWet = maxWet;
}

void Storage::setTempSystem(TempSystem* tempSystem){
	this->tempSystem = tempSystem;
}

void Storage::setWetSystem(WetSystem* wetSystem) {
	this->wetSystem = wetSystem;
}

void Storage::infoStorage() {
	cout << "Наименование склада:--------------- " << getName() << endl
		<< "Минимальная температура:----------- " << getMinTemp() << endl
		<< "Максимальная температура:---------- " << getMaxTemp() << endl
		<< "Минимальный процент влажности:----- " << getMinWet() << endl
		<< "Максимальный процент влажности:---- " << getMaxWet() << endl
		<< "Текущая температура:--------------- " << getTempSystem()->getSensorTemp()->getCurrentTemp() << endl
		<< "Текущая влажность:----------------- " << getWetSystem()->getSensorWet()->getCurrentWet() << endl
		<< "Система регулирования температуры:- ";  isWorking(getTempSystem()->getIsWorking());
	cout << "     Кондиционер:------------------ ";  isWorking(getTempSystem()->getIsAirCondWorking());
	cout << "     Отопление:-------------------- ";  isWorking(getTempSystem()->getIsHeatWorking());
	cout << "Система регулирования влажности:--- ";  isWorking(getWetSystem()->getIsWorking());
	cout << "     Вентиляция:------------------- ";  isWorking(getWetSystem()->getIsVentWorking());
	cout << "     Увлажнитель:------------------ ";  isWorking(getWetSystem()->getIsWetWorking());
}

void Storage::isWorking(bool isWorking) {
	string str;
	if (isWorking) printf("\033[32mвключен\033[0m\n");
	else printf("\033[31mвыключен\033[0m\n");
}