#include "Strategy.h"
#include <iostream>
#include <memory>

using namespace std;

void ClientCode() 
{
	Context context(make_unique<ConcreteStrategyA>());
	cout << "Client: strategy is set to normal sorting" << endl;
	context.doSomething();
	cout << endl;
	cout << "Client: strategy is set to reverse sorting." << endl;
	context.setStrategy(make_unique<ConcreteStrategyB>());
	context.doSomething();
}

int main() 
{
	ClientCode();
	return 0;
}
