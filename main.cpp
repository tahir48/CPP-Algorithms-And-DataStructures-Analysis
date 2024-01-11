#include <iostream>
#include <chrono>
#include "LinkedList/LinkedList.h"
#include "TimeComplexityTests/LinkedList/LinkedListTimeComplexity.h"

int main() {
    
    // LinkedList myList;
    // myList.insert(0,20);
    // myList.insert(0,10);
    // myList.insert(2,30);

    // myList.printList();

    int sizeX = 100000; 
    int sizeY = 200000;

    // comparePrintTimes(sizeX, sizeY);
    // compareAppendTimes(sizeX, sizeY);
    // comparePopTimes(sizeX, sizeY);
    compareReverseTimes(sizeX, sizeY);

    // compareGetValueTimes(sizeX, sizeY, 0);
    // compareGetValueTimes(sizeX, sizeY, sizeX / 2);
    // compareGetValueTimes(sizeX, sizeY, sizeX - 1);  // I doubt this approach. I will reconsider very soon.


    return 0;
}