#include "Memento.h"
#include <iostream>

using namespace std;

Caretaker::Caretaker(Originator* o)
: originator(o) {}

void Caretaker::undo()
{
	Memento* tmp = history.back();
	history.pop_back();
	tmp->restore();
	delete tmp;
}

void Caretaker::save()
{
	Memento* tmp = originator->save();
	history.push_back(tmp);
}

void Caretaker::showHistory()
{
	for (Memento* m: history)
	{
		cout << "state: " << m->get() << endl;
	}
}

ConcreteOriginator::ConcreteOriginator(int state /*= 0*/): state(state) {}

Memento* ConcreteOriginator::save()
{
	return new ConcreteMemento(this, GetState());
}

void ConcreteOriginator::DoSomething()
{
	if (state == 0) state = 1;
	else if (state == 1) state = 2;
	else if (state == 2) state = 0;
}

ConcreteMemento::ConcreteMemento(ConcreteOriginator* o, int state): originator(o), state(state) {}

void ConcreteMemento::restore()
{
	originator->SetState(state);
}

int ConcreteMemento::get()
{
	return state;
}
