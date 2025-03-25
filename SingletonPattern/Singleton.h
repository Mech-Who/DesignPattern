#pragma once

#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <string>
#include <mutex>

class Singleton
{
	static Singleton* instance;
	static std::mutex mutex_;
protected:
	std::string name="Jack";
	Singleton(std::string name) :name(name) {}
	~Singleton() {}
public:
	static Singleton* getInstance(std::string name);

	Singleton() = delete;
	void operator=(const Singleton&) = delete;

	inline std::string getName() { return this->name; }
	inline void setName(std::string newName) { this->name = newName; }
};

// Test methods
void threadFoo();
void threadBar();

#endif // __SINGLETON_H__
