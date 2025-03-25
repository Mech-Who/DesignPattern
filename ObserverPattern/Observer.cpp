#include "Observer.h"
#include <algorithm>
#include <iostream>

void Publisher::Notify()
{
	for(auto observer : observers)
	{
		observer->Update(this);
	}
}

void Publisher::AddObserver(Observer* o)
{
	observers.push_back(o);
}

void Publisher::RemoveObserver(Observer* o)
{
	auto it = std::find(observers.begin(), observers.end(), o);
	observers.erase(it, it + 1);
}

void Publisher::ChangeState()
{
	std::cout << "\nPublisher change state!" << std::endl;
	if (state == 0) state = 1;
	else if (state == 1) state = 2;
	else if (state == 2) state = 3;
	else if (state == 3) state = 0;
	Notify();
}

void ConcreteObserver::Update(Publisher* p)
{
	std::cout << "Get publisher state: " << p->GetState() << std::endl;
}
