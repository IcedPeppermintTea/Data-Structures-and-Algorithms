#include "DynamicQueue.h"
#include <iostream>
#include <stdlib.h>

//-------------------------------------------------------------------------------
// constructors
//-------------------------------------------------------------------------------
/********************************************************************************
default constructor
********************************************************************************/
DynamicQueue::DynamicQueue() {
    front = nullptr;
    rear = nullptr;
}

//---------------------------------------------------------------
// methods (inserts and deletes)
//---------------------------------------------------------------
bool DynamicQueue::empty() {
    return (front == nullptr);
}

void DynamicQueue::insert(int x) {
    DynamicNode* p = new DynamicNode;
    p->info =x;
    p->next = nullptr;

    if (empty()) {
        front = p;
    }
    else {
        rear->next = p;
    }

    rear = p;
}

int DynamicQueue::remove() {
    if (empty()) {
        std::cout << "queue underflow";
        exit(1);
    }

    DynamicNode* p = front;
    int temp = p->info;
    front = p->next;
    delete p;
    if (front == nullptr)
        rear = nullptr;

    return temp;
}

void DynamicQueue::priorityQueue(char a, int size){
 // check if a already exists in the queue
     // if it DOES exist:
         // move node with a value to the rear (most recently referenced key)
     // if a does NOT exist in the queue
        // if queue is full (if queue contains QUEUESIZE elements)
            // remove front element of queue, then insert new node with a in the rear
        // if queue is NOT full
           // insert new node with a in rear of queue
}