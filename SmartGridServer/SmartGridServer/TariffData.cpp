/** TariffData.cpp (TR 15-June-2015)
*
* Edited by:
*
*		Zuordnung von Tarifdatens�tzen und Netzauslastungsprofilen zu eindeutigen IDs
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
* Die Variablen der Klasse erhalten hier die �bergebenen Werte:
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
/** Dies ist ein Destruktor
*
*/
TariffData::~TariffData(){
	identifier = 0;
	tariffCourse.clear();
	networkLoadCourse.clear();
}

/** Diese Methode setzt identifier auf den Wert der �bergabe
*
*/
void TariffData::SetIdentifier(int identifier){

	TariffData::identifier = identifier;
}
/** Diese Methode gibt den Wert von identifier zur�ck
*
*/
int TariffData::GetIdentifier(){
	
	return identifier;
}
/** Diese Methode gibt den Wert von identifier als String zur�ck
*
*/
string TariffData::GetIdentifier_string(){

	return to_string(identifier);
}

/** Diese Methode setzt tariffCourse auf den Wert der �bergabe, falls die L�ngen �bereinstimmen
*
*/
void TariffData::SetTariffCourse(vector<float> tariffCourse){
	
		TariffData::tariffCourse = tariffCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse zur�ck
*
*/
vector<float>  TariffData::GetTariffCourse(){

	return tariffCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse als String zur�ck
*
*/
string	TariffData::GetTariffCourse_string(){

	StringConverter converter;

	return converter.toString(tariffCourse);
}

/** Diese Methode setzt tariffCourse auf den Wert der �bergabe, falls die Laengen �bereinstimmen
*
*/
void TariffData::SetNetworkLoadCourse(vector<float> networkLoadCourse){

	TariffData::networkLoadCourse = networkLoadCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse zur�ck
*
*/
vector<float>  TariffData::GetNetworkLoadCourse(){
	return networkLoadCourse;
}
/** Diese Methode gibt den Wert von GetTariffCourse als String zur�ck
*
*/
string TariffData::GetNetworkLoadCourse_string(){
	StringConverter converter;

	return converter.toString(networkLoadCourse);
}

bool operator== (TariffData &obj1, TariffData &obj2)
{

	return (obj1.GetIdentifier() == obj2.GetIdentifier());
}

bool operator!= (TariffData &obj1, TariffData &obj2)
{

	return !(obj1 == obj2);
}