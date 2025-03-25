#include "Flyweight.h"
#include <iostream>

using namespace std;

void ClientCode(Forest* forest) 
{
	forest->plantTree(1.0, 2.0, "苹果树", "红色", "正面图");
	forest->plantTree(2.0, 4.0, "苹果树", "红色", "正面图");
	forest->plantTree(3.0, 6.0, "香蕉树", "黄色", "正面图");
	forest->plantTree(4.0, 8.0, "香蕉树", "黄色", "正面图");
	forest->plantTree(5.0, 10.0, "梨树", "黄色", "侧面图");
}

int main()
{
	Forest *forest = new Forest();
	ClientCode(forest);
	forest->draw("主窗口");
	delete forest;
	TreeTypeFactory::clear();

	cin.clear(); // reset any error flags
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
	cin.get(); // get one more char from the user
	
	return 0;
}