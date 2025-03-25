#include <iostream>
#include <thread>

#include "Singleton.h"

using namespace std;

Singleton* Singleton::instance = nullptr;
mutex Singleton::mutex_;

Singleton* Singleton::getInstance(string name) 
{
	lock_guard<mutex> lock(Singleton::mutex_);
	if (Singleton::instance == nullptr)
	{
		Singleton::instance = new Singleton(name);
	}
	return Singleton::instance;
}


void threadFoo()
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	Singleton* sfoo = Singleton::getInstance("Foo");
	cout << "sfoo.name: " << sfoo->getName() << endl;
}

void threadBar() 
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	Singleton* sbar = Singleton::getInstance("Bar");
	cout << "sbar.name: " << sbar->getName() << endl;
}
