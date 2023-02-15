/*
 * dynamic.cpp
 * main file for DynamicList implementation
 * Linked List Practice for Data Structures and Algorithms
 */
#include "DynamicList.h"
#include <iostream>

int main() {
    DynamicList newList = DynamicList();

    newList.print();
    // test inserts
    newList.insertFirst(1);
    newList.insertFirst(2);
    newList.insertFirst(5);
    newList.insertFirst(3);
    std::cout << "The list after inserts: ";
    newList.print();

    // test search method and then insert after
    DynamicNode* first = newList.search(3);
    std::cout << "Search method works for when node is at head of list: ";
    std::cout << first->info << "\n";
    DynamicNode* notFound = newList.search(7); // for a node not found in the list
    if (notFound == nullptr)
        std::cout << "7 was not found\n";
    // std::cout << notFound->info;// avoid doing this...
    DynamicNode* dn = newList.search(2); // for a node in the list
    std::cout << "Search method works for when node is in list: ";
    std::cout << dn->info << "\n";
    newList.insertAfter(dn, 4);
    std::cout << "The list after using insertAfter method on the node we just found with search: ";
    newList.print();
    return 0;
}
