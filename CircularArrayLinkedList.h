//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_CIRCULARARRAYLINKEDLIST_H
#define ASSIGNMENT2_6_CIRCULARARRAYLINKEDLIST_H

#include <ostream>
#include "TemporaryEmployee.h"

class tempNode{
public:
    TemporaryEmployee *temporaryEmployee;
    int nextIndex;

    tempNode(TemporaryEmployee *temporaryEmployee, int nextIndex);
};

class CircularArrayLinkedList {
private:
    int arraySize = 0, maxSize = 20, firstElementIndex = -1, lastElementIndex = -1;
    tempNode *circularArray[20];
    std::string outputString;
public:
    int size();
    void add(TemporaryEmployee *employee);
    void toString();
    void printList();
    bool contains(TemporaryEmployee *employee);
    CircularArrayLinkedList();

    friend std::ostream &operator<<(std::ostream &os, const CircularArrayLinkedList &list);

};


#endif //ASSIGNMENT2_6_CIRCULARARRAYLINKEDLIST_H
