#ifndef MYPROGRAM_H
#define MYPROGRAM_H

#include "Set.h"

void createTestFiles();

template<typename SetType>
void myProgram(const char path[]);
template <typename SetType>
Set<SetType>* binaryFileManipulations(const char filePath[], Set<SetType>* result, bool& first);
template <typename SetType>
void printElInRangeCount(const Set<SetType>* set);

void IsIstreamGood(std::istream& in);
bool exceptionHanderForRangre(std::istream& in);

template <typename SetType>
bool devideByAtAny(const SetType* elements, unsigned elCount, SetType element);
template <typename SetType>
bool devideByAtAll(const SetType* elements, unsigned elCount, SetType element);

#include "MyProgram.inl"

#endif // !MYPROGRAM_H
