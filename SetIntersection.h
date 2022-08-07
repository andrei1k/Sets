#ifndef SETINTERSECTION_H
#define SETINTERSECTION_H

#include "Set.h"

//template<typename SetType>
//class SetIntersection : public Set<SetType> {
//
//public:
//
//	SetIntersection(Set<SetType>** sets, unsigned setCount);
//	SetIntersection(const SetIntersection<SetType>& copy) = default;
//	SetIntersection<SetType>& operator=(const SetIntersection<SetType>&copy) = default;
//	virtual ~SetIntersection() {}
//
//	Set<SetType>* clone() const;
//
//private:
//
//};

template <typename SetType>
class SetIntersection : public Set<SetType> {

public:

	SetIntersection(Set<SetType>** sets, unsigned setCount);
	SetIntersection(const SetIntersection<SetType>& copy);
	virtual ~SetIntersection();

	void copy(const SetIntersection<SetType>& copy);
	void copyWithDel(const SetIntersection<SetType>& copy);
	void myDelete() override;

	bool isElInSet(const SetType el) const override;
	Set<SetType>* clone() const;
	Set<SetType>** sets;


private:

	unsigned setCount;


};

#endif // !SETINTERSECTION_H


