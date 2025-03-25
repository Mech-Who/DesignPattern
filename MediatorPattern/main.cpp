#include "Mediator.h"
#include <iostream>

using namespace std;

void ClientCode() 
{
	ComponentA* a = new ComponentA();
	ComponentB* b = new ComponentB();
	Mediator* m = new ConcreteMediator(a, b);

	cout << "Component A Operation A:" << endl;
	a->DoA();
	cout << "Component A Operation B:" << endl;
	a->DoB();
	cout << "Component B Operation C:" << endl;
	b->DoC();
	cout << "Component B Operation D:" << endl;
	b->DoD();

	delete m;
	delete b;
	delete a;
}

int main() 
{
	ClientCode();
	return 0;
}
