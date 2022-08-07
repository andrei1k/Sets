#ifndef FINITESET_H
#define FINITESET_H

#include "Set.h"

template <typename SetType>
class FiniteSet : public Set<SetType> {

public:

	FiniteSet(const SetType* elements, unsigned elCount);
	FiniteSet(const FiniteSet<SetType>& copy);
	~FiniteSet();

	void copy(const FiniteSet<SetType>& copy);
	void copyWithDel(const FiniteSet<SetType>& copy);
	void myDelete() override;


	bool isElInSet(const SetType el) const override;
	Set<SetType>* clone() const;

	//ZA TEST
	void print() const;

private:

	SetType* setElements{};
	unsigned size{};

};

#endif // !FINITESET_H

