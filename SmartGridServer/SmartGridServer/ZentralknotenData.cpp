/** ZentralknotenData.cpp (TR 16-June-2015)
*
* Edited by:
*
*                  Datensatz eines Zentralknotens, bestehend aus Identifier, Gruppe und Verlauf der Oekonomie
*
*
*
*/
#include "ZentralknotenData.h"

/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	identifier = 0;
*	group = 0;	
*	ratingOfEconomy.clear();
*
*/
ZentralknotenData::ZentralknotenData(){
	identifier = 0;
	group = 0;	
	ratingOfEconomy.clear();
}
/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die übergebenen Werte:
*	identifier = identifier;
*	group = group;
*	ratingOfEconomy = ratingOfEconomy;
*
*/
ZentralknotenData::ZentralknotenData(int identifier, int group, vector<int> ratingOfEconomy){
	SetIdentifier(identifier);
	SetGroup(group);
	SetRatingOfEconomy(ratingOfEconomy);
}
/** Dies ist ein Konstruktor
*
* String vom Format der toString Funktion wird erwartet.
*
*/
ZentralknotenData::ZentralknotenData(string in_string){

	StringConverter converter;
	vector<string> in_vector;
	vector<string> bufferString_vector;
	vector<int> bufferInt_vector;

	in_vector = converter.toVector(in_string);

	if (in_vector.size() != 3){	//Falls Vektor-Laenge nicht Argumentmenge entspricht, nutze leeren Konstruktor
		ZentralknotenData();
	}
	else{
		SetIdentifier(atoi(in_vector[0].c_str()));	//Setze Identifier

		SetGroup(atoi(in_vector[1].c_str()));		//Setze group

		bufferString_vector = converter.toVector(in_vector[2]);	//Setze Bewertung der Oekonomie
		bufferInt_vector.resize(bufferString_vector.size());

		for (int i = 0; i < bufferString_vector.size(); i++)
		{
			bufferInt_vector[i] = atoi(bufferString_vector[0].c_str());
		}

		SetRatingOfEconomy(bufferInt_vector);
	}
}
/** Dies ist ein Destruktor
*
*/
ZentralknotenData::~ZentralknotenData(){
	identifier = 0;
	group = 0;
	ratingOfEconomy.clear();
}

/** Diese Methode setzt identifier auf den Wert der Übergabe
*
*/
void ZentralknotenData::SetIdentifier(int identifier){

	ZentralknotenData::identifier=identifier;
}
/** Diese Methode gibt den Wert von identifier zurück
*
*/
int ZentralknotenData::GetIdentifier(){

	return identifier;
}
/** Diese Methode gibt den Wert von identifier als String zurück
*
*/
string ZentralknotenData::GetIdentifier_string(){

	return to_string(identifier);
}

/** Diese Methode setzt group auf den Wert der Übergabe
*
*/
void ZentralknotenData::SetGroup(int group){

	ZentralknotenData::group = group;
}
/** Diese Methode gibt den Wert von group zurück
*
*/
int ZentralknotenData::GetGroup(){

	return group;
}
/** Diese Methode gibt den Wert von group als String zurück
*
*/
string ZentralknotenData::GetGroup_string(){

	return to_string(group);
}

/** Diese Methode setzt ratingOfEconomy auf den Wert der Übergabe
*
*/
void ZentralknotenData::SetRatingOfEconomy(vector<int> ratingOfEconomy){
	
	ZentralknotenData::ratingOfEconomy = ratingOfEconomy;
}
/** Diese Methode hängt ratingOfEconomy den Wert der Übergabe an
*
*/
void ZentralknotenData::AppendRatingOfEconomy(int ratingOfEconomy){

	ZentralknotenData::ratingOfEconomy.push_back(ratingOfEconomy);
}
/** Diese Methode gibt den Wert von ratingOfEconomy zurück
*
*/
vector<int> ZentralknotenData::GetRatingOfEconomy(){

	return ratingOfEconomy;
}
/** Diese Methode gibt den Wert von ratingOfEconomy als String zurück
*
*/
string ZentralknotenData::GetRatingOfEconomy_string(){

	StringConverter converter;

	return converter.toString(ratingOfEconomy);
}

bool ZentralknotenData::equals(ZentralknotenData obj1)
{

	return (obj1.GetIdentifier() == identifier);
}

string ZentralknotenData::toString(){

	StringConverter converter;
	vector <string> bufferVector{ GetIdentifier_string(), GetGroup_string(), GetRatingOfEconomy_string() };

	return converter.toString(bufferVector);
}
