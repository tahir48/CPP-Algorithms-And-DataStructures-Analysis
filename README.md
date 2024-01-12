# Algortihms and Data Structures Implementation in C++

This repository contains a C++ implementation of Algortihms and Data structures. So far I have implemented singly linked list. 

## Covered Data Structures
* LinkedList
* DoublyLinkedList

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

- `insert(int index, int value)`: Inserts a new node with the specified value to the specified index.


# Time Complexity Analysis
In this project, I have conducted an analysis of the time complexity for various methods in our data structures. This analysis helps to understand the efficiency of algorithms and their performance as the size of the input data scales.

## Methods Analyzed
LinkedList::printList(): Measures the time taken to print all elements in the list.
LinkedList::append(): Measures the time taken to append elements in the list.
LinkedList::pop(): Measures the time taken to append elements in the list.
LinkedList::reverse();
LinkedList::getValue(int index);

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


### LinkedList::pop():

Time taken to pop a list of size 10000: 68.563 ms
Time taken to pop a list of size 20000: 271.784 ms
Ratio of time taken (20000/10000): 3.964

Time taken to pop a list of size 100000: 6792.8 ms
Time taken to pop a list of size 200000: 27393.3 ms
Ratio of time taken (200000/100000): 4.0327

Observation: It is expected poping an element of the list should take linear time since it is an O(n) operation. However, I am observing a non-linear growth i.e., O(n^2). This result is similar to what we faced in the append method. 
How can I handle this problem? 
1. Take median of 1000 times running the same test.
2. Try on different machines, OS, etc. 

### LinkedList::reverse():


Time taken to reverse a list of size 100000: 196.913 ms
Time taken to reverse a list of size 200000: 396.76 ms
Ratio of time taken (Y/X): 2.0149

Observations: reverse method has O(1) time complexity, which implies a linear relationship between the input size, and the time taken to execute the algorithm. Accordingly, doubling the input size, doubled the amount of time taken to execute the algortihm. 

### LinkedList::getValue(int index);

Average time taken to get 0 th value from a list of size 10000: 0 ms
Average time taken to get 0 th value from a list of size 20000: 0 ms
Ratio of time taken (Y/X): nan

Average time taken to get 5000 th value from a list of size 10000: 0.006032 ms
Average time taken to get 5000 th value from a list of size 20000: 0.005743 ms
Ratio of time taken (Y/X): 0.952089

Average time taken to get 9999 th value from a list of size 10000: 0.012034 ms
Average time taken to get 9999 th value from a list of size 20000: 0.012035 ms
Ratio of time taken (Y/X): 1.00008

Observations: The getValue method is supposed to have O(n) time complexity. Here, despite the large list size, we observed an O(1) increase. I will complete this report after I also tried this method on a different PC and operating system. Also, I guess I need to reconsider my evaluation metric for methods that take an index as an input.




## Doubly LinkedList Class Methods - Doubly Linked List

- `append(int value)`: Appends a new node with the specified value to the end of the list.

- `printList`: Prints the entire list to the console.

# Time Complexity Analysis

## Methods Analyzed
DoublyLinkedList::append(int value)


## Results and Observations
### LinkedList::append():

Size 10000 - Average time: 0.394266 ms, Median time: 0 ms
Size 20000 - Average time: 0.826253 ms, Median time: 1 ms
Ratio of average time taken (Y/X): 2.09567
Ratio of median time taken (Y/X): inf

Observations: