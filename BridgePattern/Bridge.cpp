#include <iostream>
#include "Bridge.h"

using namespace std;

double Rectangle::getArea() const
{
	return this->height * this->weight;
}

double Circle::getArea() const
{
	return radius * radius * PI;
}

void Rectangle::report() const 
{
	cout << color->getName() << " Rectangle!" << endl;
}

void Circle::report() const
{
	cout << color->getName() << " Circle!" << endl;
}
