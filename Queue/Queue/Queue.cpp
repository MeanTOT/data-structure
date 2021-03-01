#include <iostream>
#include "Queue.h"

int main()
{
    Queue* queue = new Queue();

    queue->Add(1);
    queue->Add(2);
    queue->Add(3);

    queue->Dequeue();
    queue->Dequeue();
    queue->Dequeue();

    delete queue;

    return 0;
}