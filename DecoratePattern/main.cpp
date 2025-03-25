#include <iostream>
#include "Decorate.h"

using namespace std;

int main() 
{
	EmailNotifier* email = new EmailNotifier();
	QQNotifier* qq = new QQNotifier(email);
	WechatNotifier* wechat = new WechatNotifier(qq);
	SMSNotifier* sms = new SMSNotifier(wechat);
	sms->notify("test!");
	delete email;
	delete qq;
	delete wechat;
	delete sms;
	return 0;
}
