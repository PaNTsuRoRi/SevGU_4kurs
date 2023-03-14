#include "wetSystem.h"

using namespace std;

WetSystem::WetSystem() {
	isWorking = true;
	isVentWorking = false;
	isWetWorking = false;
	sensorWet = new SensorWet();
}

WetSystem::WetSystem(bool isWorking, bool isVentWorking, bool isWetWorking) {
	this->isWorking = isWorking;
	this->isVentWorking = isVentWorking;
	this->isWetWorking = isWetWorking;
	sensorWet = new SensorWet();
}

bool WetSystem::getIsWorking() {
	return this->isWorking;
}

bool WetSystem::getIsVentWorking() {
	return this->isVentWorking;
}

bool WetSystem::getIsWetWorking() {
	return this->isWetWorking;
}

SensorWet* WetSystem::getSensorWet() {
	return this->sensorWet;
}

void WetSystem::enableSystem() {
	this->isWorking = true;
}

void WetSystem::disableSystem() {
	this->isWorking = false;
}

void WetSystem::enableVent() {
	this->isVentWorking = true;
}

void WetSystem::disableVent() {
	this->isVentWorking = false;
}

void WetSystem::enableWet() {
	this->isWetWorking = true;
}

void WetSystem::disableWet() {
	this->isWetWorking = false;
}

void WetSystem::setSensorWet(SensorWet* sensorWet) {
	this->sensorWet = sensorWet;
}