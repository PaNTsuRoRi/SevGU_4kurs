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
	cout << "������������ ������:--------------- " << getName() << endl
		<< "����������� �����������:----------- " << getMinTemp() << endl
		<< "������������ �����������:---------- " << getMaxTemp() << endl
		<< "����������� ������� ���������:----- " << getMinWet() << endl
		<< "������������ ������� ���������:---- " << getMaxWet() << endl
		<< "������� �����������:--------------- " << getTempSystem()->getSensorTemp()->getCurrentTemp() << endl
		<< "������� ���������:----------------- " << getWetSystem()->getSensorWet()->getCurrentWet() << endl
		<< "������� ������������� �����������:- ";  isWorking(getTempSystem()->getIsWorking());
	cout << "     �����������:------------------ ";  isWorking(getTempSystem()->getIsAirCondWorking());
	cout << "     ���������:-------------------- ";  isWorking(getTempSystem()->getIsHeatWorking());
	cout << "������� ������������� ���������:--- ";  isWorking(getWetSystem()->getIsWorking());
	cout << "     ����������:------------------- ";  isWorking(getWetSystem()->getIsVentWorking());
	cout << "     �����������:------------------ ";  isWorking(getWetSystem()->getIsWetWorking());
}

void Storage::isWorking(bool isWorking) {
	string str;
	if (isWorking) printf("\033[32m�������\033[0m\n");
	else printf("\033[31m��������\033[0m\n");
}