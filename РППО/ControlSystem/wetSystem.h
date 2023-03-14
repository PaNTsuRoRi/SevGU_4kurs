#pragma once

#include "sensorWet.h"

using namespace std;

class WetSystem {
private:
	bool isWorking;
	bool isVentWorking;
	bool isWetWorking;
	SensorWet* sensorWet;
public:
	WetSystem();
	WetSystem(bool isWorking, bool isAirCondWorking, bool isHeatWorking);

	bool getIsWorking();
	bool getIsVentWorking();
	bool getIsWetWorking();
	SensorWet* getSensorWet();

	void enableSystem();
	void disableSystem();
	void enableVent();
	void disableVent();
	void enableWet();
	void disableWet();
	void setSensorWet(SensorWet* sensorWet);
};