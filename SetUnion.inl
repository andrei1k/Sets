#ifndef SETUNION_INL
#define SETUNION_INL

#include "SetUnion.h"
#include <iostream>

template<typename SetType>
SetUnion<SetType>::SetUnion(Set<SetType>** sets, unsigned setCount) : setCount(setCount)
{
	this->sets = new Set<SetType>*[this->setCount];
	for (unsigned i = 0; i < setCount; i++) {
		this->sets[i] = sets[i]->clone();
	}
}

template<typename SetType>
SetUnion<SetType>::SetUnion(const SetUnion<SetType>& copy)
{
	this->copy(copy);
}

template<typename SetType>
SetUnion<SetType>::~SetUnion()
{
	myDelete();
}

template<typename SetType>
void SetUnion<SetType>::copy(const SetUnion<SetType>& copy)
{
	this->setCount = copy.setCount;
	this->sets = new Set<SetType> *[this->setCount];
	for (unsigned i = 0; i < this->setCount; i++) {
		this->sets[i] = copy.sets[i]->clone();
	}
}

template<typename SetType>
void SetUnion<SetType>::copyWithDel(const SetUnion<SetType>& copy)
{
	myDelete();
	copy(copy);
}

template<typename SetType>
void SetUnion<SetType>::myDelete()
{
	for (unsigned i = 0; i < this->setCount; i++)
		delete sets[i];
	delete[] sets;
}

template<typename SetType>
bool SetUnion<SetType>::isElInSet(const SetType el) const
{
	for (unsigned i = 0; i < this->setCount; i++) {

		if (sets[i]->isElInSet(el))

			return true;
	}
	return false;
}

template<typename SetType>
Set<SetType>* SetUnion<SetType>::clone() const
{
	return new SetUnion(*this);
}

#endif // !SETUNION_INL
