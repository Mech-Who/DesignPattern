#pragma once
#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include <string>

struct BaseComponent;

struct Mediator 
{
	virtual ~Mediator() {}
	virtual void Notify(BaseComponent* sender, std::string event) = 0;
};

struct BaseComponent
{
	BaseComponent(Mediator* m = nullptr) : mediator(m) {}
	virtual ~BaseComponent() {}
	void SetMediator(Mediator* m);
protected:
	Mediator* mediator;
};

struct ComponentA: public BaseComponent
{
	void DoA();
	void DoB();
};

struct ComponentB: public BaseComponent
{
	void DoC();
	void DoD();
};

struct ConcreteMediator: public Mediator
{
	ConcreteMediator(ComponentA* a, ComponentB* b);
	void Notify(BaseComponent* sender, std::string event) override;
private:
	ComponentA* cA;
	ComponentB* cB;
};

#endif // __MEDIATOR_H__

