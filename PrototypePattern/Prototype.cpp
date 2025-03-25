#include <iostream>
#include "Prototype.h"

using namespace std;

/// <summary>
/// Prototypes
/// </summary>
Prototype* Robot::clone() const {
	return new Robot(this);
}

void Robot::work() {
	cout << "Prototype name: " << name << ", robot type: " << type << endl;
}

Prototype* Machine::clone() const {
	return new Machine(this);
}

void Machine::work() {
	cout << "Prototype name: " << name << ", machine usage: " << usage << endl;
}

/// <summary>
/// PrototypeFactory
/// </summary>
/// <param name="type_name">type name of prototype</param>
/// <returns>Prototype object</returns>
Prototype* PrototypeFactory::createPrototype(std::string type_name) {
	return prototypes[type_name]->clone();
}
