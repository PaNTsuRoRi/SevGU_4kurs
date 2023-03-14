#pragma once

#include <string>

using namespace std;

class SensorTemp {
private:
	int currentTemp;
	int accuracy;
	bool isWorking;
public:
	SensorTemp();
	SensorTemp(int currentTemp, int accuracy, bool isWorking);

	int getCurrentTemp();
	int getAccuracy();
	bool getIsWorking();

	void setCurrentTemp(int currentTemp);
	void setAccuracy(int accuracy);
	void setIsWorking(bool isWorking);
};