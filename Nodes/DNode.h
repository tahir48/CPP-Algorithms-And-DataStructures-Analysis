#ifndef DNODE_H
#define DNODE_H

class DNode{
    public:
        int value;
        DNode* next;
        DNode* prev;


        DNode(int i);

};

#endif