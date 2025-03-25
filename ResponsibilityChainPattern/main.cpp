#include "ResponsibilityChain.h"
#include <iostream>

using namespace std;

int main() 
{
	Dialog* dialog = new Dialog();
	dialog->SetWikiPageURL("https://...");
	Panel* panel = new Panel();
	panel->SetModalHelpText("��������ڡ���");
	Button* ok = new Button();
	ok->SetTooltipText("����һ��ȷ�ϰ�ť����");
	Button* cancel = new Button();
	cancel->SetTooltipText("����һ��ȡ����ť����");

	panel->Add(ok);
	panel->Add(cancel);
	dialog->Add(panel);

	// ģ�������
	panel->ShowHelp();
	ok->ShowHelp();

	delete cancel;
	delete ok;
	delete dialog;
	delete panel;
	return 0;
}
