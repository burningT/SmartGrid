#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;

class CPP_UNIT_TEST_EXPORT PrepareArduinoDisplay
{
	//string message; 
	int message;

public:
	PrepareArduinoDisplay();
	void EncodeMessage(int message);
};

