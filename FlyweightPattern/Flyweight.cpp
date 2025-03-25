#include "Flyweight.h"
#include <iostream>
#include <vector>

using namespace std;

TreeType::TreeType(std::string name, std::string color, std::string texture): name(name), color(color), texture(texture){}

void TreeType::draw(std::string canvas, double x, double y)
{
	cout << name << "(" << color << " " << texture << ") "
		 << "draw in '" << canvas << "' " 
		 << "at (" << x << "," << y << ")" << endl;
}

void Tree::draw(std::string canvas)
{
	type->draw(canvas, x, y);
}

TreeType* TreeTypeFactory::getTreeType(std::string name, std::string color, std::string texture)
{
	for (auto & treeType : treeTypes) 
	{
		if (treeType->getName() == name
			&& treeType->getColor() == color
			&& treeType->getTexture() == texture)
			return treeType;
	}
	TreeType* newTreeType = new TreeType(name, color, texture);
	treeTypes.push_back(newTreeType);
	return newTreeType;
}

void TreeTypeFactory::clear()
{
	cout << "TreeTypeFactory Clear:" << endl;
	for (auto & treeType : treeTypes)
	{
		treeType->draw("Çå³ý", 1.0, 1.0);
		delete treeType;
		treeType = nullptr;
	}
	treeTypes.clear();
}

vector<TreeType*> TreeTypeFactory::treeTypes = vector<TreeType*>();

Forest::~Forest()
{
	for (auto &tree : trees)
	{
		delete tree;
		tree = nullptr;
	}
	trees.clear();
}

Tree* Forest::plantTree(
	double x, double y, 
	std::string name, 
	std::string color, 
	std::string texture)
{
	Tree* newTree = new Tree();
	newTree->x = x;
	newTree->y = y;
	TreeType* type = TreeTypeFactory::getTreeType(name, color, texture);
	newTree->type = type;
	trees.push_back(newTree);
	return newTree;
}

void Forest::draw(std::string canvas)
{
	for(auto tree : trees)
	{
		tree->draw(canvas);
	}
}
