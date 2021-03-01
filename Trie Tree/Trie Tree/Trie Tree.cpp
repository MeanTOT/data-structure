#include <iostream>
#include "Trie.h"

int main()
{
    Trie* trie = new Trie();   

    trie->Add("Cat");
    trie->Add("Car");
    trie->Add("Cow");
    trie->Add("Copy");
    trie->Add("Dog");
    trie->Add("Dol");
    trie->Add("Doli");
    trie->Add("Minsu");

    std::cout << trie->Find("Minsu") << std::endl;

    delete trie;

    return 0;
}