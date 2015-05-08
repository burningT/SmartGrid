#ifndef UNIT_TEST_INO_SETUP_H
#define UNIT_TEST_INO_SETUP_H

/**
* Headerfile zum Importieren der Unit-Test-Einstellungen, falls nicht Arduino als Compiler genutzt wird
* Diese Headerfile sollte als erstes in die .ino included werden
**/

#ifndef ARDUINO
#include "../_UnitTests/UnitTestSetup.h"
#endif

#endif