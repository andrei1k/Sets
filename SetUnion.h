#ifndef SETUNION_H
#define SETUNION_H

#include "Set.h"

//template <typename SetType>
//class SetUnion : public Set<SetType> {
//
//public:
//
//	SetUnion(Set<SetType>** sets, unsigned setCount);
//	SetUnion(const SetUnion<SetType>& copy) = default;
//	SetUnion<SetType>& operator=(const SetUnion<SetType>&copy) = default;
//	virtual ~SetUnion() {};
//
//	Set<SetType>* clone() const;
//
//private:
//
//};

template <typename SetType>
class SetUnion : public Set<SetType> {

public:

	SetUnion(Set<SetType>** sets, unsigned setCount);
	SetUnion(const SetUnion<SetType>& copy);
	virtual ~SetUnion();

	void copy(const SetUnion<SetType>& copy) ;
	void copyWithDel(const SetUnion<SetType>& copy) ;
	void myDelete() override;

	bool isElInSet(const SetType el) const override;
	Set<SetType>* clone() const;

private:

	Set<SetType>** sets;
	unsigned setCount;


};

#endif // !SETUNION_H

