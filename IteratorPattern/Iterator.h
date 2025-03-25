#pragma once
#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <vector>

template <typename T>
struct PhoneContainer;

template<typename T>
struct PhoneIterator 
{
	PhoneIterator<T>(PhoneContainer<T>* c)
	:container(c), state(1), cIndex(0){}
	T getNext();
	bool hasMore();
protected:
	PhoneContainer<T>* container;
	int state; // TODO: Type check
	int cIndex;
};

template<typename T>
bool PhoneIterator<T>::hasMore()
{
	if (cIndex < container->size())
	{
		return true;
	}
	return false;
}

template<typename T>
T PhoneIterator<T>::getNext()
{
	T data = container->get(cIndex++);
	return data;
}

template <typename T>
struct PhoneContainer {
	PhoneIterator<T>* createIterator();
	size_t size();
	T get(int index);
	void push_back(T v);
	void remove(T v);
protected:
	std::vector<T> data;
};

template <typename T>
void PhoneContainer<T>::remove(T v)
{
	data.remove(v);
}

template <typename T>
void PhoneContainer<T>::push_back(T v)
{
	data.push_back(v);
}

template <typename T>
T PhoneContainer<T>::get(int index)
{
	return data[static_cast<size_t>(index)];
}

template <typename T>
size_t PhoneContainer<T>::size()
{
	return data.size();
}

template <typename T>
PhoneIterator<T>* PhoneContainer<T>::createIterator()
{
	return new PhoneIterator<T>(this);
}

#endif // __ITERATOR_H__
