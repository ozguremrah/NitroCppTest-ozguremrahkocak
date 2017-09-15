#pragma once
#include "Rectangle.h"

namespace Test
{


class IntersectionFinder
{
public:
	explicit IntersectionFinder();
	~IntersectionFinder();

	/**
		Finds all intersections over a given rectangle list and prints output.
		@param rectangleList: Array of rectangles to be compared 
	*/
	void findAllIntersections(const std::vector <std::shared_ptr<Rectangle>> & rectangleList);

	std::vector <std::shared_ptr<Rectangle>> getIntersections();

private:

	/**
		Recursive function.
		Given a rectangle, it finds all intersections over the rectangle list, starting
		from index. Index must be larger then current rectangle's position.
		@param rectangle: The base rectangle that will be used for comparison
		@param index: Starting position on rectangle list
	*/
	virtual void findIntersections(const std::shared_ptr<Rectangle> & rectangle, unsigned int index);

	virtual void printIntersections();
	std::vector <std::shared_ptr<Rectangle>> m_intersections;
	std::vector <std::shared_ptr<Rectangle>> m_rectangleList;

};

}