
#include "Messknoten.h"

Messknoten::Messknoten()
{

}

void Messknoten::SyncDaytime(int Daytime)
{

}

void Messknoten::CalcCurrentConsumption(int currentConsumption)
{
	/*Dies ist eine Ma�einheit der Arbeit bzw. der Energie. 
	Kilo-Watt-Stunde (kWh) bedeutet "1000 Watt w�hrend einer Stunde".
	Dies entspricht der Energie, welche ein System (z. B. Maschine, Gl�hlampe, etc.) 
	mit einer Leistung von einem Kilo-Watt w�hrend einer Stunde verbraucht.
	
	currentConsumption = (current Measurement/1000)/ 36000 (Seconds);
	
	*/

	
}

void Messknoten::TransmitDisplayCurrentConsumption(int currentConsumption)
{
}

void Messknoten::TransmitZentralknotenCurrentConsumption(int currentConsumption)
{
}

void Messknoten::CalcCostIfUsedNow(float costIfUsedNow, float tariffCourse, int currentConsumption)
{
	/*F�r die Ausrechnung der Stromkosten, die ein Ger�t verursacht, multipliziert man
	den Stromverbrauch des Ger�tes mit dem Preis pro Kilowattstunde (kWh) (Stromtarif).
	
	
	costIfUsedNow = currentConsumption * tariffCourse; 
	*/
}

void Messknoten::TransmitDisplayCostIfUsedNow(float costIfUsedNow)
{
}

void Messknoten::TransmitZentralknotenCostIfUsedNow(float costIfUsedNow)
{
}

void Messknoten::GenerateLedSiganal(int LedSignal)
{
}

void Messknoten::GenerateBeep(int BeepSignal)
{

}

