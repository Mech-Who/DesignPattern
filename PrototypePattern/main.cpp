#include <iostream>
#include "Prototype.h"

using namespace std;

int main() 
{
	PrototypeFactory* factory = new PrototypeFactory();
	Prototype* robot = factory->createPrototype("robot");
	robot->work();
	Prototype* machine = factory->createPrototype("machine");
	machine->work();
	delete robot;
	delete machine;
	delete factory;

	return 0;
}
