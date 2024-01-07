#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "../Node/Node.h"

class LinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    LinkedList();
    void print_list();
    void append(int value);
};

#endif 