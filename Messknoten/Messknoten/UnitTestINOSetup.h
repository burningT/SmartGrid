#ifndef UNIT_TEST_INO_SETUP_H
#define UNIT_TEST_INO_SETUP_H

/**
* Headerfile zum Importieren der Unit-Test-Einstellungen, falls nicht Arduino als Compiler genutzt wird
* Diese Headerfile sollte als erstes in die cpp-Dateien included werden
**/

#ifndef ARDUINO				//Lade Headerfile, falls nicht in Arduino-Umgebung

#include "../../_UnitTests/SmartGridUnitTests/unitTestSetup.h"
#endif

#ifdef UNIT_TEST_ACTIVE		//Definiere Export-Einstellungen entsprechend den Unit-Test Einstellungen

#undef CPP_UNIT_TEST_EXPORT
#define CPP_UNIT_TEST_EXPORT __declspec(dllexport)
#else
#define CPP_UNIT_TEST_EXPORT
#endif

#endif