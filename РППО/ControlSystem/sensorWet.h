#pragma once

#include <string>

using namespace std;

class SensorWet {
private:
	int currentWet;
	int accuracy;
	bool isWorking;
public:
	SensorWet();
	SensorWet(int currentWet, int accuracy, bool isWorking);

	int getCurrentWet();
	int getAccuracy();
	bool getIsWorking();

	void setCurrentWet(int currentWet);
	void setAccuracy(int accuracy);
	void setIsWorking(bool isWorking);
};