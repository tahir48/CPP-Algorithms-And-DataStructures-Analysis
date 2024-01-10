#include <iostream>
#include <chrono>
#include "LinkedList/LinkedList.h"
#include "TimeComplexityTests/LinkedList/LinkedListTimeComplexity.h"

int main() {
    
    int sizeX = 100000; 
    int sizeY = 200000;

    // comparePrintTimes(sizeX, sizeY);
    compareAppendTimes(sizeX, sizeY);

    return 0;
}

//print method
// Time taken to print a list of size 10000: 2064.1 ms
// Time taken to print a list of size 20000: 4031.06 ms
// Ratio of time taken (Y/X): 1.95294

// append Method
// Time taken to append a list of size 10000: 0 ms
// Time taken to append a list of size 20000: 0.999 ms
// Ratio of time taken (Y/X): inf