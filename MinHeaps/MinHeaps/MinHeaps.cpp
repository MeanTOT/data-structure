#include <iostream>
#include <random>
#include "MinHeaps.h"

using namespace std;

int main()
{
    MinHeaps* minHeaps = new MinHeaps();  
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        minHeaps->Add(rand() % 1000);
    }

    minHeaps->Clear();
    delete minHeaps;
    return 0;
}