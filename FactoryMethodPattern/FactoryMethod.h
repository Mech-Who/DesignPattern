#pragma once
#ifndef __FACTORY_METHOD_H__
#define __FACTORY_METHOD_H__

// Product

class Product 
{
public:
	virtual ~Product() {}
	virtual void doBusiness() const = 0;
};

class ProA : public Product
{
public:
	void doBusiness() const override;
};

class ProB: public Product
{
public:
	void doBusiness() const override;
};

// Factory

class Factory
{
public:
	virtual ~Factory() {}
	virtual Product* makeProduct() const = 0;
};

class FactoryA : public Factory
{
	Product* makeProduct() const override;
};

class FactoryB : public Factory
{
	Product* makeProduct() const override;
};

#endif // __FACTORY_METHOD_H__
