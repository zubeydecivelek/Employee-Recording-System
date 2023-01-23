#include "DoubleDynamicLinkedList.h"
#include <vector>

DoubleDynamicLinkedList::DoubleDynamicLinkedList() {}

void DoubleDynamicLinkedList::add(PermanentEmployee *permanentEmployee) {
    if(listSize==0){ //add to empty list
        Node *newNode = new Node(permanentEmployee, nullptr, nullptr);
        head = newNode;
        listSize++;
        return;
    }
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

bool DoubleDynamicLinkedList::contains(int employeeNumber) {
    Node *iter = head;
    while (iter != nullptr){
        if (iter->data->getEmployeeNumber() == employeeNumber){
            return true;
        }
        iter = iter->nextNode;
    }
    return false;
}

void DoubleDynamicLinkedList::erase(int employeeNumber) {
    if (head->data->getEmployeeNumber() == employeeNumber) { //delete the first element(head)
        Node *temp = head;
        head = head->nextNode;
        delete temp;
    } else {
        Node *iter = head->nextNode;
        while (iter->data->getEmployeeNumber() != employeeNumber) {
            iter = iter->nextNode;
        }
        if (iter->nextNode == nullptr) { //delete last element
            iter->previousNode->nextNode = nullptr;
        } else { //delete element between two nodes
            iter->previousNode->nextNode = iter->nextNode;
            iter->nextNode->previousNode = iter->previousNode;
        }
        delete iter;
    }
}

PermanentEmployee *DoubleDynamicLinkedList::findEmployee(int employeeNumber) {
    Node *iter = head;
    while (iter != nullptr){
        if (iter->data->getEmployeeNumber() == employeeNumber){
            return iter->data;
        }
        iter = iter->nextNode;
    }
}

void DoubleDynamicLinkedList::convertToVector(std::vector<Employee*> *permanentEmployeeVector) {
    Node *iter = head;
    while (iter != nullptr){
        permanentEmployeeVector->push_back(iter->data);
        iter = iter->nextNode;
    }
}

Node::Node(PermanentEmployee *data, Node *nextNode, Node *previousNode) : data(data), nextNode(nextNode),
                                                                          previousNode(previousNode) {}

Node::~Node() {
}