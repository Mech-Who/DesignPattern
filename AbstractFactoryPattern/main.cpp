#include <iostream>
#include "AbstractFactory.h"

using namespace std;

void clientCode(Factory* factory) 
{
	Chair* chair = factory->createChair();
	chair->doBuseness();
	delete chair;

	Table* table = factory->createTable();
	table->doBuseness();
	delete table;

	Sofa* sofa = factory->createSofa();
	sofa->doBuseness();
	delete sofa;
}

int main() 
{
	Factory* redFac = new RedFactory();
	clientCode(redFac);
	delete redFac;
	Factory* blueFac = new BlueFactory();
	clientCode(blueFac);
	delete blueFac;
	Factory* greenFac = new GreenFactory();
	clientCode(greenFac);
	delete greenFac;
	cout << "Hello World!" << endl;
	return 0;
}
