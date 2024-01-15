#include "DoublyLinkedListTimeComplexity.h"
#include <iostream>
#include <chrono>
#include "../../DoublyLinkedList/DoublyLinkedList.h"
#include <vector>
#include <algorithm>  // sort
#include <numeric>    // accumulate

namespace DoublyLinkedList {

    // Append method time complexity tests
    std::pair<double, double> measureAppendTime(int listSize, int numRepeats) {
        std::vector<double> durations;
        durations.reserve(numRepeats);

        for (int repeat = 0; repeat < numRepeats; ++repeat) {
            DoublyLinkedList myList;
            auto start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < listSize; ++i) {
                myList.append(i);
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            durations.push_back(duration.count());
        }

        double total = std::accumulate(durations.begin(), durations.end(), 0.0);
        double average = (total / numRepeats) / listSize;

        std::sort(durations.begin(), durations.end());
        double median = numRepeats % 2 == 0 ? (durations[numRepeats / 2 - 1] + durations[numRepeats / 2]) / 2
                                            : durations[numRepeats / 2];

        return std::make_pair(average, median);
    }


    void compareAppendTimes(int sizeX, int sizeY, int numRepeats) {
        std::pair<double, double> resultsX = measureAppendTime(sizeX, numRepeats);
        std::pair<double, double> resultsY = measureAppendTime(sizeY, numRepeats);

        double averageX = resultsX.first;
        double medianX = resultsX.second;
        double averageY = resultsY.first;
        double medianY = resultsY.second;

        std::cout << "After " << numRepeats <<  " repeats" << std::endl;
        std::cout << "Size " << sizeX << " - Average time: " << averageX << " ms, Median time: " << medianX << " ms" << std::endl;
        std::cout << "Size " << sizeY << " - Average time: " << averageY << " ms, Median time: " << medianY << " ms" << std::endl;
        std::cout << "Ratio of average time taken (Y/X): " << averageY / averageX << std::endl;
        std::cout << "Ratio of median time taken (Y/X): " << medianY / medianX << std::endl;
    }


    // Prepend method time complexity tests
    std::pair<double, double> measurePrependTime(int listSize, int numRepeats) {
        std::vector<double> durations;
        durations.reserve(numRepeats);

        for (int repeat = 0; repeat < numRepeats; ++repeat) {
            DoublyLinkedList myList;
            auto start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < listSize; ++i) {
                myList.prepend(i);
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            durations.push_back(duration.count());
        }

        double total = std::accumulate(durations.begin(), durations.end(), 0.0);
        double average = (total / numRepeats) / listSize;

        std::sort(durations.begin(), durations.end());
        double median = numRepeats % 2 == 0 ? (durations[numRepeats / 2 - 1] + durations[numRepeats / 2]) / 2
                                            : durations[numRepeats / 2];

        return std::make_pair(average, median);
    }


    void comparePrependTimes(int sizeX, int sizeY, int numRepeats) {
        std::pair<double, double> resultsX = measurePrependTime(sizeX, numRepeats);
        std::pair<double, double> resultsY = measurePrependTime(sizeY, numRepeats);

        double averageX = resultsX.first;
        double medianX = resultsX.second;
        double averageY = resultsY.first;
        double medianY = resultsY.second;

        std::cout << "After " << numRepeats <<  " repeats" << std::endl;
        std::cout << "Size " << sizeX << " - Average time: " << averageX << " ms, Median time: " << medianX << " ms" << std::endl;
        std::cout << "Size " << sizeY << " - Average time: " << averageY << " ms, Median time: " << medianY << " ms" << std::endl;
        std::cout << "Ratio of average time taken (Y/X): " << averageY / averageX << std::endl;
        std::cout << "Ratio of median time taken (Y/X): " << medianY / medianX << std::endl;
    }


    // Pop time complexity test
    std::pair<double, double> measurePopTime(int listSize, int numRepeats) {
        std::vector<double> durations;
        durations.reserve(numRepeats);

        for (int repeat = 0; repeat < numRepeats; ++repeat) {
            DoublyLinkedList myList;

            for (int i = 0; i < listSize; ++i) {
                myList.append(i);
            }
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = listSize - 1; i >= 0; --i) {
                myList.pop();
                //myList.popFirst();
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> duration = end - start;
            durations.push_back(duration.count());
        }

        double total = std::accumulate(durations.begin(), durations.end(), 0.0);
        double average = (total / numRepeats) / listSize;

        std::sort(durations.begin(), durations.end());
        double median = numRepeats % 2 == 0 ? (durations[numRepeats / 2 - 1] + durations[numRepeats / 2]) / 2
                                            : durations[numRepeats / 2];

        return std::make_pair(average, median);
    }


    void comparePopTimes(int sizeX, int sizeY, int numRepeats) {
        std::pair<double, double> resultsX = measurePopTime(sizeX, numRepeats);
        std::pair<double, double> resultsY = measurePopTime(sizeY, numRepeats);

        double averageX = resultsX.first;
        double medianX = resultsX.second;
        double averageY = resultsY.first;
        double medianY = resultsY.second;

        std::cout << "After " << numRepeats <<  " repeats" << std::endl;
        std::cout << "Size " << sizeX << " - Average time: " << averageX << " ms, Median time: " << medianX << " ms" << std::endl;
        std::cout << "Size " << sizeY << " - Average time: " << averageY << " ms, Median time: " << medianY << " ms" << std::endl;
        std::cout << "Ratio of average time taken (Y/X): " << averageY / averageX << std::endl;
        std::cout << "Ratio of median time taken (Y/X): " << medianY / medianX << std::endl;
    }


}