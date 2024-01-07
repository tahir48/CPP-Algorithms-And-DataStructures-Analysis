#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), length(0) {

}


void LinkedList::print_list() {
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

void LinkedList::pop_first(){ //three edge cases, empty, single and multiple elements
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
