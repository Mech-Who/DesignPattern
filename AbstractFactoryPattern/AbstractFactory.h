#pragma once
#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__

/// <summary>
/// Abstract Products Base
/// </summary>
struct Chair
{
	virtual void doBuseness() = 0;
};

struct Table
{
	virtual void doBuseness() = 0;
};

struct Sofa
{
	virtual void doBuseness() = 0;
};

/// <summary>
/// Concrete Chair (Product type)
/// </summary>
struct RedChair: public Chair
{
	virtual void doBuseness();
};

struct BlueChair: public Chair
{
	virtual void doBuseness();
};

struct GreenChair: public Chair
{
	virtual void doBuseness();
};

/// <summary>
/// Concrete Table (Product type)
/// </summary>
struct RedTable: public Table
{
	virtual void doBuseness();
};

struct BlueTable: public Table
{
	virtual void doBuseness();
};

struct GreenTable: public Table
{
	virtual void doBuseness();
};

/// <summary>
/// Concrete Sofa (Product type)
/// </summary>
struct RedSofa: public Sofa
{
	virtual void doBuseness();
};

struct BlueSofa : public Sofa
{
	virtual void doBuseness();
};

struct GreenSofa : public Sofa
{
	virtual void doBuseness();
};

/// <summary>
/// Factory
/// </summary>
struct Factory
{
	Factory() {}
	virtual ~Factory() {};
	virtual Chair* createChair() = 0;
	virtual Table* createTable() = 0;
	virtual Sofa* createSofa() = 0;
};

/// <summary>
/// Style Factories
/// </summary>
struct RedFactory : public Factory
{
	virtual Chair* createChair();
	virtual Table* createTable();
	virtual Sofa* createSofa();
};

struct BlueFactory : public Factory
{
	virtual Chair* createChair();
	virtual Table* createTable();
	virtual Sofa* createSofa();
};

struct GreenFactory : public Factory
{
	virtual Chair* createChair();
	virtual Table* createTable();
	virtual Sofa* createSofa();
};

#endif // __ABSTRACT_FACTORY_H__
