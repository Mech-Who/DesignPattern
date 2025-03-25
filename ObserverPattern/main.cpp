#include "Observer.h"
#include <iostream>

using namespace std;

void ClientCode() 
{
	Publisher *p = new Publisher();

	p->ChangeState();

	Observer* o1 = new ConcreteObserver();
	Observer* o2 = new ConcreteObserver();
	Observer* o3 = new ConcreteObserver();

	p->AddObserver(o1);
	p->ChangeState();

	p->AddObserver(o2);
	p->AddObserver(o3);
	p->ChangeState();

	delete o3,o2,o1;
	delete p;
}

int main() 
{
	ClientCode();
	return 0;
}
