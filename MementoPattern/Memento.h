#pragma once
#ifndef __MEMENTO_H__
#define __MEMENTO_H__
#include <vector>

struct Memento;

struct Originator
{
	virtual ~Originator() {}
	virtual Memento* save() = 0;
};

struct Memento
{
	virtual ~Memento() {}
	virtual void restore() = 0;
	virtual int get() = 0;
};

struct Caretaker
{
	Caretaker(Originator* o);
	void undo();
	void save();
	void showHistory();
private:
	std::vector<Memento*> history;
	Originator* originator;
};

struct ConcreteOriginator: public Originator
{
	ConcreteOriginator(int state = 0);
	Memento* save() override;
	inline void SetState(int s) {
		state = s;
	}
	inline int GetState() {
		return state;
	}
	void DoSomething();
protected:
	int state;
};

struct ConcreteMemento: public Memento
{
	ConcreteMemento(ConcreteOriginator* o, int state);
	void restore() override;
	int get() override;
protected:
	ConcreteOriginator* originator;
	int state;
};


#endif // __MEMENTO_H__
