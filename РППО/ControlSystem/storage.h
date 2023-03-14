#pragma once

#include "tempSystem.h"
#include "wetSystem.h"

using namespace std;

class Storage {
private:
    string name;
	int minTemp;
	int maxTemp;
	int minWet;
	int maxWet;
	TempSystem* tempSystem;
	WetSystem* wetSystem;
public:
	Storage();
	Storage(string name, int minTemp, int maxTemp, int minWet, int maxWet);

	string getName();
	int getMinTemp();
	int getMaxTemp();
	int getMinWet();
	int getMaxWet();
	TempSystem* getTempSystem();
	WetSystem* getWetSystem();

	void setName(string name);
	void setMinTemp(int minTemp);
	void setMaxTemp(int maxTemp);
	void setMinWet(int minWet);
	void setMaxWet(int maxWet);
	void setTempSystem(TempSystem* tempSystem);
	void setWetSystem(WetSystem* wetSystem);
	void infoStorage();
	void isWorking(bool isWorking);
};