#include "State.h"
#include <iostream>

void Draft::Render()
{
	std::cout << "Document is a draft." << std::endl;
}

void Draft::Publish()
{
	std::cout << "Document will be moderated!" << std::endl;
	doc->ChangeState(new Moderation());
}

void Moderation::Render()
{
	std::cout << "Document is moderating.." << std::endl;
}

void Moderation::Publish()
{
	std::cout << "Document is moderated!" << std::endl;
	doc->ChangeState(new Published());
}

void Published::Render()
{
	std::cout << "Document have published" << std::endl;
}

void Published::Publish()
{
	std::cout << "Document was already published!" << std::endl;
}

Document::Document(): state(new Draft()) 
{
	state->SetDoc(this);
}

Document::~Document() { delete state; }

void Document::Render()
{
	state->Render();
}

void Document::Publish()
{
	state->Publish();
}

void Document::ChangeState(State* s)
{
	if (nullptr != state)
		delete state;
	state = s;
	state->SetDoc(this);
}
