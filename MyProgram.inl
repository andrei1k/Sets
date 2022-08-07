#ifndef MYPROGRAM_INL
#define MYPROGRAM_INL

#include <iostream>
#include "MyProgram.h"

template <typename SetType>
bool devideByAtAny(const SetType* elements, unsigned elCount, SetType element) {

    for (unsigned i = 0; i < elCount; i++) {
        if (element % elements[i] == 0) {
            return true;
        }
    }

    return false;
}

template <typename SetType>
bool devideByAtAll(const SetType* elements, unsigned elCount, SetType element) {

    for (unsigned i = 0; i < elCount; i++) {
        if (element % elements[i] != 0) {
            return false;
        }
    }

    return true;
}

template<typename SetType>
void myProgram(const char path[]) {

    std::ifstream in(path);
    if (!in.is_open()) {

        std::cout << "Can not open file with file names.";
        return;
    }


    Set<SetType>* result = nullptr;
    bool first = true;

    for (; !in.eof();) {

        char buffer[256];
        in.getline(buffer, 256);
        result = binaryFileManipulations(buffer, result, first);
        if (first) {
            break;
        }
    }

    if (first) {
        std::cout << "Nunber is expected to be read from files.";
    }
    else {
        printElInRangeCount(result);
    }
    

    if(result)
        delete result;

    in.clear();
    in.close();

}

template <typename SetType>
Set<SetType>* binaryFileManipulations(const char filePath[], Set<SetType>* result, bool& first) {

    std::ifstream in(filePath, std::ios::binary);
    if (!in.is_open()) {
        std::cout << "Can not open this binary file.";
        return result;
    }

    short int N, T;
    
    in.read(reinterpret_cast<char*>(&N), sizeof(short));
    in.read(reinterpret_cast<char*>(&T), sizeof(short));

    if (N > 32) {
        std::cout << "N is too big. We will count it as 32";
        N = 32;
    }

    int setEl[32];
    for (int i = 0; i < N; i++) {

        in.read(reinterpret_cast<char*>(setEl + i), sizeof(int));
    }

    if (T != 0 && T != 1 && T != 2 && T != 8 && T != 9 && T != 10) {

        std::cout << "T is invalid number. Result was not changed.";
        in.clear();
        in.close();
        return result;
    }

    if (!in.good()) {
        first = true;
        return result;
    }

    Set<SetType>* sets[2];
    sets[1] = result;


    if (first) {
        first = false;
        FiniteSet<SetType> newResult(setEl, N);
        result = newResult.clone();
    }
    else if (T == 0) {
        FiniteSet<SetType> set(setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetUnion<SetType>(sets, 2);
        delete result;
        result = newResult;
    }
    else if (T == 1) {
        ConditionSet<SetType> set(&devideByAtAll, setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetUnion<SetType>(sets, 2);
        delete result;
        result = newResult;
    }
    else if (T == 2) {
        ConditionSet<SetType> set(&devideByAtAny, setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetUnion<SetType>(sets, 2);
        delete result;
        result = newResult;
    }
    else if (T == 8) {
        FiniteSet<SetType> set(setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetIntersection<SetType>(sets, 2);
        delete result;
        result = newResult;
    }
    else if (T == 9) {
        ConditionSet<SetType> set(&devideByAtAll, setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetIntersection<SetType>(sets, 2);
        delete result;
        result = newResult;
    }
    else if (T == 10) {
        ConditionSet<SetType> set(&devideByAtAny, setEl, N);
        sets[0] = &set;
        Set<SetType>* newResult = new SetIntersection<SetType>(sets, 2);
        delete result;
        result = newResult;
    }

    in.clear();
    in.close();
    
    return result;
}

template <typename SetType>
void printElInRangeCount(const Set<SetType>* set) {

    int start, end, count = 0;
    bool wrong = 0;
    do {
        std::cout << "\nEnter the range: ";
        wrong = 0;
        std::cin >> start;
        if (exceptionHanderForRangre(std::cin)) {
            wrong = 1;
        }
        std::cin >> end;
        if (exceptionHanderForRangre(std::cin)) {
            wrong = 1;
        }

        if (start > end && wrong == 0) {
            wrong = 1;
            std::cout << "\nInvalid range";
        }
    } while (wrong);

    for (int i = start; i <= end; i++) {

        if (set->isElInSet(i)) {
            count++;
            //std::cout << i << ' ';

        }
    }

    std::cout << "\nInterval [" << start << ',' << end << "] Result: " << count;
}

void IsIstreamGood(std::istream& in) {
    if (!in.good()) {
        in.clear();
        in.ignore();
        throw std::invalid_argument("\nExpexted to read number.");
    }
}

//template<typename SetType>
//void exceptionHanderForFileReading(std::istream& in, Set<SetType>* result) {
//    try
//    {
//        IsIstreamGood(in);
//    }
//    catch (const std::exception& ex)
//    {
//        std::cout << ex.what();
//        if (result) {
//            delete[] result;
//        }
//        exit(0);
//    }
//}

bool exceptionHanderForRangre(std::istream& in) {
    try
    {
        IsIstreamGood(in);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
        return 1;
    }
    return 0;
}

void createTestFiles() {

    std::ofstream out("Input.txt");
    if (out.is_open()) {
        out << "first.dat\n" << "second.dat\n" << "set.dat";
    }
    out.clear();
    out.close();
    std::ofstream b1("first.dat", std::ios::binary);
    std::ofstream b2("second.dat", std::ios::binary);
    std::ofstream b3("set.dat", std::ios::binary);

    if (!b1.is_open() || !b2.is_open() || !b3.is_open()) {
        b1.close();
        b2.close();
        b3.close();
        return;
    }
    short a = 5;
    b1.write(reinterpret_cast<const char*>(&a), sizeof(short));
    a = 0;
    b1.write(reinterpret_cast<const char*>(&a), sizeof(short));
    int arr[] = { 1, 3, 4, 6, 2 };
    b1.write(reinterpret_cast<const char*>(arr), sizeof(arr));

    a = 5;
    b2.write(reinterpret_cast<const char*>(&a), sizeof(short));
    a = 0;
    b2.write(reinterpret_cast<const char*>(&a), sizeof(short));
    int arr1[] = { 1,10,12,16,2 };
    b2.write(reinterpret_cast<const char*>(arr1), sizeof(arr1));

    a = 3;
    b3.write(reinterpret_cast<const char*>(&a), sizeof(short));
    a = 10;
    b3.write(reinterpret_cast<const char*>(&a), sizeof(short));
    int arr2[] = { 2, 3, 5};
    b3.write(reinterpret_cast<const char*>(arr2), sizeof(arr2));

    b1.clear();
    b1.close();
    b2.clear();
    b2.close();
    b3.clear();
    b3.close();
}

#endif // !MYPROGRAM_INL
