#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "../Nodes/DNode.h"

namespace DoublyLinkedList {

    class DoublyLinkedList{
        public:
            DoublyLinkedList();
            void append(int value);
            void printList();
            void prepend(int value);
            void pop();
            void popFirst();
        private:
            DNode* head;
            DNode* tail;
            int length;
    };
}
#endif