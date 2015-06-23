#include "stdafx.h"
#include "CppUnitTest.h"
//#include "../../SmartGridServer/Mockups/[...]"
//#pragma comment(lib, "../../SmartGridServer/Mockups/Debug/SmartGridServerMockups.lib")
#include "../../SmartGridServer/SmartGridServer/StringConverter.h"
#pragma comment(lib, "../../SmartGridServer/Debug/SmartGridServer.lib")

#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SmartGridServerTest
{
	TEST_CLASS(SmartGridServer_StringConverter)
	{
	public:
		StringConverter converter;

		TEST_METHOD(toString)
		{
			vector < float > testVector {1,2,3};
			string finalString = "[1,2,3]";

			//Assert::AreEqual(converter.toString(testVector),finalString);
		}

	};
}