#include "Visitor.h"
#include <iostream>

void ConcreteComponentA::accept(Visitor* visitor) const
{
	visitor->visitConcreteComponentA(this);
}

std::string ConcreteComponentA::ExclusiveMethodOfConcreteComponentA() const
{
	return "A";
}

void ConcreteComponentB::accept(Visitor* visitor) const
{
	visitor->visitConcreteComponentB(this);
}

std::string ConcreteComponentB::SpecialMethodOfConcreteComponentB() const
{
	return "B";
}

void ConcreteVisitorA::visitConcreteComponentA(const ConcreteComponentA* element) const
{
	std::cout << element->ExclusiveMethodOfConcreteComponentA()
		<< " + ConcreteVisitorA" << std::endl;
}

void ConcreteVisitorA::visitConcreteComponentB(const ConcreteComponentB* element) const
{
	std::cout << element->SpecialMethodOfConcreteComponentB()
		<< " + ConcreteVisitorA" << std::endl;
}

void ConcreteVisitorB::visitConcreteComponentA(const ConcreteComponentA* element) const
{
	std::cout << element->ExclusiveMethodOfConcreteComponentA()
		<< " + ConcreteVisitorB" << std::endl;
}

void ConcreteVisitorB::visitConcreteComponentB(const ConcreteComponentB* element) const
{
	std::cout << element->SpecialMethodOfConcreteComponentB()
		<< " + ConcreteVisitorB" << std::endl;
}
