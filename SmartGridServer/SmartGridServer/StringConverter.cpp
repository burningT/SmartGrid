/** StringConverter.cpp (TR 15-June-2015)
*
* Edited by:
*
*                  Pool von String-Konvertierungen
*
*
*
*/
#include "StringConverter.h"

/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	delimiterL = "[";
*	delimiterR = "]";
*	separator  = ",";
*
*/
StringConverter::StringConverter(){
	
	delimiterL = "[";
	delimiterR = "]";
	separator  = ",";
}

/** Dies ist ein Konstruktor
*
* Die Variablen der Klasse erhalten hier die folgenden Werte:
*	delimiterL = delimiterL;
*	delimiterR = delimiterR;
*	separator  = separator;
*
*/
StringConverter::StringConverter(string delimiterL, string delimiterR, string separator){
	StringConverter::delimiterL = delimiterL;
	StringConverter::delimiterR = delimiterR;
	StringConverter::separator = separator;
}
/** Dies ist ein Destruktor
*
*/
StringConverter::~StringConverter(){
	delimiterL = "";
	delimiterR = "";
	separator = "";
}

/**
*	Diese Methode konvertiert einen Vektor mit floats in einen String
*/
string StringConverter::toString(vector<float> vector){

	ostringstream oss;

	if (!vector.empty()){

		oss << delimiterL;	//Füge linken delimiter ein
														//Füge Elemente mit Trennzeichen ein
		copy(vector.begin(), vector.end() - 1, ostream_iterator<float>(oss, separator.c_str()));

		oss << vector.back() << delimiterR;		//Füge letztes Element mit rechtem delimiter ein
	}

	return oss.str();
}

/**
*	Diese Methode konvertiert einen Vektor mit ints in einen String
*/
string StringConverter::toString(vector<int> vector){

	ostringstream oss;

	if (!vector.empty()){

		oss << delimiterL;	//Füge linken delimiter ein
		//Füge Elemente mit Trennzeichen ein
		copy(vector.begin(), vector.end() - 1, ostream_iterator<int>(oss, separator.c_str()));

		oss << vector.back() << delimiterR;		//Füge letztes Element mit rechtem delimiter ein
	}

	return oss.str();
}

/**
*	Diese Methode konvertiert einen Vektor mit Strings in einen String
*/
string StringConverter::toString(vector<string> vector){

	string string_out = delimiterL;

	for (const auto &piece : vector)	//iteriert durch den Vektor und fügt jedes Element mit Separator ein
		string_out += piece + separator;

	string_out.erase(string_out.size()-1,1);	//lösche letzten Separator

	string_out += delimiterR;

	return string_out;
}