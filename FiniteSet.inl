#ifndef FINITESET_INL
#define FINITESET_INL

#include "FiniteSet.h"


template<typename SetType>
FiniteSet<SetType>::FiniteSet(const SetType* elements, unsigned elCount)
{
	this->size = 0;
	this->setElements = new SetType[elCount];

	for (unsigned i = 0; i < elCount; i++) {

		if (this->isElInSet(elements[i]) == false) {
			this->setElements[this->size] = elements[i];
			this->size++;
		}
	}
}

template<typename SetType>
FiniteSet<SetType>::FiniteSet(const FiniteSet<SetType>& copy)
{
	this->copy(copy);
}

template<typename SetType>
FiniteSet<SetType>::~FiniteSet()
{
	myDelete();
}

template<typename SetType>
void FiniteSet<SetType>::copy(const FiniteSet<SetType>& copy)
{
	this->size = copy.size;
	this->setElements = new SetType[this->size];
	for (unsigned i = 0; i < this->size; i++) {
		this->setElements[i] = copy.setElements[i];
	}
}

template<typename SetType>
void FiniteSet<SetType>::copyWithDel(const FiniteSet<SetType>& copy)
{
	myDelete();
	copy(copy);
}

template<typename SetType>
void FiniteSet<SetType>::myDelete()
{
	delete[] this->setElements;
}

template<typename SetType>
bool FiniteSet<SetType>::isElInSet(const SetType el) const
{
	for (unsigned i = 0; i < this->size; i++) {
		if (this->setElements[i] == el)
			return true;
	}

	return false;
}

template<typename SetType>
inline Set<SetType>* FiniteSet<SetType>::clone() const
{
	return new FiniteSet<SetType>(*this);
}

template<typename SetType>
void FiniteSet<SetType>::print() const
{
	for (unsigned i = 0; i < this->size; i++) {
		std::cout << this->setElements[i] << ' ';
	}
	std::cout << '\n';
}


#endif // !FINITESET_INL
