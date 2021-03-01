#include <iostream>
#include "LinkedList.h"

int main()
{      
    LinkedList* linkedList = new LinkedList();
    linkedList->Add(1);
    linkedList->Add(2);
    linkedList->Add(3);
    linkedList->Add(4);
    linkedList->Add(5);

    linkedList->Delete(3);

    linkedList->ShowAll();

    delete linkedList;

    return 0;
}