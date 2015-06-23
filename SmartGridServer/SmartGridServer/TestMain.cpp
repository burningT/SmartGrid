#include "StringConverter.h"
#include "TariffData.h"
#include "ZentralknotenData.h"
#include "DataManagement.h"

using namespace std;
#include <iostream>

void StringConverter_toString_Test();
void TariffData_operators_Test();
void DataManagement_SetZentralknotenData_byId_Test();


void main(int argc, const char* argv[])
{
	StringConverter_toString_Test();
	TariffData_operators_Test();
	DataManagement_SetZentralknotenData_byId_Test();

	return;
}

void StringConverter_toString_Test(){
	////////////////////////////////////
	/*Test StringConverter.toString*/
	StringConverter converter;

	vector < float > testVectorF{ 1.3f, 2.2f, 3.1f };
	string finalStringF = "[1.3,2.2,3.1]";
	string resultStringF = converter.toString(testVectorF);

	vector < int > testVectoINT{ 1, 2, 3 };
	string finalStringINT = "[1,2,3]";
	string resultStringINT = converter.toString(testVectoINT);

	vector < string > testVectorS{ "ab", "cd", "Ef" };
	string finalStringS = "[ab,cd,Ef]";
	string resultStringS = converter.toString(testVectorS);


	cout << "Test StringConverter.toString: ";

	if (finalStringF.compare(resultStringF) == 0 &&
		finalStringINT.compare(resultStringINT) == 0 &&
		finalStringS.compare(resultStringS) == 0)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << " Ausgabe: " << resultStringF << ", "
		<< resultStringINT << ", "
		<< resultStringS << "\n";

	return;
}
void TariffData_operators_Test(){
	////////////////////////////////////
	/*Test TariffData.operators*/
	vector<float>  tariffCourse{ 1.1f, 1.2f, 2.3f };
	vector<float> networkLoadCourse{ 7.7f, 7.9f, 5.4f };

	TariffData dataset1(123, tariffCourse, networkLoadCourse);
	TariffData dataset2;


	dataset2.SetIdentifier(123);
	int expResult1 = (12 == 12);
	int realResult1 = (dataset1 == dataset2);
	int realResult11 = (dataset1 != dataset2);

	dataset2.SetIdentifier(124);
	int expResult2 = (12 == 13);
	int realResult2 = (dataset1 == dataset2);
	int realResult21 = (dataset1 != dataset2);

	cout << "Test StringConverter.operators: ";

	if (expResult1 == realResult1 &&
		!expResult1 == realResult11 &&
		expResult2 == realResult2 &&
		!expResult2 == realResult21)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << " Ausgabe: " << realResult1 << ", "
		<< realResult11 << ", "
		<< realResult2 << ", "
		<< realResult21 << ", " << "\n";

	return;
}

void DataManagement_SetZentralknotenData_byId_Test(){
	////////////////////////////////////
	/*Test DataManagement.SetZentralknotenData_byId*/	
	
	vector<ZentralknotenData> zentralknoten1{ ZentralknotenData(123,0,vector<int>()),
											  ZentralknotenData(125, 123, vector<int>()),
											  ZentralknotenData(224, 123, vector<int>())};

	DataManagement dataset1(vector<TariffData> (), zentralknoten1);


	bool expResult11 = false;
	vector<ZentralknotenData> expResult12 = zentralknoten1;
	bool realResult11 = false;//dataset1.SetZentralknotenData_byId(ZentralknotenData(124, 0, vector<int>()));
	//vector<ZentralknotenData> realResult12;
	vector<ZentralknotenData> realResult12;
	//realResult12 = dataset1.GetZentralknotenData();


	/*dataset2.SetIdentifier(124);
	int expResult2 = (12 == 13);
	int realResult2 = (dataset1 == dataset2);
	int realResult21 = (dataset1 != dataset2);*/

	cout << "Test DataManagement.SetZentralknotenData_byId: ";

	if (expResult11 == realResult11 /*&&
		expResult12 == realResult12 /*&&
		expResult21 == realResult21 &&
		expResult22 == realResult22*/)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << "\n";

	return;
}
