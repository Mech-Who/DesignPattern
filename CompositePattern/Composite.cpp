#include <iostream>
#include "Composite.h"

using namespace std;

void Leaf::execute() const
{
	cout << "Leaf: " << name << endl;
}

void Composite::add(Component* c)
{
	components.push_back(c);
}

void Composite::remove(Component* c)
{
	int offset = 0;
	for (int i = 0; i != components.size(); ++i) {
		if (offset > 0)
			components[i - offset] = components[i];
		if (components[i] == c) {
			offset++;
		}
	}
}

std::vector<Component*> Composite::getChildren() const
{
	return components;
}

void Composite::execute() const
{
	cout << "Pack: " << endl << endl;
	const vector<Component*> tmp = getChildren();
	for(const Component* i : tmp)
	{
		i->execute();
	}
	cout << endl;
}
