#ifndef CIRCULARARRAYLINKEDLIST_H
#define CIRCULARARRAYLINKEDLIST_H

#include <ostream>
#include "TemporaryEmployee.h"
#include <vector>

class tempNode{
public:
    TemporaryEmployee *temporaryEmployee;
    int nextIndex;
    tempNode(TemporaryEmployee *temporaryEmployee, int nextIndex);
};

class CircularArrayLinkedList {
private:
    std::vector<int> available = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int arraySize = 0, maxSize = 20, firstElementIndex = -1, lastElementIndex = -1;
    tempNode *circularArray[20];
public:
    void add(TemporaryEmployee *employee);
    void erase(int employeeNumber);
    bool contains(int employeeNumber);
    TemporaryEmployee* find(int employeeNumber);
    void convertToVector(std::vector<Employee*> *employeeVector);
    CircularArrayLinkedList();

};


#endif //CIRCULARARRAYLINKEDLIST_H
