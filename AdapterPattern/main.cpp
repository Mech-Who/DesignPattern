#include <iostream>
#include "Adapter.h"

using namespace std;

int main() 
{
	RoundHole hole = RoundHole(10);
	cout << "Round hole radius: " << hole.getRadius() << endl;
	RoundPeg* rPeg1 = new RoundPeg(5);
	RoundPeg* rPeg2 = new RoundPeg(15);
	cout << "rPeg1(" << rPeg1->getRadius() << ") fits:" << hole.fits(rPeg1) << endl;
	cout << "rPeg2(" << rPeg2->getRadius() << ") fits:" << hole.fits(rPeg2) << endl;
	SquarePeg sPeg1 = SquarePeg(5);
	SquarePeg sPeg2 = SquarePeg(15);
	SquarePegAdapter* sAdaPeg1 = new SquarePegAdapter(sPeg1);
	SquarePegAdapter* sAdaPeg2 = new SquarePegAdapter(sPeg2);
	cout << "sPeg1(" << sAdaPeg1->getRadius() << ") with adapter fits:" << hole.fits(sAdaPeg1) << endl;
	cout << "sPeg2(" << sAdaPeg2->getRadius() << ") with adapter fits:" << hole.fits(sAdaPeg2) << endl;
	delete rPeg1;
	delete rPeg2;
	delete sAdaPeg1;
	delete sAdaPeg2;
	return 0;
}
