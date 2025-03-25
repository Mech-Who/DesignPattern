#include "Facade.h"

Facade::Facade(SubSystemA* sA, SubSystemB* sB) {
	subsystemA = sA ? sA : new SubSystemA();
	subsystemB = sB ? sB : new SubSystemB();
}

Facade::~Facade() {
	delete subsystemA;
	delete subsystemB;
}

std::string Facade::Operation() {
	std::string res = "Facade initialize subsystems:\n";
	res += subsystemA->Operation1();
	res += subsystemB->Operation1();
	res += "Facade orders subsystems to do actions:\n";
	res += subsystemA->OperationN();
	res += subsystemB->OperationN();
	return res;
}
