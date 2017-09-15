#include <iostream>
#include "IntersectionFinder.h"

using namespace Test;

IntersectionFinder::IntersectionFinder() : m_intersections(), m_rectangleList()
{
}


IntersectionFinder::~IntersectionFinder()
{
}

void IntersectionFinder::findAllIntersections(const std::vector <std::shared_ptr<Rectangle>> & rectangleList)
{
	//clear intersection list for each function call
	m_intersections.clear();
	m_rectangleList = rectangleList;
	//find intersections for all rectangles in the list
	for (unsigned int i = 0; i < m_rectangleList.size(); ++i)
		findIntersections(m_rectangleList[i], i + 1);
	printIntersections();

}

void IntersectionFinder::findIntersections(const std::shared_ptr<Rectangle> & rectangle, unsigned int index)
{
	for (index; index < m_rectangleList.size(); ++index)
	{
		//calculate intersection with the rectangle at given index
		std::shared_ptr<Rectangle> intersectRect = rectangle->calculateIntersection(m_rectangleList[index]);
		if (NULL != intersectRect)
		{
			//if there is an intersection, store it
			m_intersections.push_back(intersectRect);
			//find intersections for new intersection rectangle, starting from next rectangle
			findIntersections(intersectRect, (index + 1));
		}
	}
}

void IntersectionFinder::printIntersections()
{
	std::cout << "Intersections:" << std::endl;
	for (unsigned int i = 0; i < m_intersections.size(); ++i)
	{
		std::cout << "\tBetween rectangle ";
		int intersectionNo = m_intersections[i]->getID().size();
		for (int j = 0; j < intersectionNo; ++j)
		{
			if (j != 0)
			{
				if (j < intersectionNo - 1)
					std::cout << ", ";
				else
					std::cout << " and ";
			}
			std::cout << m_intersections[i]->getID()[j];
		}
		std::cout << " at (" << m_intersections[i]->getX1() << ", " << m_intersections[i]->getY1() << "), ";
		std::cout << "w=" << m_intersections[i]->getW() << ", h=" << m_intersections[i]->getH() << "." << std::endl;
	}

}

std::vector <std::shared_ptr<Rectangle>> IntersectionFinder::getIntersections()
{
	return m_intersections;
}