#include "DoublyLinkedListTimeComplexity.h"
#include <iostream>
#include <chrono>
#include "../../DoublyLinkedList/DoublyLinkedList.h"
#include <vector>
#include <algorithm>  // sort
#include <numeric>    // accumulate

// Append method time complexity tests
std::pair<double, double> measureAppendTimeForDoubly(int listSize, int numRepeats = 1000) {
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
    double average = total / numRepeats;

    std::sort(durations.begin(), durations.end());
    double median = numRepeats % 2 == 0 ? (durations[numRepeats / 2 - 1] + durations[numRepeats / 2]) / 2
                                         : durations[numRepeats / 2];

    return std::make_pair(average, median);
}


void compareDoublyLinkedListAppendTimes(int sizeX, int sizeY) {
    std::pair<double, double> resultsX = measureAppendTimeForDoubly(sizeX);
    std::pair<double, double> resultsY = measureAppendTimeForDoubly(sizeY);

    double averageX = resultsX.first;
    double medianX = resultsX.second;
    double averageY = resultsY.first;
    double medianY = resultsY.second;

    std::cout << "Size " << sizeX << " - Average time: " << averageX << " ms, Median time: " << medianX << " ms" << std::endl;
    std::cout << "Size " << sizeY << " - Average time: " << averageY << " ms, Median time: " << medianY << " ms" << std::endl;
    std::cout << "Ratio of average time taken (Y/X): " << averageY / averageX << std::endl;
    std::cout << "Ratio of median time taken (Y/X): " << medianY / medianX << std::endl;
}