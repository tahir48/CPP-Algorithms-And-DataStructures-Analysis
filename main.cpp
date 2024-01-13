#include <iostream>
#include <chrono>
#include "LinkedList/LinkedList.h"
#include "TimeComplexityTests/LinkedList/LinkedListTimeComplexity.h"
#include "TimeComplexityTests/DoublyLinkedList/DoublyLinkedListTimeComplexity.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

void testLinkedList();
void testDoublyLinkedList();

int main() {
    testLinkedList();
    //testDoublyLinkedList();


    return 0;
}



void testLinkedList() {
    // LinkedList myList;
    // myList.insert(0,20);
    // myList.insert(0,10);
    // myList.insert(2,30);

    // myList.printList();

    int sizeX = 100000; 
    int sizeY = 200000;
    int numRepeats = 100; 
    
    compareAppendTimes(sizeX,sizeY,numRepeats);
    // comparePrintTimes(sizeX, sizeY);
    // compareAppendTimes(sizeX, sizeY);
    // comparePopTimes(sizeX, sizeY);
    //compareReverseTimes(sizeX, sizeY);

    // compareGetValueTimes(sizeX, sizeY, 0);
    // compareGetValueTimes(sizeX, sizeY, sizeX / 2);
    // compareGetValueTimes(sizeX, sizeY, sizeX - 1);  // I doubt this approach. I will reconsider very soon.}
}

void testDoublyLinkedList() {
    // DoublyLinkedList myList;

    // myList.append(10);
    // myList.append(20);
    // myList.append(30);
    // myList.append(40);
    // myList.append(50);

    // myList.printList();



    int sizeX = 10000; 
    int sizeY = 20000;
    compareDoublyLinkedListAppendTimes(sizeX, sizeY);
}

