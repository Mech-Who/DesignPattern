#include "Proxy.h"
#include <iostream>
#include <limits>

#define DEBUG_EVENT

using namespace std;

int main() 
{
	ThirdPartyTVClass* tvclass = new ThirdPartyTVClass();

	tvclass->addVideo(1, "V_hello", 20.0, "hello world!");
	tvclass->addVideo(2, "V_world", 20.0, "world destroyed!");
	tvclass->addVideo(3, "V_destroyed", 20.0, "destroyed name!");

	CachedTVClass* cachedtv = new CachedTVClass(tvclass);
	TVManager* manager = new TVManager(cachedtv);
	manager->reactOnUserInput();
	delete manager;
	delete cachedtv;
	delete tvclass;

	cin.clear(); // reset any error flags
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
	cin.get(); // get one more char from the user
	return 0;
}
