#pragma once
#ifndef __VISITOR_H__
#define __VISITOR_H__
#include <string>

struct ConcreteComponentA;
struct ConcreteComponentB;

struct Visitor
{
	virtual ~Visitor() = default;
	virtual void visitConcreteComponentA(const ConcreteComponentA* element) const = 0;
	virtual void visitConcreteComponentB(const ConcreteComponentB* element) const = 0;
};

struct Component
{
	virtual ~Component() = default;
	virtual void accept(Visitor* visitor) const = 0;
};

struct ConcreteComponentA: public Component
{
	void accept(Visitor* visitor) const override;
	std::string ExclusiveMethodOfConcreteComponentA() const;
};

struct ConcreteComponentB: public Component
{
	void accept(Visitor* visitor) const override;
	std::string SpecialMethodOfConcreteComponentB() const;
};

struct ConcreteVisitorA: public Visitor
{
	void visitConcreteComponentA(const ConcreteComponentA* element) const override;
	void visitConcreteComponentB(const ConcreteComponentB* element) const override;
};

struct ConcreteVisitorB: public Visitor
{
	void visitConcreteComponentA(const ConcreteComponentA* element) const override;
	void visitConcreteComponentB(const ConcreteComponentB* element) const override;
};

#endif // __VISITOR_H__


