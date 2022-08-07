#ifndef SETINTERSECTION_INL
#define SETINTERSECTION_INL

#include "SetIntersection.h"
#include <iostream>

template<typename SetType>
SetIntersection<SetType>::SetIntersection(Set<SetType>** sets, unsigned setCount) : setCount(setCount)
{
	this->sets = new Set<SetType>*[setCount];
	for (unsigned i = 0; i < this->setCount; i++) {
		this->sets[i] = sets[i]->clone();
	}
}

template<typename SetType>
SetIntersection<SetType>::SetIntersection(const SetIntersection<SetType>& copy)
{
	this->copy(copy);
}


template<typename SetType>
SetIntersection<SetType>::~SetIntersection()
{
	myDelete();
}

template<typename SetType>
void SetIntersection<SetType>::copy(const SetIntersection<SetType>& copy)
{
	this->setCount = copy.setCount;
	this->sets = new Set<SetType> *[this->setCount];
	for (unsigned i = 0; i < this->setCount; i++) {
		this->sets[i] = copy.sets[i]->clone();
	}
}

template<typename SetType>
void SetIntersection<SetType>::copyWithDel(const SetIntersection<SetType>& copy)
{
	myDelete();
	copy(copy);
}

template<typename SetType>
void SetIntersection<SetType>::myDelete()
{
	for (unsigned i = 0; i < this->setCount; i++) {
			delete sets[i];
	}
	delete[] this->sets;
}

template<typename SetType>
bool SetIntersection<SetType>::isElInSet(const SetType el) const
{
	for (unsigned i = 0; i < this->setCount; i++) {

		if (!sets[i]->isElInSet(el)) {
			return false;
		}
	}
	return true;
}

template<typename SetType>
Set<SetType>* SetIntersection<SetType>::clone() const
{
	return new SetIntersection(*this);
}

#endif // !SETINTERSECTION_INL
