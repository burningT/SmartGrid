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
#include "DataManagement.h"

/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	tariffData.clear();					
*	zentralknotenData.clear();
*
*/
DataManagement::DataManagement(){

	tariffData.clear();					
	zentralknotenData.clear();
}
/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	tariffData = tariffData;
*	zentralknotenData = zentralknotenData;
*
*/
DataManagement::DataManagement(vector<TariffData> tariffData, vector<ZentralknotenData> zentralknotenData){

	SetTariffData( tariffData);
	SetZentralknotenData(zentralknotenData);
}
/** Dies ist ein Destruktor
*
*/
DataManagement::~DataManagement(){

	tariffData.clear();
	zentralknotenData.clear();
}

void DataManagement::SetTariffData(vector<TariffData> tariffData){

	DataManagement::tariffData = tariffData;
}
void DataManagement::AppendTariffData(TariffData tariffData){

	DataManagement::tariffData.push_back(tariffData);
}
/*bool DataManagement::SetTariffData_byId(TariffData tariffData){
	
	int position = find(DataManagement::tariffData.begin(), 
						DataManagement::tariffData.end(), 
						tariffData) -DataManagement::tariffData.begin();

	if (position == (DataManagement::tariffData.end() - DataManagement::tariffData.begin()))
		return false;

	DataManagement::tariffData[position] = tariffData;

	return true;
}*/
/*vector<TariffData> DataManagement::GetTariffData(){}
string DataManagement::GetTariffData_string(){}
TariffData DataManagement::GetTariffData_byId(int identifier){}
*/
void DataManagement::SetZentralknotenData(vector<ZentralknotenData> zentralknotenData){

	DataManagement::zentralknotenData = zentralknotenData;
}/*
bool DataManagement::AppendZentralknotenData(ZentralknotenData zentralknotenData){}
void DataManagement::SetZentralknotenData_byId(ZentralknotenData zentralknotenData){

	
}
/*vector<TariffData> DataManagement::GetZentralknotenData(){}
string DataManagement::GetZentralknotenData_string(){}
ZentralknotenData DataManagement::GetZentralknotenData_byId(int identifier){}*/