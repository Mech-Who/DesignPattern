#include <iostream>

#include "FactoryMethod.h"

using namespace std;

void clentCode(Factory* factory) 
{
	Product* pro = factory->makeProduct();
	pro->doBusiness();
	delete pro;
}

int factoryMethod()
{
	cout << "App: Launched with the FactoryA.\n";
	Factory* facA = new FactoryA();
	clentCode(facA);
	cout << endl;
	cout << "App: Launched with the FactoryB.\n";
	Factory* facB = new FactoryB();
	clentCode(facB);


	delete facA;
	delete facB;
	return 0;
}

int main()
{
	factoryMethod();
	return 0;
}
