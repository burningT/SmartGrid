#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;


class CPP_UNIT_TEST_EXPORT MessknotenPrepareDisplay
{
private:
	float Daytime;
	float currentConsumption;
	float Cost; 


public:
	MessknotenPrepareDisplay();
	
	void TransmitCurrentConsumption(float currentConsumption);
	void TransmitCostIfUsedNow(float Cost); 
	
};

