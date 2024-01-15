#include "DoublyLinkedList.h"
#include <iostream>

namespace DoublyLinkedList {

    DoublyLinkedList::DoublyLinkedList(): head(nullptr), tail(nullptr), length(0){
    }



    void DoublyLinkedList::append(int value){ // edge cases : the list is empty
        DNode* newnode = new DNode(value);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        } else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;

        }
        length++;
    }

    void DoublyLinkedList::printList(){
    if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        DNode* tmp = head;
        while(tmp != nullptr){
            std::cout << "Doubly Linked List item ************** " << tmp->value << std::endl;
            tmp = tmp->next;
        }
    }

    void DoublyLinkedList::prepend(int value){ // edge cases : the list is empty
        DNode* newnode = new DNode(value);
        if(head == nullptr){
            head = newnode;
            tail = newnode;
        } else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        length++;
    }

    void DoublyLinkedList::pop(){ //three edge cases, empty, single and multiple elements
        if(head == nullptr){
            return;
        }

        if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
            
        }else {
            DNode* tmp = tail->prev;
            delete tail;
            tmp->next = nullptr;
            tail = tmp;
        }
        length--;
    }

    void DoublyLinkedList::popFirst(){ //three edge cases, empty, single and multiple elements
        if(head == nullptr){
            return;
        }

        if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
            
        }else {
            DNode* tmp = head->next;
            delete head;
            tmp->prev = nullptr;
            head = tmp;
        }
        length--;
    }

}