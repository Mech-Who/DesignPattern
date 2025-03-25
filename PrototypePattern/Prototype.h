#pragma once
#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

#include <string>
#include <unordered_map>

/// <summary>
/// Prototypes
/// </summary>
struct Prototype
{
	std::string name;
	Prototype(std::string name): name(name) {}
	virtual Prototype* clone() const = 0;
	virtual void work() = 0;
protected:
	Prototype(const Prototype* src): name(src->name) {}
};

struct Robot : public Prototype 
{
	std::string type;
	Robot(std::string name, std::string type): Prototype(name), type(type) {}
	virtual Prototype* clone() const override;
	virtual void work() override;
protected:
	Robot(const Robot* src) : Prototype(src), type(src->type) {}
};

struct Machine : public Prototype 
{
	std::string usage;
	virtual Prototype* clone() const override;
	Machine(std::string name, std::string usage) : Prototype(name), usage(usage) {}
	virtual void work() override;
protected:
	Machine(const Machine* src) : Prototype(src), usage(src->usage) {}
};

/// <summary>
/// Prototype Factory
/// </summary>
struct PrototypeFactory 
{
	PrototypeFactory() {
		prototypes["robot"] = new Robot("Robot", "work");
		prototypes["machine"] = new Machine("Machine", "for human work");
	}
	~PrototypeFactory() {
		delete prototypes["robot"];
		delete prototypes["machine"];
	}

	Prototype* createPrototype(std::string type_name);
private:
	std::unordered_map<std::string, Prototype*> prototypes;
};

#endif // __PROTOTYPE_H__
