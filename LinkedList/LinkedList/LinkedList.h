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

class LinkedList
{
public:
	Node* Head = nullptr;

public:
	LinkedList() {}
	~LinkedList() 
	{
		Clear();
	}

	void Add(int data)
	{
		if (Head == nullptr)
		{
			Head = new Node(data);
		}
		else
		{
			Node* n = Head;

			while (n->Next != nullptr)
			{
				n = n->Next;
			}

			n->Next = new Node(data);
		}
	}

	void Delete(int data)
	{
		if (Head->Data == data)
		{
			Node* temp = Head->Next;
			delete Head;
			Head = temp;
			return;
		}

		Node* n = Head;

		while (n->Next != nullptr)
		{
			if (n->Next->Data == data)
			{
				Node* temp = n->Next;
				n->Next = n->Next->Next;
				delete temp;
				return;
			}
			else
			{
				n = n->Next;
			}
		}

		cout << "삭제할 원소가 존재하지 않습니다." << endl;
	}

	void Clear()
	{
		if (Head == nullptr)
			return;
		
		Node* n = Head;

		while (n != nullptr)
		{
			Node* temp = n->Next;
			delete n;
			n = temp;
		}
	}

	void ShowAll()
	{
		Node* n = Head;

		while (n != nullptr)
		{
			cout << n->Data << ", ";
			n = n->Next;
		}
	}
};