#pragma once
#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <string>

const double PI = 3.1415926;

/// <summary>
/// Colors
/// </summary>
struct Color
{
	std::string getName() { return color_name; }
protected:
	std::string color_name;
};

struct Blue: public Color
{
	Blue() { this->color_name = "Blue"; }
};

struct Yellow : public Color
{
	Yellow() { this->color_name = "Yellow"; }
};

struct Red : public Color
{
	Red() { this->color_name = "Red"; }
};

/// <summary>
/// Shapes
/// </summary>
struct Shape
{
	Color* color;
	inline void setColor(Color* newColor) { this->color = newColor; }
	inline virtual double getArea() const = 0;
	virtual void report() const = 0;
};

struct Rectangle : public Shape
{
	virtual double getArea() const override;
	virtual void report() const override;
private:
	double weight;
	double height;
};

struct Circle : public Shape
{
	virtual double getArea() const override;
	virtual void report() const override;
private:
	double radius;
};

#endif // __BRIDGE_H__
