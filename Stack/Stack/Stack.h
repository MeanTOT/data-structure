#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	Node* Next = nullptr;
	int Data = 0;
public:
	Node(int data) : Data(data) {}
};

class Stack
{
private:
	Node* mTop = nullptr;

public:
	Stack() {}
	~Stack()
	{
		if (mTop == nullptr)
		{
			return;
		}

		Node* n = mTop;

		while (n != nullptr)
		{
			Node* temp = n;
			n = n->Next;
			delete temp;
		}	
	}

	void Push(int data)
	{
		if (mTop == nullptr)
		{
			mTop = new Node(data);
			return;
		}
		
		Node* n = mTop;		
		while (n->Next != nullptr)
		{
			n = n->Next;
		}

		n->Next = new Node(data);
	}

	int Pop()
	{
		if (mTop != nullptr)
		{
			Node* node = mTop;
			int result = mTop->Data;
			mTop = mTop->Next;
			delete node;			
			return result;
		}
		else
		{
			cout << "stack is empty" << endl;
			return 0;
		}
	}

	int Peek()
	{
		if (IsEmpty())
		{
			cout << "stack is empty" << endl;
			return 0;
		}

		return mTop->Data;
	}

	bool IsEmpty()
	{
		return mTop == nullptr;
	}
};

