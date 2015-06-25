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

/** Diese Methode setzt tariffData auf den Wert der Uebergabe
*
*/
void DataManagement::SetTariffData(vector<TariffData> tariffData){

	DataManagement::tariffData = tariffData;
}
/** Diese Methode hängt tariffData den Wert der Uebergabe an
*
*/
void DataManagement::AppendTariffData(TariffData tariffData){

	DataManagement::tariffData.push_back(tariffData);
}
/** Diese Methode setzt ein Element von tariffData auf den Wert der Uebergabe, falls dere nIndexe uebereinstimmen
*
*/
bool DataManagement::SetTariffData_byId(TariffData tariffData){
	
	int i = 0;
	bool bool_found = false;

	//Durchlaufe Vectoren, bis Ende erreicht oder Uebereinstimmung gefunden (liegt dann bei i-1) 
	for (i = 0; i < DataManagement::tariffData.size() && !bool_found; i++){

		bool_found = DataManagement::tariffData[i].equals(tariffData);
	}


	if (!bool_found)	//Gebe false zurueck, wenn Element nicht gefunden wurde
		return false;

	DataManagement::tariffData[i - 1] = tariffData;

	return true;
}
/** Diese Methode gibt tariffData zurück
*
*/
vector<TariffData> DataManagement::GetTariffData(){

	return tariffData;
}
/** Diese Methode gibt tariffData als string zurück
*
*/
string DataManagement::GetTariffData_string(){

	StringConverter converter;
	int tariffData_len = tariffData.size();

	vector<string> bufferVector(tariffData_len);

	for (int i = 0; i < tariffData_len; i++){

		bufferVector[i] = tariffData[i].toString();
	}

	return converter.toString(bufferVector);
}
/** Diese Methode gibt ein Element aus tariffData zurueck, dessen Identifier mit der Uebergabe uebereinstimmt
*
*/
TariffData DataManagement::GetTariffData_byId(int identifier){

	int i = 0;
	bool bool_found = false;

	//Durchlaufe Vectoren, bis Ende erreicht oder Uebereinstimmung gefunden (liegt dann bei i-1) 
	for (i = 0; i < tariffData.size() && !bool_found; i++){

		bool_found = (tariffData[i].GetIdentifier() == identifier);
	}


	if (!bool_found)	//Gebe nichts zurueck, wenn Element nicht gefunden wurde
		return TariffData();

	return tariffData[i - 1];
}
//bool readFile_TariffData(string path, string tag){
/*XMLNode readFile_TariffData(string path, string tag){		//Nicht implementiert wegen INCLUDE-Problemen
	
	XMLNode xmlTree;
	XMLResults xmlResults;

	wchar_t* test = {0};

	xmlTree = XMLNode::parseFile((wchar_t*)path.c_str(), (wchar_t*)tag.c_str(), &xmlResults);


	return xmlTree;
	//return true;
}*/

/** Diese Methode setzt zentralknotenData auf den Wert der Uebergabe
*
*/
void DataManagement::SetZentralknotenData(vector<ZentralknotenData> zentralknotenData){

	DataManagement::zentralknotenData = zentralknotenData;
}
/** Diese Methode hängt zentralknotenData den Wert der Uebergabe an
*
*/
void DataManagement::AppendZentralknotenData(ZentralknotenData zentralknotenData){

	DataManagement::zentralknotenData.push_back(zentralknotenData);
}
/** Diese Methode setzt ein Element von zentralknotenData auf den Wert der Uebergabe, falls deren Indexe uebereinstimmen
*
*/
bool DataManagement::SetZentralknotenData_byId(ZentralknotenData zentralknotenData){

	int i = 0;
	bool bool_found = false;

	//Durchlaufe Vectoren, bis Ende erreicht oder Übereinstimmung gefunden (liegt dann bei i-1) 
	for (i = 0;  i < DataManagement::zentralknotenData.size() && !bool_found; i++){	

		bool_found = DataManagement::zentralknotenData[i].equals(zentralknotenData);
	}


	if (!bool_found)	//Gebe false zurueck, wenn Element nicht gefunden wurde
		return false;

	DataManagement::zentralknotenData[i-1] = zentralknotenData;

	return true;
}
/** Diese Methode gibt zentralknotenData zurück
*
*/
vector<ZentralknotenData> DataManagement::GetZentralknotenData(){

	return zentralknotenData;
}
/** Diese Methode gibt zentralknotenData als string zurück
*
*/
string DataManagement::GetZentralknotenData_string(){

	StringConverter converter;
	int zentralknotenData_len = zentralknotenData.size();

	vector<string> bufferVector(zentralknotenData_len);

	for (int i = 0; i < zentralknotenData_len; i++){

		bufferVector[i] = zentralknotenData[i].toString();
	}

	return converter.toString(bufferVector);
}
/** Diese Methode gibt ein Element aus zentralknotenData zurueck, dessen Identifier mit der Uebergabe uebereinstimmt
*
*/
ZentralknotenData DataManagement::GetZentralknotenData_byId(int identifier){

	int i = 0;
	bool bool_found = false;

	//Durchlaufe Vectoren, bis Ende erreicht oder Uebereinstimmung gefunden (liegt dann bei i-1) 
	for (i = 0; i < zentralknotenData.size() && !bool_found; i++){

		bool_found = (zentralknotenData[i].GetIdentifier() == identifier);
	}


	if (!bool_found)	//Gebe nichts zurueck, wenn Element nicht gefunden wurde
		return ZentralknotenData();

	return zentralknotenData[i - 1];
}