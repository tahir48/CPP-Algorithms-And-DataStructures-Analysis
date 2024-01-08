#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

class LinkedList {
public:
    
    LinkedList();
    void printList();
    void append(int value);
    void prepend(int value);
    void pop();
    void popFirst();
    int getValue(int index);
    Node* getNode(int index);
    void remove(int index);


private:
    Node* head;
    Node* tail;
    int length;
};

#endif 