#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;

class CPP_UNIT_TEST_EXPORT InterfaceDisplay
{
public:
	InterfaceDisplay();
	string transmitCurrentConsumption(float);
	string transmitOptimalUsageTimes(int[], int[]);
	string transmitCostIfUsedNow(int[], int[]);
};