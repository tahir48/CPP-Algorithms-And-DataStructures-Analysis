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
double measureAppendTime(int listSize, int numRepeats) {
    double totalDuration = 0.0;

    for (int repeat = 0; repeat < numRepeats; ++repeat) {
        LinkedList myList;

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < listSize; ++i) {
            myList.append(i);
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;
        totalDuration += duration.count();
    }

    return (totalDuration / numRepeats) / listSize; 
}

void compareAppendTimes(int sizeX, int sizeY, int numRepeats) {
    double timeX = measureAppendTime(sizeX, numRepeats);
    double timeY = measureAppendTime(sizeY, numRepeats);

    std::cout << "After number of " << numRepeats << " repeats, average time taken for individual append operation to create a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "After number of" << numRepeats << " repeats, average time taken for individual append operation to create a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
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
        myList.popFirst();
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end-start; 
    return duration.count()/listSize; //Since it reflects individual operation time for each pop method,
    // I prefered to divide it by listSize; 
}

void comparePopTimes(int sizeX, int sizeY){
    double timeX = measurePopTime(sizeX);
    double timeY = measurePopTime(sizeY);

    std::cout << "Average time taken to pop an individual element of a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
    std::cout << "Average time taken to pop an individual element of a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
    std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
}


double measureReverseTime(int listSize){
    LinkedList myList;

    for(int i = 0; i < listSize; ++i) {
        myList.append(i);
    }
    
    const int numRepeats = 1000;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numRepeats; ++i) {
        myList.reverse();
    }
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




