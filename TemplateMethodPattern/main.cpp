#include "TemplateMethod.h"
#include <iostream>
#include <memory>
using namespace std;

void ClientCode(unique_ptr<AbstractMethod> &&class_) {
	// 前文操作
	class_->TemplateMethod();
	// 后文操作
}

int main() 
{
	std::cout << "Same client code can work with different subclasses:\n";
	ClientCode(make_unique<ConcreteMethodA>());
	std::cout << "\n";
	std::cout << "Same client code can work with different subclasses:\n";
	ClientCode(make_unique<ConcreteMethodB>());
	return 0;
}
