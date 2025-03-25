#pragma once
#ifndef __RESPONSIBILITY_CHAIN_H__
#define __RESPONSIBILITY_CHAIN_H__

#include <string>
#include <vector>

struct ComponentWithContextualHelp
{
	virtual void ShowHelp() = 0;
};

struct Container;

struct Component : public ComponentWithContextualHelp 
{
	virtual void SetNext(Container* NextComponent);
	virtual void ShowHelp() override;
	inline void SetTooltipText(std::string text) { TooltipText = text; }
	std::string TooltipText;
protected:
	Container* MyContainer;
};

struct Container : public Component 
{
	void Add(Component* Child);
protected:
	std::vector<Component*> Children;
};

struct Button : public Component 
{
};

struct Panel: public Container
{
	void ShowHelp() override;
	inline void SetModalHelpText(std::string text) { ModalHelpText = text; }
protected:
	std::string ModalHelpText;
};

struct Dialog: public Container
{
	void ShowHelp() override;
	inline void SetWikiPageURL(std::string text) { WikiPageURL = text; }
protected:
	std::string WikiPageURL;
};


#endif // __RESPONSIBILITY_CHAIN_H__
