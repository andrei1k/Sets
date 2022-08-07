#ifndef CONDITIONSET_H
#define CONDITIONSET_H

#include "Set.h"

template <typename SetType>
class ConditionSet : public Set<SetType> {

public:

	ConditionSet(bool (*condition)(const SetType* elements, unsigned elCount, SetType element), const SetType* elements, unsigned elCount);
	ConditionSet(const ConditionSet<SetType>& copy);
	~ConditionSet();

	void copy(const ConditionSet<SetType>& copy);
	void copyWithDel(const ConditionSet<SetType>& copy);
	virtual void myDelete() override;

	bool isElInSet(const SetType el) const;
	Set<SetType>* clone() const;

private:

	bool (*myBoolFunct)(const SetType* elements, unsigned elCount, SetType element);
	SetType* elements;
	unsigned elCount;

};


#endif // !CONDITIONSET_H
