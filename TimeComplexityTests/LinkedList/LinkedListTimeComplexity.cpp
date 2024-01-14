#include "LinkedListTimeComplexity.h"
#include <iostream>
#include <chrono>
#include "../../LinkedList/LinkedList.h"

namespace LinkedList {
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

    double measurePopTime(int listSize, int numRepeats) {
        double totalDuration = 0.0;

        for (int repeat = 0; repeat < numRepeats; ++repeat) {
            LinkedList myList;
            for (int i = 0; i < listSize; ++i) {
                myList.append(i);
            }

            auto start = std::chrono::high_resolution_clock::now();
            for (int i = listSize - 1; i >= 0; --i) {
                myList.pop();
            }
            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duration = end - start;
            totalDuration += duration.count();
        }

        return (totalDuration / numRepeats) / listSize;
    }

    void comparePopTimes(int sizeX, int sizeY, int numRepeats) {
        double timeX = measurePopTime(sizeX, numRepeats);
        double timeY = measurePopTime(sizeY, numRepeats);

        std::cout << "After number of " << numRepeats << " repeats, average time taken for individual pop operation for a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
        std::cout << "After number of " << numRepeats << " repeats, average time taken for individual pop operation for a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
        std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;

    }



    double measureReverseTime(int listSize, int numRepeats){
        double totalDuration = 0.0;
        LinkedList myList;

        for(int i = 0; i < listSize; ++i) {
            myList.append(i);
        }
        
        for (int repeat = 0; repeat < numRepeats; ++repeat) {
        auto start = std::chrono::high_resolution_clock::now();

        myList.reverse();

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> duration = end - start;

        totalDuration += duration.count();
        }
        return totalDuration / numRepeats;
    }



    void compareReverseTimes(int sizeX, int sizeY, int numRepeats){
        double timeX = measureReverseTime(sizeX, numRepeats);
        double timeY = measureReverseTime(sizeY, numRepeats);

        std::cout << "After number of " << numRepeats << " repeats, average time taken for individual reverse operation for a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
        std::cout << "After number of " << numRepeats << " repeats, average time taken for individual reverse operation for a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
        std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
    }


    double measureGetValueTime(int listSize, int index, int numRepeats) {
        double totalDuration = 0.0;

        LinkedList myList;

        for (int i = 0; i < listSize; ++i) {
            myList.append(i);
        }

        for (int repeat = 0; repeat < numRepeats; ++repeat) {
            auto start = std::chrono::high_resolution_clock::now();

            myList.getValue(index);

            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duration = end - start;

            totalDuration += duration.count();
        }

        return totalDuration / (numRepeats); 
    }

    void compareGetValueTimes(int sizeX, int sizeY, int numRepeats) {
        int indexX = sizeX / 2;  // For a consistent test, I choosed to report using the middle index
        int indexY = sizeY / 2; 
        double timeX = measureGetValueTime(sizeX, indexX, numRepeats);
        double timeY = measureGetValueTime(sizeY, indexY, numRepeats);

        std::cout << "After number of " << numRepeats << " repeats, average time taken to get value at index " << indexX << " (middle index) in a list of size " << sizeX << ": " << timeX << " ms" << std::endl;
        std::cout << "After number of " << numRepeats << " repeats, average time taken to get value at index " << indexY << " (middle index) in a list of size " << sizeY << ": " << timeY << " ms" << std::endl;
        std::cout << "Ratio of time taken (Y/X): " << timeY / timeX << std::endl;
    }
}



