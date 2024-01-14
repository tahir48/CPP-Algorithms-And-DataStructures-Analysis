#include "LinkedList.h"
#include <iostream>
namespace LinkedList {

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

    void LinkedList::removeByValue(int value) { // edge cases: empty list, removing the first node, removing the last node, value not exist
        if (head == nullptr) {
            throw std::invalid_argument("The list is empty");
        }

        if (head->value == value) {
            this->popFirst();
            return;
        }

        Node* tmp = head;
        while (tmp->next != nullptr && tmp->next->value != value) {
            tmp = tmp->next;
        }

        if (tmp->next == nullptr) {
            throw std::invalid_argument("Value not found in the list");
        }

        Node* nodeToRemove = tmp->next;
        tmp->next = nodeToRemove->next;
        
        if (nodeToRemove == tail) {
            tail = tmp;
        }

        delete nodeToRemove;
        length--;
    }

    void LinkedList::setValue(int index, int value){ // edge cases: empty list, index out of bounds
        if(head == nullptr){
            throw std::invalid_argument("The list is empty");
        }

        if(index < 0 || index > length-1){
            throw std::invalid_argument("Invalid index");
        }
        
        Node* current = this-> getNode(index);
        current->value = value;
    }

    void LinkedList::reverse(){// edge cases: empty list, list contains only one element, 
        if(head == nullptr || head->next == nullptr){
                throw std::invalid_argument("The list is empty");
        }

        Node* before = nullptr;
        Node* current = head;
        Node* after = nullptr;
        tail = head;
        while(current != nullptr){
            after = current->next;
            current->next = before;
            before = current;
            current = after;
        }
        head = before;
    }



    void LinkedList::insert(int index, int value) { // edge cases: list is empty, index out of range, prepending to first node, appending to the last node
        if (index < 0 || index > length) { // end of the list is also allowed
            throw std::out_of_range("Index out of bounds");
        }

        Node* newNode = new Node(value);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (length == 0) {
                tail = newNode;
            }
        } else {
            Node* current = head;

            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
            
            if (index == length) {
                tail = newNode;
            }
        }

        length++;
    }
}