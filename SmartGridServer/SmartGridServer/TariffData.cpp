/** TariffData.cpp (TR 15-June-2015)
*
* Edited by:
*
*		Zuordnung von Tarifdatensätzen und Netzauslastungsprofilen zu eindeutigen IDs
*
*
*
*/

#include "TariffData.h"

/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	identifier = 0;
*	tariffCourse.resize(COURSE_LEN);
*	networkLoadCourse.resize(COURSE_LEN);
*
*/
TariffData::TariffData(){
	identifier = 0;
	tariffCourse.resize(COURSE_LEN);
	networkLoadCourse.resize(COURSE_LEN);
}
/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die übergebenen Werte:
*	identifier = identifier;
*	tariffCourse = tariffCourse;
*	networkLoadCourse = networkLoadCourse;
*
*/
TariffData::TariffData(int identifier, vector<float>  tariffCourse, vector<float> networkLoadCourse){
	SetIdentifier(identifier);
	SetTariffCourse(tariffCourse);
	SetNetworkLoadCourse(networkLoadCourse);
}
/** Dies ist ein Konstruktor
*
* String vom Format der toString Funktion wird erwartet.
*
*/
TariffData::TariffData(string in_string){

	StringConverter converter;
	vector<string> in_vector;
	vector<string> bufferString_vector;
	vector<float> bufferFloat_vector;

	in_vector = converter.toVector(in_string);

	if (in_vector.size() != 3){	//Falls Vektor-Laenge nicht Argumentmenge entspricht, nutze leeren Konstruktor
		TariffData();
	}
	else{
		SetIdentifier( atoi(in_vector[0].c_str()) );	//Setze Identifier

		bufferString_vector = converter.toVector(in_vector[1]);	//Setze Tarifkurs
		bufferFloat_vector.resize(bufferString_vector.size());

		for (int i = 0; i < bufferString_vector.size(); i++)
		{
			bufferFloat_vector[i] = stof(bufferString_vector[i]);
		}

		SetTariffCourse(bufferFloat_vector);

		bufferString_vector = converter.toVector(in_vector[2]);	//Setze NEtzwerklastprofil
		bufferFloat_vector.resize(bufferString_vector.size());

		for (int i = 0; i < bufferString_vector.size(); i++)
		{
			bufferFloat_vector[i] = stof(bufferString_vector[i]);
		}

		SetNetworkLoadCourse(bufferFloat_vector);
	}
}
/** Dies ist ein Destruktor
*
*/
TariffData::~TariffData(){
	identifier = 0;
	tariffCourse.clear();
	networkLoadCourse.clear();
}

/** Diese Methode setzt identifier auf den Wert der Übergabe
*
*/
void TariffData::SetIdentifier(int identifier){

	TariffData::identifier = identifier;
}
/** Diese Methode gibt den Wert von identifier zurück
*
*/
int TariffData::GetIdentifier(){
	
	return identifier;
}
/** Diese Methode gibt den Wert von identifier als String zurück
*
*/
string TariffData::GetIdentifier_string(){

	return to_string(identifier);
}

/** Diese Methode setzt tariffCourse auf den Wert der Übergabe, falls die Längen übereinstimmen
*
*/
void TariffData::SetTariffCourse(vector<float> tariffCourse){
	
		TariffData::tariffCourse = tariffCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse zurück
*
*/
vector<float>  TariffData::GetTariffCourse(){

	return tariffCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse als String zurück
*
*/
string	TariffData::GetTariffCourse_string(){

	StringConverter converter;

	return converter.toString(tariffCourse);
}

/** Diese Methode setzt tariffCourse auf den Wert der Übergabe, falls die Laengen übereinstimmen
*
*/
void TariffData::SetNetworkLoadCourse(vector<float> networkLoadCourse){

	TariffData::networkLoadCourse = networkLoadCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse zurück
*
*/
vector<float>  TariffData::GetNetworkLoadCourse(){
	return networkLoadCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse als String zurück
*
*/
string TariffData::GetNetworkLoadCourse_string(){
	StringConverter converter;

	return converter.toString(networkLoadCourse);
}

bool TariffData::equals(TariffData obj1){

	return (obj1.GetIdentifier() == identifier);
}

string TariffData::toString(){

	StringConverter converter;
	vector <string> bufferVector{ GetIdentifier_string(), GetTariffCourse_string(), GetNetworkLoadCourse_string() };

	return converter.toString(bufferVector);
}