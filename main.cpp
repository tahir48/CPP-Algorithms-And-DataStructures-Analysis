#include <iostream>
#include <chrono>
#include "LinkedList/LinkedList.h"
#include "TimeComplexityTests/LinkedList/LinkedListTimeComplexity.h"
#include "TimeComplexityTests/DoublyLinkedList/DoublyLinkedListTimeComplexity.h"
#include "DoublyLinkedList/DoublyLinkedList.h"

void testLinkedList();
void testDoublyLinkedList();

int main() {
    //testLinkedList();
    testDoublyLinkedList();


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
    
    // comparePrintTimes(sizeX, sizeY);
    // compareAppendTimes(sizeX,sizeY,numRepeats);
    // comparePopTimes(sizeX, sizeY, numRepeats);
    // compareReverseTimes(sizeX, sizeY, numRepeats);

    LinkedList::compareGetValueTimes(sizeX, sizeY, numRepeats);
    // compareGetValueTimes(sizeX, sizeY, sizeX / 2);
    // compareGetValueTimes(sizeX, sizeY, sizeX - 1);  // I doubt this approach. I will reconsider very soon.}
}

void testDoublyLinkedList() {

    // DoublyLinkedList::DoublyLinkedList myList;

    // myList.append(10);
    // myList.append(20);
    // myList.append(30);
    // myList.append(40);
    // myList.append(50);
    // myList.append(60);
    // myList.append(70);
    // myList.removeByValue(10);
    // myList.removeByValue(70);

    // // myList.printList();
    // //std::cout << myList.getValue(4) << std::endl;
    // // myList.pop();
    // // myList.popFirst();

    // myList.printList();


    int numRepeats = 101; 
    int sizeX = 10000; 
    int sizeY = 20000;
    // DoublyLinkedList::compareAppendTimes(sizeX, sizeY, numRepeats);
    // DoublyLinkedList::comparePrependTimes(sizeX, sizeY, numRepeats);
    //DoublyLinkedList::comparePopTimes(sizeX, sizeY, numRepeats);
    //DoublyLinkedList::compareGetValueTimes(sizeX, sizeY, numRepeats);
    DoublyLinkedList::compareRemoveTimes(sizeX, sizeY, numRepeats);
}

