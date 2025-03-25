#include <iostream>
#include "Composite.h"

using namespace std;

int main() 
{
	Composite* prod = new Composite();

	Composite* pac1 = new Composite();
	Leaf* apple = new Leaf("apple");
	Leaf* banana = new Leaf("banana");
	pac1->add(apple);
	pac1->add(banana);

	Leaf* orange = new Leaf("orange");
	Leaf* watermelon = new Leaf("watermelon");

	prod->add(pac1);
	prod->add(orange);
	prod->add(watermelon);

	prod->execute();

	delete pac1;
	delete prod;
	return 0;
}
