#pragma once
#ifndef __BUILDER_H__
#define __BUILDER_H__

#include <vector>

/// <summary>
/// Builder Base
/// </summary>
struct BuilderBase
{
	BuilderBase() {}
	virtual ~BuilderBase() {}
	virtual void setHead() = 0;
	virtual void setLeftArm() = 0;
	virtual void setRightArm() = 0;
	virtual void setBody() = 0;
	virtual void setLeftLeg() = 0;
	virtual void setRightLeg() = 0;
	virtual void setLeftFoot() = 0;
	virtual void setRightFoot() = 0;
};

/// <summary>
/// Base Component
/// </summary>
struct Part
{
	virtual void report() = 0;
};

/// <summary>
/// Robots
/// </summary>
struct Robot 
{
	Robot() {}
	~Robot();
	void report();
	std::vector<Part*> parts;
};

struct Builder : public BuilderBase
{
	Builder() { 
		reset(); 
	}
	~Builder() { 
		if (robot != nullptr) delete robot; 
	}

	virtual void setHead() override;
	virtual void setLeftArm() override;
	virtual void setRightArm() override;
	virtual void setBody() override;
	virtual void setLeftLeg() override;
	virtual void setRightLeg() override;
	virtual void setLeftFoot() override;
	virtual void setRightFoot() override;

	void reset();
	Robot *getRobot();
protected:
	Robot *robot;
};

/// <summary>
/// Manager
/// </summary>
struct Manager
{
	Manager(BuilderBase* builder):builder(builder) {}
	~Manager() {}
	void setBuilder(BuilderBase* newBuilder);
	void makeFullRobot();
	void makeHalfRobot();
protected:
	BuilderBase* builder;
};

/// <summary>
/// Components: Robot Head
/// </summary>
struct Head: public Part 
{
	virtual void report();
};

struct Arm : public Part 
{
	virtual void report();
};

struct Body : public Part {
	virtual void report();
};

struct Leg : public Part {
	virtual void report();
};

struct Foot : public Part {
	virtual void report();
};

#endif // __BUILDER_H__
