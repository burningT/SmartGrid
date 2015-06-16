/** GroupData.h (TR 15-June-2015)
*
* Edited by:
*
*                  Zuordnung von Gruppen zu dem Ranking ihrer Mitglieder
*
*
*
*/

#pragma once
#include "UnitTestINOSetup.h"
using namespace std;
#include <list>


class CPP_UNIT_TEST_EXPORT GroupData
{
private:
	int identifier;
	list<int> ranking;
public:
	GroupData();
	~GroupData();
};