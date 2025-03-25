#pragma once
#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <string>
#include <vector>

struct Observer;

struct Publisher {
	Publisher():state(0){}
	void Notify();
	void AddObserver(Observer* o);
	void RemoveObserver(Observer* o);
	void ChangeState();
	inline int GetState() { return state; }
protected:
	std::vector<Observer*> observers;
	int state;
};

struct Observer
{
	virtual ~Observer() {}
	virtual void Update(Publisher* p) = 0;
};

struct ConcreteObserver: public Observer
{
	void Update(Publisher* p) override;
};

#endif // __OBSERVER_H__
