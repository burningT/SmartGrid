#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;



class CPP_UNIT_TEST_EXPORT Messknoten
{
private:
	int identifier;
	int DeviceTypeID;
	int currentConsumption;
	int currentRuntime;
	int lastStartTime;
	int averageRuntimeServer;
	int averageRuntimeDecvice;
	int averageConsumptionServer;
	int averageConsumptionDevice;
	int Daytime;
	float tariffCourse[24];
	float networkLoadCourse[24];

	void optimalUsageTime(int[], int[]);
	float costIfUsedNow();
	int ratingOfCurrentUsage();
	int LedSignal; 
	int BeepSignal; 

public:
	Messknoten();
	void SyncDaytime(int Daytime);
	void CalcCurrentConsumption(int currentConsumption);
	void TransmitDisplayCurrentConsumption(int currentConsumption);
	void TransmitZentralknotenCurrentConsumption(int currentConsumption);
	void CalcCostIfUsedNow(float costIfUsedNow, float tariffCourse, int currentConsumption);
	void TransmitDisplayCostIfUsedNow(float costIfUsedNow);
	void TransmitZentralknotenCostIfUsedNow(float costIfUsedNow);
	void GenerateLedSiganal(int LedSignal);
	void GenerateBeep(int BeepSignal);
};


