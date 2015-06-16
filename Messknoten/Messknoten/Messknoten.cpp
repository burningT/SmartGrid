
#include "Messknoten.h"

Messknoten::Messknoten()
{

}

void Messknoten::SyncDaytime(int Daytime)
{

}

void Messknoten::CalcCurrentConsumption(int currentConsumption)
{
	/*Dies ist eine Maßeinheit der Arbeit bzw. der Energie. 
	Kilo-Watt-Stunde (kWh) bedeutet "1000 Watt während einer Stunde".
	Dies entspricht der Energie, welche ein System (z. B. Maschine, Glühlampe, etc.) 
	mit einer Leistung von einem Kilo-Watt während einer Stunde verbraucht.
	
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
	/*Für die Ausrechnung der Stromkosten, die ein Gerät verursacht, multipliziert man
	den Stromverbrauch des Gerätes mit dem Preis pro Kilowattstunde (kWh) (Stromtarif).
	
	
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

