#include "CircularArrayLinkedList.h"

CircularArrayLinkedList::CircularArrayLinkedList() {}

void CircularArrayLinkedList::add(TemporaryEmployee *employee) {
    if (arraySize == maxSize){ //array doluysa
        return;
    }
    if (arraySize==0){ //array is empty
        tempNode *node = new tempNode(employee,0);
        circularArray[available[0]] = node;
        firstElementIndex = lastElementIndex = available[0];
        available.erase(available.begin());
        arraySize++;
        return;
    }

    //if(contains(employee->getEmployeeNumber())) return; //if array has the employee

    //add to the front
    if (employee->getEmployeeNumber() < circularArray[firstElementIndex]->temporaryEmployee->getEmployeeNumber()){
        tempNode *node = new tempNode(employee,firstElementIndex);
        firstElementIndex = available[0];
        circularArray[lastElementIndex]->nextIndex = available[0];
        circularArray[available[0]] = node;
        available.erase(available.begin());
        arraySize++;
        return;
    }
    //finding add index
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != firstElementIndex && employee->getEmployeeNumber() > circularArray[circularArray[iter]->nextIndex]->temporaryEmployee->getEmployeeNumber()){
        iter = circularArray[iter]->nextIndex;
    }
    if (circularArray[iter]->nextIndex == firstElementIndex){ //add back of the list
        tempNode *node = new tempNode(employee, firstElementIndex);
        circularArray[iter]->nextIndex = available[0];
        circularArray[available[0]] = node;
        lastElementIndex = available[0];
        available.erase(available.begin());
        arraySize++;
    }
    else{ //add between two elements
        tempNode *node = new tempNode(employee, circularArray[iter]->nextIndex);
        circularArray[available[0]] = node;
        circularArray[iter]->nextIndex = available[0];
        available.erase(available.begin());
        arraySize++;
    }
}

bool CircularArrayLinkedList::contains(int employeeNumber) {
    if (arraySize==0) return false;
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != firstElementIndex){
        if (circularArray[iter]->temporaryEmployee->getEmployeeNumber() == employeeNumber) return true;

        iter = circularArray[iter]->nextIndex;
    }
    if (circularArray[iter]->temporaryEmployee->getEmployeeNumber() == employeeNumber) return true;
    return false;
}

void CircularArrayLinkedList::erase(int employeeNumber) {
    if (circularArray[firstElementIndex]->temporaryEmployee->getEmployeeNumber() == employeeNumber) { //delete first element
        tempNode *node = circularArray[firstElementIndex];
        available.push_back(firstElementIndex);
        firstElementIndex = node->nextIndex;
        circularArray[lastElementIndex]->nextIndex = firstElementIndex;
        delete node;
    }
    else{
        int iter = firstElementIndex;
        while (circularArray[circularArray[iter]->nextIndex]->temporaryEmployee->getEmployeeNumber()!=employeeNumber){
            iter = circularArray[iter]->nextIndex;
        }
        if (circularArray[iter]->nextIndex == firstElementIndex){ // delete last element
            available.push_back(lastElementIndex);
            delete circularArray[lastElementIndex];
            circularArray[iter]->nextIndex = firstElementIndex;
            lastElementIndex = iter;
        }
        else{
            tempNode *node = circularArray[circularArray[iter]->nextIndex];
            available.push_back(circularArray[iter]->nextIndex);
            circularArray[iter]->nextIndex = circularArray[circularArray[iter]->nextIndex]->nextIndex;
        }
    }
    arraySize--;
}

void CircularArrayLinkedList::convertToVector(std::vector<Employee *> *employeeVector) {
    if (arraySize==0) return;
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != firstElementIndex){
        employeeVector->push_back(circularArray[iter]->temporaryEmployee);
        iter = circularArray[iter]->nextIndex;
    }
    employeeVector->push_back(circularArray[iter]->temporaryEmployee);
}

TemporaryEmployee *CircularArrayLinkedList::find(int employeeNumber) {
    int iter = firstElementIndex;
    while (circularArray[iter]->nextIndex != firstElementIndex){
        if (circularArray[iter]->temporaryEmployee->getEmployeeNumber() == employeeNumber) return circularArray[iter]->temporaryEmployee;
        iter = circularArray[iter]->nextIndex;
    }
    if (circularArray[iter]->temporaryEmployee->getEmployeeNumber() == employeeNumber) return circularArray[iter]->temporaryEmployee;
}


tempNode::tempNode(TemporaryEmployee *temporaryEmployee, int nextIndex) : temporaryEmployee(temporaryEmployee),
                                                                          nextIndex(nextIndex) {}
