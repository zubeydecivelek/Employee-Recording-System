//
// Created by zubey on 30.11.2021.
//

#include "CircularArrayLinkedList.h"

CircularArrayLinkedList::CircularArrayLinkedList() {}

int CircularArrayLinkedList::size() {
    return arraySize;
}

void CircularArrayLinkedList::add(TemporaryEmployee *employee) {
    if (arraySize == maxSize){ //array doluysa
        return;
    }

    if(contains(employee)) return; //if array has the employee

    if (arraySize==0){ //array is empty
        tempNode *node = new tempNode(employee,-1);
        circularArray[arraySize] = node;
        firstElementIndex = arraySize;
        lastElementIndex = arraySize;
        arraySize++;
        return;
    }

    //add to the front
    if (employee->getEmployeeNumber() < circularArray[firstElementIndex]->temporaryEmployee->getEmployeeNumber()){
        tempNode *node = new tempNode(employee,firstElementIndex);
        firstElementIndex = arraySize;
        circularArray[arraySize] = node;
        arraySize++;
        return;
    }
    //finding add index
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != -1 && employee->getEmployeeNumber() > circularArray[circularArray[iter]->nextIndex]->temporaryEmployee->getEmployeeNumber()){
        iter = circularArray[iter]->nextIndex;
    }
    if (circularArray[iter]->nextIndex == -1){ //add back of the list
        tempNode *node = new tempNode(employee, -1);
        circularArray[iter]->nextIndex = arraySize;
        circularArray[arraySize] = node;
        lastElementIndex = arraySize;
        arraySize++;
    }
    else{ //add between two elements
        tempNode *node = new tempNode(employee, circularArray[iter]->nextIndex);
        circularArray[arraySize] = node;
        circularArray[iter]->nextIndex = arraySize;
        arraySize++;
    }
}


void CircularArrayLinkedList::toString() {
    outputString = "";
}

std::ostream &operator<<(std::ostream &os, const CircularArrayLinkedList &list) {
    os<<"["<< list.outputString<<"]";
    return os;
}

void CircularArrayLinkedList::printList() {
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != -1){
        std::cout<<circularArray[iter]->temporaryEmployee->getName()<<std::endl;
        iter = circularArray[iter]->nextIndex;
    }
    std::cout<<circularArray[iter]->temporaryEmployee->getName()<<std::endl;
}

bool CircularArrayLinkedList::contains(TemporaryEmployee *employee) {
    for (int i = 0;i<arraySize;i++){
        if (*circularArray[i]->temporaryEmployee == *employee) return true;
    }
    return false;
}


tempNode::tempNode(TemporaryEmployee *temporaryEmployee, int nextIndex) : temporaryEmployee(temporaryEmployee),
                                                                          nextIndex(nextIndex) {}
