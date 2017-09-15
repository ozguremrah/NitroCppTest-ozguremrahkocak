#pragma once
#include <vector>
#include <memory>

namespace Test
{ 
class Rectangle
{
public:
	Rectangle(std::vector<int> id, int x1, int y1, int x2, int y2);
	~Rectangle();

	/*
		Calculates intersection with another rectangle.
		If there is an intersection it is added to the intersection vector.
		An intersection is also a rectangle.
	*/
	virtual std::shared_ptr<Rectangle> calculateIntersection(const std::shared_ptr<Rectangle> rectangle);

	//Accessor functions
	int getX1();
	int getY1();
	int getW();
	int getH();
	std::vector <int> getID();


private:
	//Adds a new id to ID vector
	void addID(int id);

	int width, height;
	int x1, y1, x2, y2; // x1, y1 top left corner
						// x2, y2 bottom right corner

	std::vector <int> ID; //single ID -> input rectangle
						  //multiple ID -> intersection rectangle
};

}