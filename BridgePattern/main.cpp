#include <iostream>
#include "Bridge.h"

using namespace std;

int main() 
{
	Shape* s1 = new Rectangle();
	Shape* s2 = new Circle();
	Color* red = new Red();
	Color* yellow = new Yellow();
	
	s1->setColor(red);
	s2->setColor(yellow);

	s1->report();
	s2->report();

	delete yellow;
	delete red;
	delete s2;
	delete s1;
	return 0;
}
