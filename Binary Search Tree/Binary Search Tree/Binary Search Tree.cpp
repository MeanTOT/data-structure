#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree* BST = new BinarySearchTree();
    BST->Insert(10);
    BST->Insert(5);
    BST->Insert(12);
    BST->Insert(15);
    BST->Insert(20);
    BST->Insert(21);

    BST->InOrderTraversal();
    delete BST;

    return 0;
}