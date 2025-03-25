#pragma once
#ifndef __DECORATE_H__
#define __DECORATE_H__

#include <string>

struct Notifier 
{
	virtual void notify(std::string msg) = 0;
};

struct EmailNotifier: Notifier
{
	virtual void notify(std::string msg);
};

struct NotifierDecorator : public Notifier
{
	NotifierDecorator() { notifier = nullptr; };
	NotifierDecorator(Notifier* notifier)
		: notifier(notifier) {}
	virtual ~NotifierDecorator();
	virtual void notify(std::string msg) = 0;
protected:
	Notifier* notifier;
};

struct QQNotifier : public NotifierDecorator
{
	QQNotifier() = default;
	QQNotifier(Notifier* notifier)
		: NotifierDecorator(notifier) {}
	virtual ~QQNotifier();
	virtual void notify(std::string msg);
};

struct WechatNotifier : public NotifierDecorator
{
	WechatNotifier() = default;
	WechatNotifier(Notifier* notifier)
		: NotifierDecorator(notifier) {
	}
	virtual ~WechatNotifier();
	virtual void notify(std::string msg);
};

struct SMSNotifier : public NotifierDecorator
{
	SMSNotifier() = default;
	SMSNotifier(Notifier* notifier)
		: NotifierDecorator(notifier) {
	}
	virtual ~SMSNotifier();
	virtual void notify(std::string msg);
};

#endif // __DECORATE_H__
