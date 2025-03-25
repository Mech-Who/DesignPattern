#include "ResponsibilityChain.h"
#include <iostream>

using namespace std;

int main() 
{
	Dialog* dialog = new Dialog();
	dialog->SetWikiPageURL("https://...");
	Panel* panel = new Panel();
	panel->SetModalHelpText("本面板用于……");
	Button* ok = new Button();
	ok->SetTooltipText("这是一个确认按钮……");
	Button* cancel = new Button();
	cancel->SetTooltipText("这是一个取消按钮……");

	panel->Add(ok);
	panel->Add(cancel);
	dialog->Add(panel);

	// 模拟点击组件
	panel->ShowHelp();
	ok->ShowHelp();

	delete cancel;
	delete ok;
	delete dialog;
	delete panel;
	return 0;
}
