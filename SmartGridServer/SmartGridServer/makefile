all:	MainTest

	
MainTest:  TestMain.o ZentralknotenData.o StringConverter.o GroupData.o DataManagement.o TariffData.o xmlParser.o
	g++ -Wall -o -std=c++11 TestMain.o ZentralknotenData.o StringConverter.o GroupData.o DataManagement.o TariffData.o xmlParser.o -o MainTest

TestMain.o: TestMain.cpp
	g++ -Wall -o -std=c++11 TestMain.cpp
	
TariffData.o: TariffData.cpp
	g++ -Wall -o -std=c++11 TariffData.cpp

ZentralknotenData.o: ZentralknotenData.cpp
	g++ -Wall -o -std=c++11 ZentralknotenData.cpp

StringConverter.o: StringConverter.cpp
	g++ -Wall -o -std=c++11 StringConverter.cpp
    
GroupData.o: GroupData.cpp
	g++ -Wall -o -std=c++11 GroupData.cpp
    
DataManagement.o: DataManagement.cpp
	g++ -Wall -o -std=c++11 -L "../librarys/xmlParser" -I "../librarys/xmlParser" DataManagement.cpp
	#g++ -Wall -o -std=c++11 DataManagement.cpp
	
xmlParser.o: ../librarys/xmlParser/xmlParser.cpp
	g++ -Wall -o -std=c++11 ../librarys/xmlParser/xmlParser.cpp


clean:
	#rm *o MainTest
