#pragma once

#include "sensorTemp.h"

using namespace std;

class TempSystem {
private:
	bool isWorking;
	bool isAirCondWorking;
	bool isHeatWorking;
	SensorTemp* sensorTemp;
public:
	TempSystem();
	TempSystem(bool isWorking, bool isAirCondWorking, bool isHeatWorking);

	bool getIsWorking();
	bool getIsAirCondWorking();
	bool getIsHeatWorking();
	SensorTemp* getSensorTemp();

	void enableSystem();
	void disableSystem();
	void enableAirCond();
	void disableAirCond();
	void enableHeat();
	void disableHeat();
	void setSensorTemp(SensorTemp* sensorTemp);
};