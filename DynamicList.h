/*
 * DynamicList.h
 * Specification file for DynamicLists
 * Linked List Practice for Data Structures and Algorithms
 */
#ifndef LINKEDLISTS_ONE_DYNAMICLIST_H
#define LINKEDLISTS_ONE_DYNAMICLIST_H

#include <iostream>

struct DynamicNode {
    int info; // holds the int data of the node
    DynamicNode *next; // pointer to a node
};

class DynamicList {
private:
    DynamicNode *head;
public:
    // Constructors
    DynamicList() {
        head = nullptr; // we begin with an empty list
    }

    // Methods (inserts, deletes, print, search)
    void insertFirst(int x);
    void insertAfter(DynamicNode *p, int x);
    void insertLast(int x);
    DynamicNode* search(int x);
    int deleteFirst();
    int deleteAfter(DynamicNode *p);
    void removeX(int x);
    void print();
    //bool isEmpty();
};
#endif //LINKEDLISTS_ONE_DYNAMICLIST_H
