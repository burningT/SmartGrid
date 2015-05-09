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

public:
	Messknoten();
};