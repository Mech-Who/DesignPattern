#include <iostream>
#include "FactoryMethod.h"

using namespace std;

void ProA::doBusiness() const
{
	cout << "do A business!" << endl;
}

void ProB::doBusiness() const 
{
	cout << "do B business!" << endl;
}

Product* FactoryA::makeProduct() const
{
	return new ProA();
}

Product* FactoryB::makeProduct() const
{
	return new ProB();
}
