#include "Strategy.h"
#include <algorithm>
#include <iostream>

void Context::setStrategy(std::unique_ptr<Strategy>&& s)
{
	strategy_ = std::move(s);
}

void Context::doSomething() const
{
	if (strategy_) {
		std::cout << "Context: sorting data using the strategy(not sure how it'll do it)" << std::endl;
		std::string result = strategy_->doAlgrithm("aecbd");
		std::cout << result << std::endl;
	}else{
		std::cout << "Context: strategy isn't set" << std::endl;
	}
}

std::string ConcreteStrategyA::doAlgrithm(std::string_view s)
{
	std::string result(s);
	std::sort(std::begin(result), std::end(result));
	return result;
}

std::string ConcreteStrategyB::doAlgrithm(std::string_view s)
{
	std::string result(s);
	std::sort(std::begin(result), std::end(result), std::greater<>());
	return result;
}
