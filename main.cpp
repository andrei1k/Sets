#include <iostream>
#include <fstream>
#include "Set.h"
#include "FiniteSet.h"
#include "ConditionSet.h"
#include "SetUnion.h"
#include "SetIntersection.h"
#include "MyProgram.h"

int main()
{
    // Class Tests
    //int arr[] = { 2, 3, 1 , 4, 6 , 10, 12, 16};
    //FiniteSet<int> myFSet(arr, 8); 
    ////myFSet.print();
    //int arr2[] = { 2, 3 , 5};
    //ConditionSet<int> myVondition(&devideByAtAny, arr2, 3);
    ////std::cout << myVondition.isElInSet(4) << myVondition.isElInSet(3) << myVondition.isElInSet(6) << myVondition.isElInSet(1);
    //Set<int>* arrOfSets[] = { &myFSet, &myVondition };
    //SetUnion<int> unity(arrOfSets, 2);
    ////std::cout << unity.isElInSet(4) << unity.isElInSet(3) << unity.isElInSet(6) << unity.isElInSet(1);
    //SetIntersection<int> intersec(arrOfSets, 2);
    ////std::cout << intersec.isElInSet(4) << intersec.isElInSet(3) << intersec.isElInSet(6) << intersec.isElInSet(1);
    ////std::cout << &myFSet << ' ' << intersec.sets[0];
    //Set<int>* clon = myFSet.clone();
    ////dynamic_cast<FiniteSet<int>*>(clon)->print();
    ////std::cout << clon->isElInSet(4) << clon->isElInSet(3) << clon->isElInSet(6) << clon->isElInSet(1);
    //delete clon;
    
    createTestFiles();
    myProgram<int>("Input.txt");

}