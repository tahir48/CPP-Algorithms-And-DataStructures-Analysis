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

The correct results are:
After number of 100 repeats, average time taken for individual append operation to create a list of size 100000: 3.70577e-005 ms
After number of100 repeats, average time taken for individual append operation to create a list of size 200000: 3.71745e-005 ms
Ratio of time taken (Y/X): 1.00315

Observation: Since has a tail, the time taken to append the list constantly scales with the number of elements, suggesting an O(1) time complexity for the append method, regardless of the size of the list. The test is repeated for 100 times, and the average execution time is reported.

### LinkedList::pop() and LinkedList::popFirst():

**popFirst**
After number of 100 repeats, average time taken for individual popFirst operation for a list of size 100000: 2.02366e-005 ms
After number of100 repeats, average time taken for individual popFirst operation for a list of size 200000: 2.02631e-005 ms
Ratio of time taken (Y/X): 1.00131

**pop**
After number of 5 repeats, average time taken for individual pop operation for a list of size 100000: 0.0684338 ms
After number of5 repeats, average time taken for individual pop operation for a list of size 200000: 0.136989 ms
Ratio of time taken (Y/X): 2.00177

Observation: Expected complexity from popFirst was O(1) and pop was O(n). Based on the results, doubling the input sizes, popFirst method average execution time scaled constantly(O(1)), and pop time scaled linearly (O(n)).

### LinkedList::reverse():

After number of 100 repeats, average time taken for individual reverse operation for a list of size 100000: 0.20046 ms
After number of 100 repeats, average time taken for individual reverse operation for a list of size 200000: 0.41143 ms
Ratio of time taken (Y/X): 2.05243

Observations: reverse method has O(1) time complexity, which implies a linear relationship between the input size, and the time taken to execute the algorithm. Accordingly, doubling the input size, doubled the amount of time taken to execute the algortihm. 

### LinkedList::getValue(int index);

After number of 100 repeats, average time taken to get value at index 50000 (middle index) in a list of size 100000: 0.05592 ms
After number of 100 repeats, average time taken to get value at index 100000 (middle index) in a list of size 200000: 0.11526 ms
Ratio of time taken (Y/X): 2.06116

Observation: Expected complexity from getValue was O(n) since it traverse through a list to get a value at a specific index. Doubling the input sizes, getValue method average execution time scaled linearly (O(n)) as expected.





## Doubly LinkedList Class Methods - Doubly Linked List

- `append(int value)`: Appends a new node with the specified value to the end of the list.

- `printList`: Prints the entire list to the console.

- `prepend(int value)`: Prepends a new node with the specified value to the beginning of the list.

- `pop`: Removes and deletes the last node from the list.

- `popFirst`: Removes and deletes the first node from the list.

# Time Complexity Analysis

## Methods Analyzed
DoublyLinkedList::append(int value)
DoublyLinkedList::prepend(int value)
DoublyLinkedList::pop()
DoublyLinkedList::popFirst()


## Results and Observations
### DoublyLinkedList::append():

After 101 repeats
Size 10000 - Average time: 0.394266 ms, Median time: 0 ms
Size 20000 - Average time: 0.826253 ms, Median time: 1 ms
Ratio of average time taken (Y/X): 2.09567
Ratio of median time taken (Y/X): inf

Observations:

### DoublyLinkedList::prepend():

After 101 repeats
Size 10000 - Average time: 3.6298e-005 ms, Median time: 0 ms
Size 20000 - Average time: 3.75757e-005 ms, Median time: 1 ms
Ratio of average time taken (Y/X): 1.0352
Ratio of median time taken (Y/X): inf

Observations:

### DoublyLinkedList::pop():


Size 10000 - Average time: 2.99426e-005 ms, Median time: 0 ms
Size 20000 - Average time: 2.95866e-005 ms, Median time: 0.998 ms
Ratio of average time taken (Y/X): 0.988113
Ratio of median time taken (Y/X): inf

Observations:


### DoublyLinkedList::popFirst():

After 101 repeats
Size 10000 - Average time: 2.18386e-005 ms, Median time: 0 ms
Size 20000 - Average time: 2.18995e-005 ms, Median time: 0 ms
Ratio of average time taken (Y/X): 1.00279
Ratio of median time taken (Y/X): nan