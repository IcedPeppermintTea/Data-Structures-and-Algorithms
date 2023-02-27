#ifndef DYNAMICQUEUE_H
#define DYNAMICQUEUE_H

struct DynamicNode{ // node is the same as in the dynamic list code
    int info;
    DynamicNode *next;
};

class DynamicQueue {
public:
    //---------------------------------------------------------------
    // constructors
    //---------------------------------------------------------------
    DynamicQueue();

    //---------------------------------------------------------------
    // methods (inserts and deletes)
    //---------------------------------------------------------------
    bool empty();
    void insert(int x);
    int remove();

    // Homework 1
    void priorityQueue(char a, int size);

private:
    DynamicNode* front;
    DynamicNode* rear;
};
#endif
