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
