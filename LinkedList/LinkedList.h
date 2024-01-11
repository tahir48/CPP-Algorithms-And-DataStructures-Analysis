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
    void removeByValue(int value);
    void setValue(int index, int value);
    void reverse();
    void insert(int index, int value);

private:
    Node* head;
    Node* tail;
    int length;
};

#endif 