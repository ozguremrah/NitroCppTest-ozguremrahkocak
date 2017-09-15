#include "JsonReader.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace Test;

std::vector <std::string> JsonReader::errorCodes;

JsonReader::JsonReader()
{
}


JsonReader::~JsonReader()
{
}

std::vector <std::shared_ptr<Rectangle>> JsonReader::readJsonFile(const std::string& fileName)
{
	//clear error list for each file read
	errorCodes.empty();
	std::vector <std::shared_ptr<Rectangle>> rectList; //container to hold rectangles from file
	rectList.reserve(MAX_RECTANGLE_SIZE);


	//// read a JSON file
	try
	{
		std::ifstream in(fileName);
		json j;
		in >> j;
		json rects = j["rects"];

		//check if the file contains "rects" array
		if (rects.is_null())
			throw std::runtime_error("Cannot find rects array.");

		//validate input & create rectangles from JSON file
		for (unsigned int i = 0; i < rects.size() && i < MAX_RECTANGLE_SIZE; ++i)
		{
			json rect = rects[i];

			//check if values are integers
			json number = rect["x"];
			if (!number.is_number_integer())
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " does not contain integer x value.");

			int x = number;

			number = rect["y"];
			if (!number.is_number_integer())
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " does not contain integer y value.");

			int y = number;

			number = rect["w"];
			if (!number.is_number_integer())
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " does not contain integer w value.");

			int w = number;

			number = rect["h"];
			if (!number.is_number_integer())
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " does not contain integer h value.");

			int h = number;

			//check if width and height are positive
			if (w <= 0)
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " contains non positive width.");
			if (h <= 0)
				throw std::runtime_error("Rectangle " + std::to_string(i + 1) + " contains non positive height.");

			//create rectangles
			rectList.push_back(std::make_shared<Rectangle>(std::vector<int>(1, i + 1), x, y, x + w, y + h));

		}


	}
	catch (std::exception& e)
	{
		std::string errorCode(e.what());
		std::cerr << errorCode << std::endl;
		errorCodes.push_back(errorCode);
		//there is a problem with the file content, empty rectangle list
		rectList.clear();
	}

	printInput(rectList);

	return rectList;
}

void JsonReader::printInput(const std::vector <std::shared_ptr<Rectangle>> & rectangles)
{
	std::cout << "Input:" << std::endl;
	for (unsigned int i = 0; i < rectangles.size(); ++i)
	{
		std::cout << "\t" << i + 1 << ": Rectangle at " <<
			"(" << rectangles[i]->getX1() << "," << rectangles[i]->getY1() << "), " <<
			"w=" << rectangles[i]->getW() << ", h=" << rectangles[i]->getH() << "." << std::endl;
	}
}
