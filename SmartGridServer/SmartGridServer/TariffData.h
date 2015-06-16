/** TariffData.h (TR 15-June-2015)
*
* Edited by:
*
*                  Zuordnung von Tarifdatensätzen und Netzauslastungsprofilen zu eindeutigen IDs
*
*
*
*/

#pragma once
#include "UnitTestINOSetup.h"
#include "StringConverter.h"

#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define COURSE_LEN 7*24*60/5	//Daten für 7 Tage im Raster von 5min


class CPP_UNIT_TEST_EXPORT TariffData
{
private:
	int identifier;						//eindeutiger Identifier des Tarifs
	vector<float> tariffCourse;			//Tarifverlauf des Tarifs
	vector<float> networkLoadCourse;	//Profil der Netzwerkauslastung
public:
	TariffData();
	TariffData(int identifier, vector<float> tariffCourse, vector<float> networkLoadCourse);
	~TariffData();

	void SetIdentifier(int identifier);
	int GetIdentifier();
	string GetIdentifier_string();

	void SetTariffCourse(vector<float> tariffCourse);
	vector<float> GetTariffCourse();
	string GetTariffCourse_string();

	void SetNetworkLoadCourse(vector<float> networkLoadCourse);
	vector<float> GetNetworkLoadCourse();
	string GetNetworkLoadCourse_string();
};