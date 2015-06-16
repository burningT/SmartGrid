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
* Die Variablen der Klasse erhalten hier die �bergebenen Werte:
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
/** Dies ist ein Destruktor
*
*/
ZentralknotenData::~ZentralknotenData(){
	identifier = 0;
	group = 0;
	ratingOfEconomy.clear();
}

/** Diese Methode setzt identifier auf den Wert der �bergabe
*
*/
void ZentralknotenData::SetIdentifier(int identifier){

	ZentralknotenData::identifier;
}
/** Diese Methode gibt den Wert von identifier zur�ck
*
*/
int ZentralknotenData::GetIdentifier(){

	return identifier;
}
/** Diese Methode gibt den Wert von identifier als String zur�ck
*
*/
string ZentralknotenData::GetIdentifier_string(){

	return to_string(identifier);
}

/** Diese Methode setzt group auf den Wert der �bergabe
*
*/
void ZentralknotenData::SetGroup(int group){

	ZentralknotenData::group = group;
}
/** Diese Methode gibt den Wert von group zur�ck
*
*/
int ZentralknotenData::GetGroup(){

	return group;
}
/** Diese Methode gibt den Wert von group als String zur�ck
*
*/
string ZentralknotenData::GetGroup_string(){

	return to_string(group);
}

/** Diese Methode setzt ratingOfEconomy auf den Wert der �bergabe
*
*/
void ZentralknotenData::SetRatingOfEconomy(vector<int> ratingOfEconomy){
	
	ZentralknotenData::ratingOfEconomy = ratingOfEconomy;
}
/** Diese Methode h�ngt ratingOfEconomy den Wert der �bergabe an
*
*/
void ZentralknotenData::AppendRatingOfEconomy(int ratingOfEconomy){

	ZentralknotenData::ratingOfEconomy.push_back(ratingOfEconomy);
}
/** Diese Methode gibt den Wert von ratingOfEconomy zur�ck
*
*/
vector<int> ZentralknotenData::GetRatingOfEconomy(){

	return ratingOfEconomy;
}
/** Diese Methode gibt den Wert von ratingOfEconomy als String zur�ck
*
*/
string ZentralknotenData::GetRatingOfEconomy_string(){

	StringConverter converter;

	return converter.toString(ratingOfEconomy);
}