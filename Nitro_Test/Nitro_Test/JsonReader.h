/*
	Using JSON for Modern C++ Version 2.1.1 by nlohmann 
	Source: https://github.com/nlohmann/json/releases
*/

#pragma once
#include "json.hpp"
#include "Rectangle.h"
#include <string>

#define MAX_RECTANGLE_SIZE 10

namespace Test
{ 

using json = nlohmann::json;

class JsonReader
{
public:
	JsonReader();
	~JsonReader();

	/**
		Reads Json file that contains "rects" array of rectangle definitions.
		Checks file correctness, stores & returns all rectangles.
		@param fileName: Name of the JSON file
		@return array of rectangles
	*/
	static std::vector <std::shared_ptr<Rectangle>> readJsonFile(const std::string& fileName);

	static std::vector <std::string> errorCodes; //Container to hold error codes for unit testing purposes

private:

	/**
		Prints out given rectangles.
		@param rectangles: Input rectangles
	*/
	static void printInput(const std::vector <std::shared_ptr<Rectangle>> & rectangles);
};

}