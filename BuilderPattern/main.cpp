#include <iostream>
#include "Builder.h"

using namespace std;

int main() 
{
	Builder* builder = new Builder();
	Manager manager = Manager(builder);

	// full robot
	cout << "Full robot:" << endl;
	manager.makeFullRobot();
	Robot* robot1 = builder->getRobot();
	robot1->report();
	delete robot1;
	robot1 = nullptr;

	// half robot
	cout << "Half robot:" << endl;
	manager.makeHalfRobot();
	Robot* robot2 = builder->getRobot();
	robot2->report();
	delete robot2;
	robot2 = nullptr;

	// custom robot
	cout << "Custom robot:" << endl;
	builder->setHead();
	builder->setBody();
	Robot* robot3 = builder->getRobot();
	robot3->report();
	delete robot3;
	robot3 = nullptr;

	delete builder;
	return 0;
}
