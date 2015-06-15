/** StringConverter.h (TR 15-June-2015)
*
* Edited by:
*
*                  Pool von String-Konvertierungen
*
*
*
*/

#pragma once
#include "UnitTestINOSetup.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class CPP_UNIT_TEST_EXPORT StringConverter
{
private:
	string delimiterL;
	string delimiterR;
	string separator;
public:
	StringConverter();
	StringConverter(string delimiterL, string delimiterR, string separator);

	string toString(vector<float> vector);
};