/** ZentralknotenData.h (TR 16-June-2015)
*
* Edited by:
*
*                  Datensatz eines Zentralknotens, bestehend aus Identifier, Gruppe und Verlauf der Oekonomie
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


class CPP_UNIT_TEST_EXPORT ZentralknotenData
{
private:
	int identifier;					//eindeutiger Identifier des Knotens
	int group;						//Gruppe des Knotens
	vector<int> ratingOfEconomy;	//Verlauf der Bewertung der Ökonomie des Verbrauchs am Knoten
									//Anmerkung: sollte später durch Datentyp mit Zeitstempel ersetzt werden
public:
	ZentralknotenData();
	ZentralknotenData(int identifier, int group, vector<int> ratingOfEconomy);
	~ZentralknotenData();

	void SetIdentifier(int identifier);
	int GetIdentifier();
	string GetIdentifier_string();

	void SetGroup(int tariffCourse);
	int GetGroup();
	string GetGroup_string();

	void SetRatingOfEconomy(vector<int> ratingOfEconomy);
	void AppendRatingOfEconomy(int ratingOfEconomy);
	vector<int> GetRatingOfEconomy();
	string GetRatingOfEconomy_string();
};