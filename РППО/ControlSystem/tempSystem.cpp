#include "tempSystem.h"

using namespace std;

TempSystem::TempSystem() {
	isWorking = true;
	isAirCondWorking = false;
	isHeatWorking = false;
	sensorTemp = new SensorTemp();
}

TempSystem::TempSystem(bool isWorking, bool isAirCondWorking, bool isHeatWorking) {
	this->isWorking = isWorking;
	this->isAirCondWorking = isAirCondWorking;
	this->isHeatWorking = isHeatWorking;
	sensorTemp = new SensorTemp();
}

bool TempSystem::getIsWorking() {
	return this->isWorking;
}

bool TempSystem::getIsAirCondWorking() {
	return this->isAirCondWorking;
}

bool TempSystem::getIsHeatWorking() {
	return this->isHeatWorking;
}

SensorTemp* TempSystem::getSensorTemp() {
	return this->sensorTemp;
}

void TempSystem::enableSystem() {
	this->isWorking = true;
}

void TempSystem::disableSystem() {
	this->isWorking = false;
}

void TempSystem::enableAirCond() {
	this->isAirCondWorking = true;
}

void TempSystem::disableAirCond() {
	this->isAirCondWorking = false;
}

void TempSystem::enableHeat() {
	this->isHeatWorking = true;
}

void TempSystem::disableHeat() {
	this->isHeatWorking = false;
}

void TempSystem::setSensorTemp(SensorTemp* sensorTemp) {
	this->sensorTemp = sensorTemp;
}