/*
 * DynamicList.cpp
 * Implementation file for DynamicLists
 * Linked List Practice for Data Structures and Algorithms
 */

#include "DynamicList.h"
#include <iostream>

// Methods (inserts, deletes, print, search)

/*
 * Insert a new node at the beginning of a list
 */
void DynamicList::insertFirst(int x) {
    DynamicNode* q = new DynamicNode; // create new node
    q->info = x; // assign the value to the node
    q->next = head; // assign the q pointer the value of the head pointer
    head = q; // assign head pointer to the new node
}

/*
 * Insert after some other node (not first)
 */
void DynamicList::insertAfter(DynamicNode *p, int x) {
    // check if empty
    if (p == nullptr) {
        std::cout << "void insertion\n";
        exit(1);
    }
    DynamicNode* q = new DynamicNode; // create new node to insert
    q->info = x; // assign the value to the node
    q->next = p->next; // assign new node's pointer with the pointer memory of the old node (place node after old node)
    p->next = q; // the new node will be after the old node
}

/*
 * Insert at the end of the list
 */
void DynamicList::insertLast(int x) {
    DynamicNode* p = new DynamicNode; // the node we want to add as the last on the list
    p->info = x; // assign the value to the node
    p->next = nullptr; // assign the null memory address
    DynamicNode* q = nullptr; // q is a temp to traverse the list
    if (head == nullptr) { // check for empty list
        head = p; // the node would be the first
    }
    else {
        // search for the last node
        for (q = head; q -> next != nullptr; q = q->next) ; // empty loop body, get to the end
        q->next = p; // after q reaches the end, p will become the last node
    }
}

/*
 * search for a node in the list
 */
DynamicNode* DynamicList::search(int x) {
    DynamicNode* p = head; // node to iterate through the list
    for (p; p != nullptr; p = p->next) // while p is not at the end, go through each node
        if (p->info == x) // if the node is equal to the value we are looking for
            return p; // return that node

    return nullptr; // if x is not on the list
}

/*
 * Delete first node on the list
 */
int DynamicList::deleteFirst() {
    if (head == nullptr) { // check for empty list
        std::cout << "Empty List\n";
    }
    int temp = head->info; // the data of the head
    if (head->next != nullptr) { // more than one node on the list
        DynamicNode* newHead = head->next; // move to the next head
        delete head; // delete the data and memory of the old head
        head = newHead; // give head the data and memory of new head
    }
    else { // one node in the list -> make list empty
        delete head; // delete the data and memory of the old head
        head = nullptr; // empty list
    }
    return temp; // return the data of the old head (first node which is deleted)
}

/*
 * Delete node which is not first on the list
 */
int DynamicList:: deleteAfter(DynamicNode *p) {
    // if empty
    if ((p == nullptr) || p->next == nullptr) {
        std::cout << "void deletion";
        exit(1);
    }
    DynamicNode *q = p->next; // just a temp to the next of p
    int temp = q->info; // the data so we can return it
    p->next = q->next; // update the next's
    delete q; // delete the actual node in memory
    return temp; // return the info on the node you deleted
}

/*
 * Remove all nodes whose info fields contain x
 */
void DynamicList::removeX(int x) {
    DynamicNode* p = head; // p is the first node
    DynamicNode* q = nullptr; // q will be the one behind p, null for now
    while (p != nullptr) { // traverse the list
        if (p->info == x) { // you found it
            p = p->next; // update memory address
            if (q == nullptr) { // if q is still null, then p is still first node in the list
                deleteFirst(); // remove first node of the list
            }
            else { // if q is not null, then p is not the first node, it's the one after q
                deleteAfter(q); // q is before p, p has info = x
            }
        }
        else {
            // advance to the next node of list
            q = p; // q is after p
            p = p->next; // p advances
        }
    }
}

void DynamicList::print() {
    if (head == nullptr) { // check for empty list
        std::cout << "Empty List\n";
    }
    DynamicNode* p = head; // node to go through the list, start at head
    while (p != nullptr) {
        std::cout << p->info; // print the data of the node
        if (p->next != nullptr) {
            std::cout << "->";
        }
        else {
            std::cout << "\n";
        }
        p = p->next;
    }
}

// bool DynamicList::isEmpty() {}
