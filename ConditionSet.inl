#ifndef CONDITIONSET_INL
#define CONDITIONSET_INL

#include "ConditionSet.h"

template<typename SetType>
ConditionSet<SetType>::ConditionSet(bool(*condition)(const SetType* elements, unsigned elCount, SetType element), const SetType* elements, unsigned elCount) 
{
	this->myBoolFunct = condition;
	this->elements = new SetType[elCount];
	for (unsigned i = 0; i < elCount; i++) {
		this->elements[i] = elements[i];
	}
	this->elCount = elCount;
}

template<typename SetType>
ConditionSet<SetType>::ConditionSet(const ConditionSet<SetType>& copy)
{
	this->copy(copy);
}

template<typename SetType>
void ConditionSet<SetType>::copy(const ConditionSet<SetType>& copy)
{
	this->myBoolFunct = copy.myBoolFunct;
	this->elCount = copy.elCount;
	this->elements = new SetType[this->elCount];
	for (unsigned i = 0; i < this->elCount; i++) {
		this->elements[i] = copy.elements[i];
	}
}

template<typename SetType>
void ConditionSet<SetType>::copyWithDel(const ConditionSet<SetType>& copy)
{
	myDelete();
	copy(copy);
}

template<typename SetType>
void ConditionSet<SetType>::myDelete()
{
	delete[] this->elements;
}

template<typename SetType>
ConditionSet<SetType>::~ConditionSet()
{
	myDelete();
}

template<typename SetType>
bool ConditionSet<SetType>::isElInSet(const SetType el) const
{
	return this->myBoolFunct(this->elements, this->elCount, el);
}

template<typename SetType>
inline Set<SetType>* ConditionSet<SetType>::clone() const
{
	return new ConditionSet(*this);
}

#endif // !CONDITIONSET_INL
