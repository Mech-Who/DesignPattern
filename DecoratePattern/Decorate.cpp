#include <iostream>
#include "Decorate.h"

using namespace std;

void EmailNotifier::notify(string msg)
{
	cout << "Email notify: " << msg << endl;
}

NotifierDecorator::~NotifierDecorator()
{
	cout << "NotifierDecorator destroyed!" << endl;
}

QQNotifier::~QQNotifier()
{
	cout << "QQNotifier destroyed!" << endl;
}

WechatNotifier::~WechatNotifier()
{
	cout << "WechatNotifier destroyed!" << endl;
}

SMSNotifier::~SMSNotifier()
{
	cout << "SMSNotifier destroyed!" << endl;
}

void QQNotifier::notify(string msg)
{
	cout << "QQ notify: " << msg << endl;
	if (notifier != nullptr) {
		notifier->notify(msg);
	}
}

void WechatNotifier::notify(string msg)
{
	cout << "Wechat notify: " << msg << endl;
	if (notifier != nullptr) {
		notifier->notify(msg);
	}
}

void SMSNotifier::notify(string msg)
{
	cout << "SMS notify: " << msg << endl;
	if (notifier != nullptr){
		notifier->notify(msg);
	}
}
