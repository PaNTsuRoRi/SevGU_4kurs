#include "sensorTemp.h"

using namespace std;

SensorTemp::SensorTemp() {
	currentTemp = rand() % 10 + 20;
	accuracy = 1;
	isWorking = true;
}

SensorTemp::SensorTemp(int currentTemp, int accuracy, bool isWorking) {
	this->currentTemp = currentTemp;
	this->accuracy = accuracy;
	this->isWorking = isWorking;
}

int SensorTemp::getCurrentTemp() {
	return this->currentTemp;
}

int SensorTemp::getAccuracy() {
	return this->accuracy;
}

bool SensorTemp::getIsWorking() {
	return this->isWorking;
}

void SensorTemp::setCurrentTemp(int currentTemp) {
	this->currentTemp = currentTemp;
}

void SensorTemp::setAccuracy(int accuracy) {
	this->accuracy = accuracy;
}

void SensorTemp::setIsWorking(bool isWorking) {
	this->isWorking = isWorking;
}