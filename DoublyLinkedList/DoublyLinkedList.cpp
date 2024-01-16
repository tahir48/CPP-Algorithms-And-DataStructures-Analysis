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

    int DoublyLinkedList::getValue(int index) { // edge cases : the lis tis empty, index out of bounds.
        if (head == nullptr) {
            throw std::invalid_argument("List is empty.");
        }

        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds.");
        }

        DNode* tmp;
        if (index > length / 2) {
            tmp = tail;
            for (int i = 0; i < length - index - 1; ++i) {
                tmp = tmp->prev;
            }
        } else {
            tmp = head;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
        }
        return tmp->value;
    }

    DNode* DoublyLinkedList::getNode(int index) { // edge cases : the lis tis empty, index out of bounds.
        if (head == nullptr) {
            throw std::invalid_argument("List is empty.");
        }

        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds.");
        }

        DNode* tmp;
        if (index > length / 2) {
            tmp = tail;
            for (int i = 0; i < length - index - 1; ++i) {
                tmp = tmp->prev;
            }
        } else {
            tmp = head;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
        }
        return tmp;
    }

    void DoublyLinkedList::remove(int index) { // edge cases : the list is empty, index out of bounds, list has single elements
    // deleting from the begining, deleting from the end
        if (head == nullptr) {
            throw std::invalid_argument("List is empty.");
        }

        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds.");
        }

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            DNode* toDelete;
            if (index == 0) {
                toDelete = head;
                head = head->next;
                if (head) head->prev = nullptr;
            } else if (index == length - 1) {
                toDelete = tail;
                tail = tail->prev;
                if (tail) tail->next = nullptr;
            } else {
                if (index > length / 2) {
                    toDelete = tail;
                    for (int i = 0; i < length - index - 1; ++i) {
                        toDelete = toDelete->prev;
                    }
                } else {
                    toDelete = head;
                    for (int i = 0; i < index; ++i) {
                        toDelete = toDelete->next;
                    }
                }
                toDelete->prev->next = toDelete->next;
                toDelete->next->prev = toDelete->prev;
            }
            delete toDelete;
        }

        length--;
    }

    void DoublyLinkedList::removeByValue(int value) { // edge cases : the list is empty, list has single elements
    // the value is at the begining, the value is at the end, value not exist.
        if (head == nullptr) {
            throw std::invalid_argument("List is empty.");
        }

        if (head->value == value) {
            DNode* tmp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; 
            delete tmp;
            length--;
            return;
        }

        DNode* tmp = head;

        while (tmp != nullptr && tmp->value != value) {
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            throw std::invalid_argument("Value not found in the list");
        }

        if (tmp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            tmp->prev->next = tmp->next;
            if (tmp->next) {
                tmp->next->prev = tmp->prev;
            }
        }

        delete tmp;
        length--;
    }

}