/** DataManagement.h (TR 16-June-2015)
*
* Edited by:
*
*                Diese Klasse enthaelt die Datenhaltung des Servers
*
*				Eingegliederte Klassen koennen spaeter durch eine Datenbank ersetzt werden
*
*
*/

#pragma once
#include "UnitTestINOSetup.h"
#include "GroupData.h"
#include "TariffData.h"
#include "ZentralknotenData.h"

#include <vector>
#include <algorithm>

using namespace std;

class CPP_UNIT_TEST_EXPORT DataManagement
{
private:
	//vector<GroupData> tariffCourse;	//Gruppen, die vom Server verwaltet werden //Nicht implementiert
	vector<TariffData> tariffData;					//Vom Server verwaltete Tarife
	vector<ZentralknotenData> zentralknotenData;	//Vom Server verwaltete Tarife

public:
	DataManagement();
	DataManagement(vector<TariffData> tariffData, vector<ZentralknotenData> zentralknotenData);
	~DataManagement();

	void SetTariffData(vector<TariffData> tariffData);
	void AppendTariffData(TariffData tariffData);
	bool SetTariffData_byId(TariffData tariffData);
	vector<TariffData> GetTariffData();
	string GetTariffData_string();
	TariffData GetTariffData_byId(int identifier);

	void SetZentralknotenData(vector<ZentralknotenData> zentralknotenData);
	void AppendZentralknotenData(ZentralknotenData zentralknotenData);
	bool SetZentralknotenData_byId(ZentralknotenData zentralknotenData);
	vector<ZentralknotenData> GetZentralknotenData();
	string GetZentralknotenData_string();
	ZentralknotenData GetZentralknotenData_byId(int identifier);
};