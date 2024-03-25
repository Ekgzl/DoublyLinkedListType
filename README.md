# C++ Doubly Linked List Implementation

This repository contains an implementation of a doubly linked list data structure in C++.

## File Structure

- **doubly.h**: Contains the definition of the doubly linked list class and its member functions.
- **main.cpp**: Test program demonstrating the usage of the doubly linked list.

## How to Use

1. Clone or download the project to your computer.
2. Compile the `main.cpp` file with your C++ compiler (`g++`, `clang++`, etc.).
3. Run the compiled program to test the doubly linked list operations.

## Example Usage

```cpp
#include <iostream>
#include "doubly.h"

using namespace std;

int main() {
    // Create a doubly linked list
    doublyLinkedList<int> list;

    // Insert elements into the list
    int temp = 3;
    int a = 5;
    int b = 9;
    int c = 13;

    list.insertFirst(a);
    list.insertLast(b);
    list.insertFirst(c);
    list.insertLast(temp);

    // Print the list
    cout << "List: " << list << endl;

    // Delete elements from the list
    list.deleteNode(a);
    cout << "List after deleting " << a << ": " << list << endl;

    list.deleteNode(99); // Trying to delete an item not in the list
    list.deleteNode(b);
    cout << "List after deleting " << b << ": " << list << endl;

    list.deleteNode(c);
    cout << "List after deleting " << c << ": " << list << endl;

    list.deleteNode(temp);
    cout << "List after deleting " << temp << ": " << list << endl;

    list.deleteNode(13); // Trying to delete an item not in the list

    return 0;
}
