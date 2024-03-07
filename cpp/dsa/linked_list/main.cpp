#include "linked_list.cpp"
#include <iostream>

int main()
{
    // create a linked list of ints
    LinkedList<int> list = LinkedList<int>();

    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);

    list.printList();
    list.reverseOrder();
    list.printList();
}