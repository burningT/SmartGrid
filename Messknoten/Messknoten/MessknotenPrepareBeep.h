#pragma once
#include "../Messknoten/UnitTestINOSetup.h"
#include <string>
#include <iostream>
using namespace std;

class CPP_UNIT_TEST_EXPORT MessknotenPrepareBeep
{
	int Beep; 

public:
	MessknotenPrepareBeep();
	void GenerateBeep(int Beep);
};

