#pragma once
#ifndef __FLYWEIGHT_H__
#define __FLYWEIGHT_H__

#include <string>
#include <vector>

struct TreeType
{
	TreeType() = default;
	TreeType(std::string name, std::string color, std::string texture);
	void draw(std::string canvas, double x, double y);
	inline std::string getName() { return name; }
	inline std::string getColor() { return color; }
	inline std::string getTexture() { return texture; }
private:
	std::string name;
	std::string color;
	std::string texture;
};

struct Tree
{
	void draw(std::string canvas);

	double x;
	double y;
	TreeType* type;
};

struct TreeTypeFactory
{
	static TreeType* getTreeType(std::string name, std::string color, std::string texture);
	static void clear();
private:
	static std::vector<TreeType*> treeTypes;
};

struct Forest
{
	~Forest();
	Tree* plantTree(double x, double y, std::string name, std::string color, std::string texture);
	void draw(std::string canvas);

	std::vector<Tree*> trees;
};

#endif // __FLYWEIGHT_H__
