#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int Data = 0;
	Node* Right = nullptr;
	Node* Left = nullptr;
public:
	Node(int data) : Data(data) {}
};

class BinarySearchTree
{
private:
	Node* Root = nullptr;

public:
	BinarySearchTree() {}
	~BinarySearchTree() { Clear(); }

	void Insert(int data)
	{
		InsertInternalResursive(Root, data);
	}

	void Delete(int data)
	{
		Root = DeleteInternalResursive(Root, data);
	}

	void InOrderTraversal()
	{
		InOrderTraversalResursive(Root);
	}

	void Clear()
	{
		while (Root != nullptr)
			Root = DeleteInternalResursive(Root, Root->Data);
	}

private:
	void InsertInternalResursive(Node*& node, int data)
	{
		if (node == nullptr)
		{
			node = new Node(data);
			return;
		}

		if (data < node->Data)
		{
			InsertInternalResursive(node->Left, data);
		}
		else if (data > node->Data)
		{
			InsertInternalResursive(node->Right, data);
		}
		else
		{
			cout << "중복된 원소 허용하지 않음" << endl;
			return;
		}
	}

	Node* DeleteInternalResursive(Node*& node, int data)
	{
		if (node == nullptr)
			return nullptr;
		if (data < node->Data)
			node->Left = DeleteInternalResursive(node->Left, data);
		else if (data > node->Data)
			node->Right = DeleteInternalResursive(node->Right, data);
		else
		{
			if (node->Right == nullptr && node->Left == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->Left == nullptr)
			{
				Node* temp = node->Right;
				delete node;
				return temp;
			}
			else if (node->Right == nullptr)
			{
				Node* temp = node->Left;
				delete node;
				return temp;
			}

			node->Data = FindMinResursive(node->Right);
			node->Right = DeleteInternalResursive(node->Right, node->Data);
		}

		return node;
	}

	int FindMinResursive(Node* node)
	{
		if (node->Left == nullptr)
			return node->Data;
		else
			FindMinResursive(node->Left);		
	}

	void InOrderTraversalResursive(Node* node)
	{
		if (node != nullptr)
		{			
			InOrderTraversalResursive(node->Left);
			cout << node->Data << ", ";
			InOrderTraversalResursive(node->Right);			
		}
		else
		{
			return;
		}
	}
};

