#pragma once
#ifndef __FACADE_H__
#define __FACADE_H__

#include <string>

struct SubSystemA
{
	std::string Operation1() const {
		return "SubSystemA: Ready!\n";
	}
	// ...
	std::string OperationN() const {
		return "SubSystemA: Go!\n";
	}
};

struct SubSystemB
{
	std::string Operation1() const {
		return "SubSystemB: Ready!\n";
	}
	// ...
	std::string OperationN() const {
		return "SubSystemB: Fire!\n";
	}
};

struct Facade
{
	Facade(SubSystemA* sA = nullptr, SubSystemB* sB = nullptr);
	~Facade();
	std::string Operation();
protected:
	SubSystemA* subsystemA;
	SubSystemB* subsystemB;
};

#endif // __FACADE_H__
