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

TariffData::TariffData(){
	identifier = 0;
	tariffCourse.resize(COURSE_LEN);
	networkLoadCourse.resize(COURSE_LEN);
}

TariffData::TariffData(int identifier, vector<float>  tariffCourse, vector<float> networkLoadCourse){
	SetIdentifier(identifier);
	SetTariffCourse(tariffCourse);
	SetNetworkLoadCourse(networkLoadCourse);
}

void TariffData::SetIdentifier(int identifier){

	TariffData::identifier = identifier;
}
int TariffData::GetIdentifier(){
	
	return identifier;
}
string TariffData::GetIdentifier_string(){

	return to_string(identifier);
}

void TariffData::SetTariffCourse(vector<float> tariffCourse){
	
	if (tariffCourse.capacity() == COURSE_LEN){
		TariffData::tariffCourse = tariffCourse;
	}
}
vector<float>  TariffData::GetTariffCourse(){

	return tariffCourse;
}
string	TariffData::GetTariffCourse_string(){

	StringConverter converter;

	return converter.toString(tariffCourse);
}

void TariffData::SetNetworkLoadCourse(vector<float> networkLoadCourse){

	if (networkLoadCourse.capacity() == COURSE_LEN){
		TariffData::networkLoadCourse = networkLoadCourse;
	}
}
vector<float>  TariffData::GetNetworkLoadCourse(){
	return networkLoadCourse;
}
string TariffData::GetNetworkLoadCourse_string(){
	StringConverter converter;

	return converter.toString(networkLoadCourse);
}