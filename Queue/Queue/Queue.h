#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int Data = 0;
	Node* Next = nullptr;

public:
	Node(int data) : Data(data) {}
};

class Queue
{
public:
	Node* first = nullptr;	

public:
	Queue() {}
	~Queue() { Clear(); }

	void Add(int data)
	{
		Node* newNode = new Node(data);

		if (first == nullptr)
		{
			first = newNode;
			return;
		}			
		
		Node* n = first;
		while (n->Next != nullptr)
		{
			n = n->Next;
		}

		n->Next = newNode;
	}

	int Dequeue()
	{
		if (first == nullptr)
			return 0;
		
		Node* temp = first;
		int result = first->Data;

		first = first->Next;

		delete temp;
		return result;
	}

	int Peek()
	{
		if (first == nullptr) return 0;

		return first->Data;
	}

	bool IsEmpty()
	{
		return first == nullptr;
	}

	void Clear()
	{
		if (first == nullptr)
			return;

		Node* n = first;
		while (n != nullptr)
		{
			Node* temp = n;
			n = n->Next;
			delete temp;
		}
	}
};

