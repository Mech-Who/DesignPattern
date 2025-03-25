#include "TemplateMethod.h"
#include <iostream>

void AbstractMethod::TemplateMethod() const
{
	this->BaseOperation1();
	this->RequiredOperations1();
	this->BaseOperation2();
	this->Hook1();
	this->RequiredOperation2();
	this->BaseOperation3();
	this->Hook2();
}

void AbstractMethod::BaseOperation1() const
{
	std::cout << "AbstractClass says: I am doing the bulk of the work\n";
}

void AbstractMethod::BaseOperation2() const
{
	std::cout << "AbstractClass says: But I let subclasses override some operations\n";
}

void AbstractMethod::BaseOperation3() const
{
	std::cout << "AbstractClass says: But I am doing the bulk of the work anyway\n";
}

void AbstractMethod::Hook1() const {}

void AbstractMethod::Hook2() const {}

void ConcreteMethodA::RequiredOperations1() const
{
	std::cout << "ConcreteClassA says: Implemented Operation1\n";
}

void ConcreteMethodA::RequiredOperation2() const
{
	std::cout << "ConcreteClassA says: Implemented Operation2\n";
}

void ConcreteMethodB::RequiredOperations1() const
{
	std::cout << "ConcreteClassB says: Implemented Operation1\n";
}

void ConcreteMethodB::RequiredOperation2() const
{
	std::cout << "ConcreteClassB says: Implemented Operation2\n";
}

void ConcreteMethodB::Hook1() const {
	std::cout << "ConcreteClassB says: Overridden Hook1\n";
}