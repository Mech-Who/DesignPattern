#include <iostream>
#include "Builder.h"

using namespace std;

/// <summary>
/// WoodBuilder
/// </summary>
void Builder::setHead() {
	robot->parts.emplace_back(new Head());
}
void Builder::setLeftArm() {
	robot->parts.emplace_back(new Arm());
}
void Builder::setRightArm() {
	robot->parts.emplace_back(new Arm());
}
void Builder::setBody() {
	robot->parts.emplace_back(new Body());
}
void Builder::setLeftLeg() {
	robot->parts.emplace_back(new Leg());
}
void Builder::setRightLeg() {
	robot->parts.emplace_back(new Leg());
}
void Builder::setLeftFoot() {
	robot->parts.emplace_back(new Foot());
}
void Builder::setRightFoot() {
	robot->parts.emplace_back(new Foot());
}
void Builder::reset() {
	robot = new Robot();
}
Robot* Builder::getRobot() {
	Robot* result = robot;
	reset();
	return result;
}

/// <summary>
/// Manager
/// </summary>
void Manager::setBuilder(BuilderBase* newBuilder)
{
	builder = newBuilder;
}
void Manager::makeFullRobot()
{
	builder->setHead();
	builder->setBody();
	builder->setLeftArm();
	builder->setRightArm();
	builder->setLeftLeg();
	builder->setLeftFoot();
	builder->setRightLeg();
	builder->setRightFoot();
}
void Manager::makeHalfRobot()
{
	builder->setHead();
	builder->setBody();
	builder->setLeftArm();
	builder->setRightArm();
}

/// <summary>
/// Robot
/// </summary>
Robot::~Robot() {
	for(Part* i: parts){
		if (i != nullptr)
			delete i;
	}
}

void Robot::report()
{
	for(Part* i: parts){
		if (i != nullptr)
			i->report();
	}
}

/// <summary>
/// Parts
/// </summary>
void Head::report() {
	cout << "This is Head!" << endl;
}
void Arm::report() {
	cout << "This is Arm!" << endl;
}
void Body::report() {
	cout << "This is Body!" << endl;
}
void Leg::report() {
	cout << "This is Leg!" << endl;
}
void Foot::report() {
	cout << "This is Foot!" << endl;
}
