#include "Visitor.h"
#include <array>
#include <iostream>

void ClientCode(std::array<const Component*, 2> components, Visitor* visitor) {
	for (const Component* comp : components) {
		comp->accept(visitor);
	}
}

int main() 
{
	std::array<const Component*, 2> components = { new ConcreteComponentA, new ConcreteComponentB };
	std::cout << "The client code works with all visitors via the base Visitor interface:\n";
	ConcreteVisitorA* visitor1 = new ConcreteVisitorA;
	ClientCode(components, visitor1);
	std::cout << "\n";
	std::cout << "It allows the same client code to work with different types of visitors:\n";
	ConcreteVisitorB* visitor2 = new ConcreteVisitorB;
	ClientCode(components, visitor2);

	for (const Component* comp : components) {
		delete comp;
	}
	delete visitor1;
	delete visitor2;
	return 0;
}
