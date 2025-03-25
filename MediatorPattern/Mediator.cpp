#include "Mediator.h"
#include <iostream>

using namespace std;

void BaseComponent::SetMediator(Mediator* m)
{
	mediator = m;
}

void ComponentA::DoA()
{
	cout << "Do A event!" << endl;
	mediator->Notify(this, "A");
}

void ComponentA::DoB()
{
	cout << "Do B event!" << endl;
	mediator->Notify(this, "B");
}

void ComponentB::DoC()
{
	cout << "Do C event!" << endl;
	mediator->Notify(this, "C");
}

void ComponentB::DoD()
{
	cout << "Do D event!" << endl;
	mediator->Notify(this, "D");
}

ConcreteMediator::ConcreteMediator(ComponentA* a, ComponentB* b): cA(a), cB(b)
{
	cA->SetMediator(this);
	cB->SetMediator(this);
}

void ConcreteMediator::Notify(BaseComponent* sender, std::string event)
{
	cout << "Sender: " << sender << endl;
	if (event == "A")
	{
		cout << "Event A:" << endl;
		cB->DoC();
	}
	if (event == "B")
	{
		cout << "Event B:" << endl;
	}
	if (event == "C") 
	{
		cout << "Event C:" << endl;
	}
	if (event == "D")
	{
		cout << "Event D:" << endl;
		cA->DoB();
	}
}
