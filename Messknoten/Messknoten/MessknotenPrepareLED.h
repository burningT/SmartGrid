#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;

class CPP_UNIT_TEST_EXPORT MessknotenPrepareLED
{
	int Led;

public:
	MessknotenPrepareLED();
	
	void GenerateLedSignal(int Led);
};

