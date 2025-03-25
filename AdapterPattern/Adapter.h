#pragma once
#ifndef __ADAPTER_H__
#define __ADAPTER_H__

struct RoundPeg
{
	RoundPeg(double radius=0) : radius(radius) {}
	inline virtual double getRadius() const { return radius; }
private:
	double radius;
};

struct RoundHole
{
	RoundHole(double radius=0) : radius(radius) {}
	inline double getRadius() const { return radius; }
	bool fits(RoundPeg* peg) const;
private:
	double radius;
};

struct SquarePeg 
{
	SquarePeg(double w=0): weight(w) {}
	inline double getWeight() const { return weight; }
private:
	double weight;
};

struct SquarePegAdapter: public RoundPeg
{
	SquarePegAdapter(SquarePeg& peg) : speg(peg) {}
	inline double getRadius() const { return speg.getWeight() * sqrt(2); }
private:
	SquarePeg speg;
};

#endif // __ADAPTER_H__