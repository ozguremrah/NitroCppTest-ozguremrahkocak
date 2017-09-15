/*
	Using Boost 1.65.1 Unit Test Framework
*/

#ifdef _UNIT_TEST

#include "JsonReader.h"
#include "IntersectionFinder.h"

using namespace Test;

#define BOOST_TEST_MODULE JsonReaderTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/results_reporter.hpp>



struct LogToFile
{
	LogToFile()
	{
		std::string logFileName("Test_Results.xml");
		logFile.open(logFileName.c_str());
		boost::unit_test::unit_test_log.set_stream(logFile);
	}
	~LogToFile()
	{
		boost::unit_test::unit_test_log.test_finish();
		logFile.close();
		boost::unit_test::unit_test_log.set_stream(std::cout);
	}
	std::ofstream logFile;
};

BOOST_GLOBAL_FIXTURE(LogToFile);

BOOST_AUTO_TEST_SUITE(NitroTest)

BOOST_AUTO_TEST_CASE(IntersectionTest)
{
	JsonReader jr;

	IntersectionFinder finder;

	//Open config file and get JSON file names, expected array sizes and number of intersections
	std::ifstream infile("test_config_intersection.txt");
	if (!infile.is_open())
		BOOST_TEST_MESSAGE("Cannot open test_config_intersection.txt");
	else
	{
		std::string fileName;
		int arraySize; //expected array size
		int intersectionNo; //expected number of intersections

		while (infile >> fileName >> arraySize >> intersectionNo)
		{
			//Check size;
			//if size is larger than MAX_RECTANGLE_SIZE, take MAX_RECTANGLE_SIZE
			arraySize = ((arraySize > MAX_RECTANGLE_SIZE) ? MAX_RECTANGLE_SIZE : arraySize);
			BOOST_TEST_MESSAGE("Checking size of valid rectangle array from file " + fileName);
			//Check if two size values are same
			BOOST_CHECK_MESSAGE(jr.readJsonFile(fileName).size() == arraySize, "Expected size is " << arraySize);

			//Check number of intersections;
			//for an array of n identical rects the number of intersections is 
			//		C(n,2) + C(n,3) + ... + C(n,n)
			BOOST_TEST_MESSAGE("Checking intersections from file " + fileName);
			finder.findAllIntersections(jr.readJsonFile(fileName));
			BOOST_CHECK_MESSAGE(finder.getIntersections().size() == intersectionNo, "Expected number of intersections is " << intersectionNo);
		}
	infile.close();
	}
	
}


BOOST_AUTO_TEST_CASE(FileIntegrityTest)
{
	JsonReader jr;

	//Open config file and get JSON file names and expected error messages
	std::ifstream infile("test_config_fileIntegrity.txt");
	if (!infile.is_open())
		BOOST_TEST_MESSAGE("Cannot open test_config_fileIntegrity.txt");
	else
	{
		std::string fileName;
		std::string errorMsg; //expected error message
		while (infile)
		{
			infile >> fileName;
			std::getline(infile, errorMsg);
			jr.readJsonFile(fileName);
			if (0 == jr.errorCodes.size())
				BOOST_ERROR("No error message for the file " + fileName);
			else
			{
				//Check if two messages are same
				BOOST_TEST_MESSAGE("Checking error messages from " + fileName);
				BOOST_CHECK_MESSAGE( errorMsg.compare(jr.errorCodes.back()), "Expected message is " << errorMsg);
			}
		}
		infile.close();
	}
}

BOOST_AUTO_TEST_SUITE_END()

#endif