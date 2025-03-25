#include "ResponsibilityChain.h"
#include <iostream>

using namespace std;

void Component::SetNext(Container* NextComponent)
{
	MyContainer = NextComponent;
}

void Component::ShowHelp()
{
	if (!TooltipText.empty()) 
	{
		cout << TooltipText << endl;
	}
	else 
	{
		MyContainer->ShowHelp();
	}
}

void Container::Add(Component* Child)
{
	Children.push_back(Child);
	Child->SetNext(this);
}

void Panel::ShowHelp()
{
	if (!ModalHelpText.empty())
	{
		cout << ModalHelpText << endl;
	}
	else 
	{
		Container::ShowHelp();
	}
}

void Dialog::ShowHelp()
{
	if (!WikiPageURL.empty())
	{
		cout << WikiPageURL << endl;
	}
	else
	{
		Container::ShowHelp();
	}
}
