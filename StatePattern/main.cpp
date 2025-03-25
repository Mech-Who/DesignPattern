#include "State.h"
#include <iostream>

using namespace std;

void ClientCode() 
{
	auto doc = new Document();
	// draft
	doc->Render();
	doc->Publish();
	// moderate
	doc->Render();
	doc->Publish();
	// publish
	doc->Render();
	doc->Publish();

	delete doc;
}

int main() 
{
	ClientCode();
	return 0;
}
