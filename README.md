# Algortihms and Data Structures Implementation in C++

This repository contains a C++ implementation of Algortihms and Data structures. So far I have implemented singly linked list. 

## LinkedList Class Methods - Singly Linked List

- `printList`: Prints the entire list to the console.

- `append(int value)`: Appends a new node with the specified value to the end of the list.

- `prepend(int value)`: Prepends a new node with the specified value to the beginning of the list.

- `pop`: Removes and deletes the last node from the list.

- `popFirst`: Removes and deletes the first node from the list.

- `getValue(int index)`: Returns the value of the node at the specified index. Throws an exception if the index is out of range.

- `getNode(int index)`: Returns a pointer to the node at the specified index. Returns `nullptr` if the index is out of range.

- `remove(int index)`: Removes and deletes the node at the specified index. Throws an exception if the index is out of range.

- `removeByValue(int value)`: Removes the first node that contains the specified value. Throws an exception if the list is empty or the value is not found.

- `setValue(int index, int value)`: Sets the value of the node at the specified index to a new value. Throws an exception if the index is out of range.

- `reverse()`: Reverses the order of the nodes in the list.




# Time Complexity Analysis
In this project, I have conducted an analysis of the time complexity for various methods in our data structures. This analysis helps to understand the efficiency of algorithms and their performance as the size of the input data scales.

## Methods Analyzed
LinkedList::printList(): Measures the time taken to print all elements in the list.


Analysis Approach
To analyze the time complexity, we implemented specific test functions that measure the execution time of each method with varying input sizes. These tests are located in the TimeComplexityTests directory. The key idea is to observe how the execution time changes as the size of the input increases.

## Results and Observations
### LinkedList::printList():

Time taken to print a list of size 10000: 2064.1 ms
Time taken to print a list of size 20000: 4031.06 ms
Ratio of time taken (20000/10000): 1.95294

Observation: The time taken to print the list scales linearly with the number of elements, suggesting an O(n) time complexity for the printList method.



### LinkedList::append():

Time taken to append a list of size 10000: 0 ms
Time taken to append a list of size 20000: 0.999 ms
Ratio of time taken (20000/10000): inf

Time taken to append a list of size 100000: 2.997 ms
Time taken to append a list of size 200000: 6.527 ms
Ratio of time taken (200000/100000): 2.17784

Time taken to append a list of size 1000000: 36.964 ms
Time taken to append a list of size 2000000: 83.023 ms
Ratio of time taken (2000000/1000000): 2.24605

Observation: Results are interesting, indeed. Since it has a tail, I was expecting appending an element to the tail of the list to take constant time since it is an O(1) operation, regardless of the size of the list (We know that O(1) is the worst-case scenario). However, I am observing a linear growth i.e., O(n). After my searches, I suspect several factors such as system load, inefficiencies in memory allocation (as the list grows larger), or maybe other overheads that occur with larger data sets. I hope to write additional notes here after I do some more search, or maybe try on a different machine.




