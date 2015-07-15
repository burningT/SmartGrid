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

	for (int i = 0; i < vector.size(); i++)	//iteriert durch den Vektor und fuegt jedes Element mit Separator ein
		string_out += vector[i] + separator;

	string_out.erase(string_out.size()-1,1);	//lösche letzten Separator

	string_out += delimiterR;

	return string_out;
}

vector<string> StringConverter::toVector(string in_string){

	vector<string> string_vector;
	string string_buffer="";
	int delimiterL_count = 0; //Haelt die Anzahl der linken Begrenzer gegenüber der rechter Begrenzer
	char c =0;

	for (int i = 0; i < in_string.length(); i++){
		c = in_string[i];

		//Begrenzer-Zähler
		if (c == delimiterL[0]){
			delimiterL_count++;
		}
		else if (c == delimiterR[0]){
			delimiterL_count--;
		}

		if ((c == delimiterL[0] || c == separator[0]) && delimiterL_count == 1){	//Falls linker Begrenzer oder Separator gefunden, lege string_buffer in Vector
			if (string_buffer.length() > 0){
				string_vector.push_back(string_buffer);
				string_buffer = "";
			}
		}
		else if (c == delimiterR[0] && delimiterL_count == 0){ //Falls letzterrechter Begrenzer gefunden, lege string_buffer in Vector und return
			if (string_buffer.length() > 0){			
				string_vector.push_back(string_buffer);
			}

			return string_vector;
		}
		else{											//Falls keine besonderen Charakter gefunden, Haenge an String an
			string_buffer += c;
		}
	}

	return string_vector;
}
