//
// Created by zubey on 30.11.2021.
//

#ifndef ASSIGNMENT2_6_DOUBLEDYNAMICLINKEDLIST_H
#define ASSIGNMENT2_6_DOUBLEDYNAMICLINKEDLIST_H

#include "PermanentEmployee.h"

class Node{
public:
    PermanentEmployee *data;
    Node *nextNode = nullptr, *previousNode= nullptr;

    Node(PermanentEmployee *data, Node *nextNode, Node *previousNode);

};

class DoubleDynamicLinkedList {
private:
    Node *head;
    int listSize = 0;
public:
    DoubleDynamicLinkedList();
    void add(PermanentEmployee *permanentEmployee);
    bool contains(PermanentEmployee *permanentEmployee);
    void print();
};


#endif //ASSIGNMENT2_6_DOUBLEDYNAMICLINKEDLIST_H
