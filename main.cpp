#include <iostream>
#include "doubly.h"

using namespace std;
int main() {
    doublyLinkedList<int> list;

    int temp = 3;
    int a = 5;
    int b = 9;
    int c = 13;

    list.insertFirst(a);
    list.insertLast(b);
    list.insertFirst(c);
    list.insertLast(temp);

    cout << list << endl;

    list.deleteNode(a);
    cout << list << endl;
    list.deleteNode(99);
    list.deleteNode(b);
    cout << list << endl;
    list.deleteNode(c);
    cout << list << endl;
    list.deleteNode(temp);
    cout << list << endl;
    list.deleteNode(13);

}