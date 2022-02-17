//
// Created by zubey on 30.11.2021.
//

#include "DoubleDynamicLinkedList.h"
DoubleDynamicLinkedList::DoubleDynamicLinkedList() {}

void DoubleDynamicLinkedList::add(PermanentEmployee *permanentEmployee) {
    if(listSize==0){ //add to empty list
        Node *newNode = new Node(permanentEmployee, nullptr, nullptr);
        head = newNode;
        listSize++;
        return;
    }
    if(contains(permanentEmployee)) return; //if array has the employee

    if (*permanentEmployee > *(head->data)){ //add to head -> if employee's appointment date is bigger
        Node *newNode = new Node (permanentEmployee, head, nullptr);
        head->previousNode = newNode;
        head = newNode;
        listSize++;
        return;
    }
    Node *iter = head;
    while (iter->nextNode != nullptr && *permanentEmployee < *(iter->data)){
        iter = iter->nextNode;
    }
    if (iter->nextNode == nullptr){ //add to last
        Node *newNode = new Node(permanentEmployee, nullptr,iter);
        iter->nextNode = newNode;
    }
    else{ //add between two nodes
        Node *newNode = new Node(permanentEmployee,iter,iter->previousNode);
        iter->previousNode->nextNode = newNode;
        iter->previousNode = newNode;
    }
    listSize++;
}

void DoubleDynamicLinkedList::print() {
    Node *iter = head;
    while (iter->nextNode != nullptr){
        std::cout<<iter->data->getName()<<std::endl;
        iter = iter->nextNode;
    }
    std::cout<<iter->data->getName()<<std::endl;

}

bool DoubleDynamicLinkedList::contains(PermanentEmployee *permanentEmployee) {
    Node *iter =head;
    while (iter->nextNode != nullptr){
        if (*iter->data == *permanentEmployee){
            return true;
        }
        iter = iter->nextNode;
    }
    if (*iter->data == *permanentEmployee) return true;
    return false;
}

Node::Node(PermanentEmployee *data, Node *nextNode, Node *previousNode) : data(data), nextNode(nextNode),
                                                                          previousNode(previousNode) {}


