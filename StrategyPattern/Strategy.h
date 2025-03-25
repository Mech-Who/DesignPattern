#pragma once
#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <memory>
#include <string>
#include <string_view>

struct Strategy
{
	virtual ~Strategy() = default;
	virtual std::string doAlgrithm(std::string_view data) = 0;
};

struct Context {
	explicit Context(std::unique_ptr<Strategy>&& s = {}) : strategy_(std::move(s)) {}
	void setStrategy(std::unique_ptr<Strategy>&& s);
	void doSomething() const;
private:
	std::unique_ptr<Strategy> strategy_;
};

struct ConcreteStrategyA: public Strategy {
	std::string doAlgrithm(std::string_view s) override;
};

struct ConcreteStrategyB: public Strategy {
	std::string doAlgrithm(std::string_view s) override;
};

#endif // __STRATEGY_H__
