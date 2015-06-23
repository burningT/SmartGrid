#include "StringConverter.h"
#include "TariffData.h"
#include "ZentralknotenData.h"
#include "DataManagement.h"

using namespace std;
#include <iostream>

void StringConverter_toString_Test();
void StringConverter_toVector_Test();
void TariffData_operators_Test();
void DataManagement_SetZentralknotenData_byId_Test();
void DataManagement_SetTariffData_byId_Test();
void TariffDate_TariffData();


void main(int argc, const char* argv[])
{
	StringConverter_toString_Test();
	StringConverter_toVector_Test();
	TariffData_operators_Test();
	DataManagement_SetZentralknotenData_byId_Test();
	DataManagement_SetTariffData_byId_Test();
	TariffDate_TariffData();

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
void StringConverter_toVector_Test(){
	////////////////////////////////////
	/*Test StringConverter.toVector*/
	StringConverter converter;

	vector < float > testVectorF{ 1.3f, 2.2f, 3.1f };
	string stringF = converter.toString(testVectorF);
	vector<string> testVectorS{ stringF, "abc", "def", "42", "Ein Satz!" };
	string testS = converter.toString(testVectorS);

	vector<string> result1Vector = converter.toVector(testS);
	bool realResult1_bool = false;


	cout << "Test StringConverter.toVector: ";

	int i;

	if (result1Vector.size() == testVectorS.size()){

		i = 0;
		realResult1_bool = true;

		for (i = 0; i < result1Vector.size() && realResult1_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			realResult1_bool = (result1Vector[i].compare(testVectorS[i])) == 0;
		}
	}

	if (realResult1_bool)
		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";
		
		cout << "\n";

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
	int realResult1 = (dataset1.equals(dataset2));

	dataset2.SetIdentifier(124);
	int expResult2 = (12 == 13);
	int realResult2 = (dataset1.equals(dataset2));

	cout << "Test StringConverter.operators: ";

	if (expResult1 == realResult1 &&
		expResult2 == realResult2)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << " Ausgabe: " << realResult1 << ", "
		<< realResult2 << ", " << "\n";

	return;
}

void DataManagement_SetZentralknotenData_byId_Test(){
	////////////////////////////////////
	/*Test DataManagement.SetZentralknotenData_byId*/	
	
	ZentralknotenData zentralknoten1 = ZentralknotenData((int)124, (int)0, vector<int>());
	ZentralknotenData zentralknoten2 = ZentralknotenData((int)125, (int)0, vector<int>());

	vector<ZentralknotenData> zentralknoten1_vector{ ZentralknotenData((int)123, (int)0, vector<int>()),
													 ZentralknotenData((int)125, (int)123, vector<int>()),
													 ZentralknotenData((int)224, (int)123, vector<int>()) };

	DataManagement dataset1(vector<TariffData>(), zentralknoten1_vector);
	
	// Test mit Element ohne passenden Index
	bool expResult11 = false;
	vector<ZentralknotenData> expResult12 = zentralknoten1_vector;
	bool realResult11 = dataset1.SetZentralknotenData_byId(zentralknoten1);
	bool realResult12_bool = false; // Initialer Wert, durchlaeuft spaeter Schleife
	vector<ZentralknotenData> realResult12;
	realResult12 = dataset1.GetZentralknotenData();

	// Test mit Element mit passendem Index
	bool expResult21 = true;
	vector<ZentralknotenData> expResult22 = zentralknoten1_vector;
	expResult22[1] = zentralknoten2;
	bool realResult21 = dataset1.SetZentralknotenData_byId(zentralknoten2);
	bool realResult22_bool = false; // Initialer Wert, durchlaeuft spaeter Schleife
	vector<ZentralknotenData> realResult22;
	realResult22 = dataset1.GetZentralknotenData();





	cout << "Test DataManagement.SetZentralknotenData_byId: ";

	int i;

	if (realResult12.size() == expResult12.size()){

		i = 0;
		realResult12_bool = true;

		for (i = 0; i < realResult12.size() && realResult12_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			realResult12_bool = (realResult12[i].equals(expResult12[i]));
		}
	}
	if (realResult22.size() == expResult22.size()){

		i = 0;
		realResult22_bool = true;

		for (i = 0; i < realResult22.size() && realResult22_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			realResult22_bool = (realResult22[i].equals(expResult22[i]));
		}
	}

	if (expResult11 == realResult11 &&
		realResult12_bool &&
		expResult21 == realResult21 &&
		realResult22_bool)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << "\n";

	return;
}
void DataManagement_SetTariffData_byId_Test(){
	////////////////////////////////////
	/*Test DataManagement.SetTariffData_byId*/
	
	TariffData tariff1 = TariffData((int)124, vector < float > {1.2f}, vector<float>());
	TariffData tariff2 = TariffData((int)125, vector<float>{1.2f}, vector<float>());

	vector<TariffData> tariff1_vector{ TariffData((int)123, vector<float>{4.2f}, vector<float>()),
		TariffData((int)125, vector<float>{4.2f}, vector<float>()),
		TariffData((int)224, vector<float>{4.2f}, vector<float>()) };

	DataManagement dataset1(tariff1_vector, vector<ZentralknotenData>());
	
	// Test mit Element ohne passenden Index
	bool expResult11 = false;
	vector<TariffData> expResult12 = tariff1_vector;
	bool realResult11 = dataset1.SetTariffData_byId(tariff1);
	bool realResult12_bool = false; // Initialer Wert, durchlaeuft spaeter Schleife
	vector<TariffData> realResult12;
	realResult12 = dataset1.GetTariffData();
	
	// Test mit Element mit passendem Index
	bool expResult21 = true;
	vector<TariffData> expResult22 = tariff1_vector;
	expResult22[1] = tariff2;
	bool realResult21 = dataset1.SetTariffData_byId(tariff2);
	bool realResult22_bool = false; // Initialer Wert, durchlaeuft spaeter Schleife
	vector<TariffData> realResult22;
	realResult22 = dataset1.GetTariffData();



	

	cout << "Test DataManagement.SetTariffData_byId: ";

	int i;

	if (realResult12.size() == expResult12.size()){

		i = 0;
		realResult12_bool = true;

		for (i = 0; i < realResult12.size() && realResult12_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			realResult12_bool = (realResult12[i].equals(expResult12[i]));
		}
	}
	if (realResult22.size() == expResult22.size()){

		i = 0;
		realResult22_bool = true;

		for (i = 0; i < realResult22.size() && realResult22_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			realResult22_bool = (realResult22[i].equals(expResult22[i]));
		}
	}

	if (expResult11 == realResult11 &&
		realResult12_bool &&
		expResult21 == realResult21 &&
		realResult22_bool)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << "\n";
	
	return;
}
void TariffDate_TariffData(){
	////////////////////////////////////
	/*Test TariffData.TariffData*/

	TariffData tariff1 = TariffData((int)124, vector < float > {1.2f, 1.3f, 2.2f, 3.1f}, vector < float > {1.7f, 1.47f, 5.2f, 8.1586f});
	string tariff1_string = tariff1.toString();
	TariffData tariff_result(tariff1_string);

	bool result1TariffCourse_bool = false;
	bool result1NetworkLoadCourse_bool = false;

	cout << "Test TariffData.TariffData: ";

	int i;

	if (tariff_result.GetTariffCourse().size() == tariff1.GetTariffCourse().size()){

		i = 0;
		result1TariffCourse_bool = true;

		for (i = 0; i < tariff_result.GetTariffCourse().size() && result1TariffCourse_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			result1TariffCourse_bool = (tariff_result.GetTariffCourse()[i] == tariff1.GetTariffCourse()[i]);
		}
	}
	if (tariff_result.GetNetworkLoadCourse().size() == tariff1.GetNetworkLoadCourse().size()){

		i = 0;
		result1NetworkLoadCourse_bool = true;

		for (i = 0; i < tariff_result.GetNetworkLoadCourse().size() && result1NetworkLoadCourse_bool; i++){	//Durchlaufe Vectoren, bis Ende erreicht oder Fehler in Uebereinstimmung geunden

			result1NetworkLoadCourse_bool = (tariff_result.GetNetworkLoadCourse()[i] == tariff1.GetNetworkLoadCourse()[i]);
		}
	}

	if (tariff_result.GetIdentifier() == tariff1.GetIdentifier() &&
		result1TariffCourse_bool &&
		result1NetworkLoadCourse_bool)

		cout << "ERFOLGREICH";
	else
		cout << "fehlgeschlagen";

	cout << "\n";

	return;
}