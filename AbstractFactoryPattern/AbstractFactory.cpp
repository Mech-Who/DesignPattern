#include <iostream>
#include "AbstractFactory.h"

using namespace std;

/*
Chairs
*/
void RedChair::doBuseness() 
{
	cout << "This is a RED chair!" << endl;
}

void BlueChair::doBuseness()
{
	cout << "This is a BLUE chair!" << endl;
}

void GreenChair::doBuseness()
{
	cout << "This is a GREEN chair!" << endl;
}

/*
Tables
*/
void RedTable::doBuseness()
{
	cout << "This is a RED table!" << endl;
}

void BlueTable::doBuseness()
{
	cout << "This is a BLUE table!" << endl;
}

void GreenTable::doBuseness()
{
	cout << "This is a GREEN table!" << endl;
}

/*
Sofas
*/
void RedSofa::doBuseness()
{
	cout << "This is a RED sofa!" << endl;
}

void BlueSofa::doBuseness()
{
	cout << "This is a BLUE sofa!" << endl;
}

void GreenSofa::doBuseness()
{
	cout << "This is a GREEN sofa!" << endl;
}

/*
Red Factory
*/
Chair* RedFactory::createChair()
{
	return new RedChair();
}

Table* RedFactory::createTable()
{
	return new RedTable();
}

Sofa* RedFactory::createSofa()
{
	return new RedSofa();
}

/*
Blue Factory
*/
Chair* BlueFactory::createChair()
{
	return new BlueChair();
}

Table* BlueFactory::createTable()
{
	return new BlueTable();
}

Sofa* BlueFactory::createSofa()
{
	return new BlueSofa();
}

/*
Green Factory
*/
Chair* GreenFactory::createChair()
{
	return new GreenChair();
}

Table* GreenFactory::createTable()
{
	return new GreenTable();
}

Sofa* GreenFactory::createSofa()
{
	return new GreenSofa();
}
