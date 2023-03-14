#include "sensorWet.h"

using namespace std;

SensorWet::SensorWet() {
	currentWet = rand() % 10 + 50;
	accuracy = 1;
	isWorking = true;
}

SensorWet::SensorWet(int currentWet, int accuracy, bool isWorking) {
	this->currentWet = currentWet;
	this->accuracy = accuracy;
	this->isWorking = isWorking;
}

int SensorWet::getCurrentWet() {
	return this->currentWet;
}

int SensorWet::getAccuracy() {
	return this->accuracy;
}

bool SensorWet::getIsWorking() {
	return this->isWorking;
}

void SensorWet::setCurrentWet(int currentWet) {
	this->currentWet = currentWet;
}

void SensorWet::setAccuracy(int accuracy) {
	this->accuracy = accuracy;
}

void SensorWet::setIsWorking(bool isWorking) {
	this->isWorking = isWorking;
}