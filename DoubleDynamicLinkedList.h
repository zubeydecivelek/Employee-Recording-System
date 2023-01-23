#ifndef DOUBLEDYNAMICLINKEDLIST_H
#define DOUBLEDYNAMICLINKEDLIST_H
#include "PermanentEmployee.h"
#include "CircularArrayLinkedList.h"
#include "TemporaryEmployee.h"


class Node{
public:
    PermanentEmployee *data;
    Node *nextNode = nullptr;
    Node *previousNode= nullptr;
    ~Node();
    Node(PermanentEmployee *data, Node *nextNode, Node *previousNode);

};
class DoubleDynamicLinkedList {
private:
    Node *head;
    int listSize = 0;
public:
    DoubleDynamicLinkedList();
    void add(PermanentEmployee *permanentEmployee);
    void erase(int employeeNumber);
    bool contains(int employeeNumber);
    PermanentEmployee* findEmployee(int employeeNumber);
    void convertToVector(std::vector<Employee*> *employeeVector);
};


#endif //DOUBLEDYNAMICLINKEDLIST_H
