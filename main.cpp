#include <iostream>
#include "LinkedList/LinkedList.h"

int main() {
    LinkedList myList;

    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.prepend(40);
    myList.append(35);
    myList.append(40);
    myList.append(45);
    myList.pop();
    myList.pop();
    myList.pop_first();

    std::cout << "Here are all the elements of the linkedlist:" << std::endl;
    myList.print_list();

    return 0;
}
