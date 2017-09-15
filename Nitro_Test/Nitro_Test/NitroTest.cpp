// NitroTest.cpp : Defines the entry point for the console application.
//

#ifndef _UNIT_TEST

#include "JsonReader.h"
#include "IntersectionFinder.h"

using namespace Test;

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Missing command line argument." << std::endl << "Usage: Nitro_Test name_of_your_JSON_file" << std::endl;
		return 1;
	}

	IntersectionFinder finder;
	finder.findAllIntersections(JsonReader::readJsonFile(std::string(argv[1])));

	system("PAUSE");

	return 0;
}

#endif

