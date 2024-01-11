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

// I pass prepend method since it is similar with append method

double measurePopTime(int listSize){
    LinkedList myList;

    for (int i = 0; i < listSize; ++i) {
        myList.append(i);
    }

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = listSize - 1; i >= 0; --i) {
        myList.pop();
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end-start; 
    return duration.count();
}

void comparePopTimes(int sizeX, int sizeY){
    double timeX = measurePopTime(sizeX);
    double timeY = measurePopTime(sizeY);

    std::cout << "Time taken to pop a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Time taken to pop a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}


double measureReverseTime(int listSize){
    LinkedList myList;

    for(int i = 0; i < listSize; ++i) {
        myList.append(i);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    myList.reverse();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count();
}


void compareReverseTimes(int sizeX, int sizeY){
    double timeX = measureReverseTime(sizeX);
    double timeY = measureReverseTime(sizeY);

    std::cout << "Time taken to reverse a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Time taken to reverse a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}


double measureGetValueTime(int listSize, int index) {
    LinkedList myList;

    for(int i = 0; i < listSize; ++i) {
        myList.append(i);
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        myList.getValue(index);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    return duration.count() / 1000;  // Average seems more appropriate, if I detect a hardware bottleneck, even median should be considered.
}

void compareGetValueTimes(int sizeX, int sizeY, int index) {
    double timeX = measureGetValueTime(sizeX, index);
    double timeY = measureGetValueTime(sizeY, index);

    std::cout << "Average time taken to get " << index << " th value from a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Average time taken to get " << index << " th value from a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}




