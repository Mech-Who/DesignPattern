#pragma once
#ifndef __COMPOSITE_H__
#define __COMPOSITE_H__

#include <vector>
#include <string>

struct Component
{
	virtual void execute() const = 0;
};

struct Leaf: public Component
{
	Leaf(std::string prodName) :name(prodName) {}
	inline void setName(std::string newName) {
		name = newName;
	}
	inline std::string getName() { return name; }
	void execute() const final override;
protected:
	std::string name;
};

struct Composite: public Component
{
	void add(Component* c);
	void remove(Component* c);
	std::vector<Component*> getChildren() const;
	void execute() const final override;
protected:
	mutable std::vector<Component*> components;
};

#endif // __COMPOSITE_H__
