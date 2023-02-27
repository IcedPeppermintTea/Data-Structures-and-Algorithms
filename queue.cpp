#include <iostream>
#include "DynamicQueue.h"

int main()
{
    // hardcode in main the following value:
    const int QUEUESIZE = 4;

    // test DynamicQueue
    DynamicQueue queue = DynamicQueue();
    queue.insert(5);
    std::cout << "Inserted 5 into queue" << std::endl;
    queue.insert(7);
    std::cout << "Inserted 7 into queue" << std::endl;
    queue.remove();
    std::cout << "Removed 5 from queue" << std::endl;
    queue.remove();
    std::cout << "Removed 7 from queue" << std::endl;
    // code should exit here due to underflow
    std::cout << "Attempting to remove from an empty queue..." << std::endl;
    queue.remove();
}

