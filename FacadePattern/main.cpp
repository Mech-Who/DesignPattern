#include <iostream>
#include <limits>
#include "Facade.h"

using namespace std;

void ClientCode(Facade* facade){
	cout << facade->Operation() << endl;
}

int main() 
{
	SubSystemA* sA = new SubSystemA();
	SubSystemB* sB = new SubSystemB();

	Facade* facade = new Facade(sA, sB);
	ClientCode(facade);

	delete facade;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}
