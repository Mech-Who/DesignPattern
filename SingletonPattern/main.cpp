#include <iostream>

#include "Singleton.h"

using namespace std;

int singleton()
{
	cout << "Different name as not save, while same name as save!" << endl;
	cout << "Result:" << endl;
	thread t1(threadFoo);
	thread t2(threadBar);
	t1.join();
	t2.join();
	return 0;
}

int main()
{
	singleton();
	return 0;
}
