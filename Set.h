#ifndef SET_H
#define SET_H

#include <new>

template<typename SetType>
class Set {

public:

	virtual Set<SetType>& operator=(const Set<SetType>& copy) = delete;
	virtual ~Set() {}

	virtual bool isElInSet(const SetType el) const = 0;
	virtual Set<SetType>* clone() const = 0;

	virtual void myDelete() = 0;

};

#include "SetIntersection.inl"
#include "SetUnion.inl"
#include "ConditionSet.inl"
#include "FiniteSet.inl"


#endif // !SET_H