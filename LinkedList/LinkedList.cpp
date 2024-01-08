#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0) {

}


void LinkedList::printList() {
    Node* tmp = head;
    while (tmp != nullptr) {
        std::cout << "LinkedList item ************** " << tmp->value << std::endl;
        tmp = tmp->next;
    }
}


void LinkedList::append(int value) {
    Node* newnode = new Node(value);
    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    length++;
}

void LinkedList::prepend(int value){
    Node* newnode = new Node(value);
    if(head == nullptr){
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
    length++;
}


void LinkedList::pop(){ //three edge cases, empty, single and multiple elements
    if(head == nullptr){
        return ;
    }
    if(length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
    }else {
        Node* tmp = head;
        while(tmp->next->next != nullptr)
        {
            tmp = tmp->next;
        }
        delete tmp->next; 
        tmp->next = nullptr;
        tail = tmp;
    }
    length--;
}

void LinkedList::popFirst(){ //three edge cases, empty, single and multiple elements
    if(head == nullptr){
        return;
    }
    if(length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
    } else{
        Node* tmp = head;
        head = tmp->next;
        tmp->next = nullptr;
        delete tmp;
    }
    length--;
}


int LinkedList::getValue(int index) { // Edge cases: empty list, negative index input, index out of bound.
    if (head == nullptr || index < 0) {
        return -1;
    }

    Node* tmp = head;
    int i = 0;
    while (tmp != nullptr && i < index) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == nullptr) {
        return -1;
    }

    return tmp->value;
}


Node* LinkedList::getNode(int index){ // Edge cases: empty list, negative index input, index out of bound.
    if (head == nullptr || index < 0) {
        throw std::invalid_argument("Invalid index or empty list"); // Another way of handling edge cases. More readable.
    }

    Node* tmp = head;
    int i = 0;
    while (tmp != nullptr && i < index) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == nullptr) {
        throw std::out_of_range("Index out of bounds"); 
    }

    return tmp;
}


void LinkedList::remove(int index){ // edge cases: empty list, removing the first node, removing the last node, index Out of Bounds
    if(head == nullptr){
        throw std::invalid_argument("empty list");
    }

    if(index < 0 || index > length-1){
        throw std::invalid_argument("Invalid index");
    }

    if(index == 0){
        this->popFirst();
        return;
    }

    if(index == length-1)
    {
        this->pop();
        return;
    } 

    Node* before = this->getNode(index - 1);
    Node* tmp = before->next;
    before->next = tmp->next;
    delete tmp;

    length--;
}

