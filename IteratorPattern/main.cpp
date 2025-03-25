#include "Iterator.h"
#include <iostream>

using namespace std;

void ClientCode()
{
	PhoneContainer<int> counter;
	counter.push_back(1);
	counter.push_back(2);
	counter.push_back(3);
	counter.push_back(4);
	PhoneIterator<int>* iter = counter.createIterator();
	while(iter->hasMore())
	{
		cout << iter->getNext() << endl;
	}
	cout << "Iterator over!" << endl;
	delete iter;
}

int main() 
{
	ClientCode();
	return 0;
}
