#include "Memento.h"
#include <iostream>

using namespace std;

void ClientCode()
{
	ConcreteOriginator* o = new ConcreteOriginator();
	Caretaker* ct = new Caretaker(o);

	cout << "First save..." << endl;
	ct->save();
	cout << "save..." << endl;
	o->DoSomething();
	ct->save();
	cout << "save..." << endl;
	o->DoSomething();
	ct->save();
	
	ct->showHistory();

	cout << "undo..." << endl;
	ct->undo();
	ct->showHistory();
	ct->undo();
	ct->showHistory();
	ct->undo();

	cout << "over" << endl;

	delete ct;
	delete o;
}

int main() 
{
	ClientCode();
	return 0;
}
