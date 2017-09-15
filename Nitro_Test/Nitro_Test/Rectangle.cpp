#include <algorithm>
#include "Rectangle.h"

using namespace Test;


Rectangle::Rectangle(std::vector<int> id, int x1, int y1, int x2, int y2) 
{
	this->ID = id;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	width = x2 - x1;
	height = y2 - y1;
}


Rectangle::~Rectangle()
{
}

void Rectangle::addID(int id)
{
	ID.push_back(id);
}

std::shared_ptr<Rectangle> Rectangle::calculateIntersection(const std::shared_ptr<Rectangle> rectangle)
{
	std::shared_ptr<Rectangle> intersectRect = NULL;

	if ((x1 <= rectangle->x2 && y2 >= rectangle->y1) &&
		(x2 >= rectangle->x1 && y1 <= rectangle->y2))
	{
		//create intersection rectangle
		intersectRect = std::shared_ptr<Rectangle>(new Rectangle(ID, std::max(x1, rectangle->x1),
																	std::max(y1, rectangle->y1),
																	std::min(x2, rectangle->x2),
																	std::min(y2, rectangle->y2)));
		//add intersecting rectangle ID
		intersectRect->addID(rectangle->ID.front());
	}

	return intersectRect;
}

int Rectangle::getX1()
{
	return x1;
}

int Rectangle::getY1()
{
	return y1;
}

int Rectangle::getW()
{
	return width;
}

int Rectangle::getH()
{
	return height;
}

std::vector <int> Rectangle::getID()
{
	return ID;
}