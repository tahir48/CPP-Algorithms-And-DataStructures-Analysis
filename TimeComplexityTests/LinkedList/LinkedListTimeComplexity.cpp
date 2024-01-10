#include "LinkedListTimeComplexity.h"
#include <iostream>
#include <chrono>
#include "../../LinkedList/LinkedList.h"

// printList method
double measurePrintTime(int listSize) {
    LinkedList myList;

    for (int i = 0; i < listSize; ++i) {
        myList.append(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    myList.printList();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}

void comparePrintTimes(int sizeX, int sizeY) {
    double timeX = measurePrintTime(sizeX);
    double timeY = measurePrintTime(sizeY);

    std::cout << "Time taken to print a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Time taken to print a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}

// append method
double measureAppendTime(int listSize){

    LinkedList myList;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < listSize; ++i) {
        myList.append(i);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end-start;

    return duration.count();
}

void compareAppendTimes(int sizeX, int sizeY) {
    double timeX = measureAppendTime(sizeX);
    double timeY = measureAppendTime(sizeY);

    std::cout << "Time taken to append a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Time taken to append a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}
