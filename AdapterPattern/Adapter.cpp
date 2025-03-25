#include <cmath>
#include <iostream>
#include "Adapter.h"

bool RoundHole::fits(RoundPeg* peg) const 
{
	std::cout << peg->getRadius() << "<" << getRadius() << std::endl;
	if ((peg->getRadius() - getRadius()) < -0.00001)
		return true;
	else
		return false;
}

