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

StringConverter::StringConverter(){
	delimiterL = "[";
	delimiterR = "]";
	separator  = ",";
}
StringConverter::StringConverter(string delimiterL, string delimiterR, string separator){
	StringConverter::delimiterL = delimiterL;
	StringConverter::delimiterR = delimiterR;
	StringConverter::separator = separator;
}

string StringConverter::toString(vector<float> vector){


	ostringstream oss;

	if (!vector.empty()){

		oss << delimiterL;

		copy(vector.begin(), vector.end() - 1, ostream_iterator<int>(oss, separator.c_str()));

		oss << vector.back() << delimiterR;		//Füge letztes Element ohne Begrenzer ein
	}

	return oss.str();
}