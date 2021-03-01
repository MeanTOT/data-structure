#pragma once
#include <vector>
#include <string>

class Node
{	
public:
	char Charactor;
	std::vector<Node*> Childs;
public:
	Node(char charactor) : Charactor(charactor) { }
};

class Trie
{
public:
	Node* Head = nullptr;

public:
	Trie()
	{
		
	}
	~Trie()
	{
		AllClrear();
	}

	void Add(std::string newString)
	{
		if (Head == nullptr)
			Head = new Node(' ');

		Node* currentNode = Head;
		size_t stringIndex = 0;
		while (stringIndex < newString.length())
		{
			bool isFound = false;
			for (size_t i = 0; i < currentNode->Childs.size(); i++)
			{
				if (currentNode->Childs[i]->Charactor == newString[stringIndex])
				{
					currentNode = currentNode->Childs[i];
					isFound = true;
					stringIndex++;
					break;
				}
			}

			if (currentNode->Childs.size() == 0 || isFound == false)
				break;
		}

		if (stringIndex < newString.length())
		{
			size_t remainCount = newString.length() - stringIndex;

			for (size_t i = 0; i < remainCount; i++)
			{
				currentNode->Childs.push_back(new Node(newString[stringIndex]));
				currentNode = currentNode->Childs[currentNode->Childs.size() - 1];
				stringIndex++;
			}
		}
	}

	bool Find(std::string target)
	{
		Node* currentNode = Head;
		size_t stringIndex = 0;
		bool isFound = false;

		while (stringIndex < target.length())
		{
			isFound = false;
			for (size_t i = 0; i < currentNode->Childs.size(); i++)
			{
				if (currentNode->Childs[i]->Charactor == target[stringIndex])
				{
					currentNode = currentNode->Childs[i];
					isFound = true;
					stringIndex++;
					break;
				}
			}

			if (isFound == false)
				break;
		}

		return isFound;
	}

private:
	void AllClrear()
	{
		AllClearInternalResursive(Head);
		delete Head;
		Head = nullptr;
	}

	void AllClearInternalResursive(Node* node)
	{
		for (int i = 0; i < node->Childs.size(); i++)
		{			
			AllClearInternalResursive(node->Childs[i]);
			delete node->Childs[i];
		}

		node->Childs.clear();
	}
};

