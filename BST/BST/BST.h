#pragma once
#include "Node.h"
class BST
{
private:
	void insertNode(Node*, int);
	void travel(Node*);
	Node* root;
	void findSuccessor(Node*, int);
	void findPredecessor(Node*, int);
	Node* searchNode(Node*, int);
	void deleteNode(Node*);
	Node* findMax(Node*);
	Node* findMin(Node*);
public:
	void ClearTree();
	Node* ReturnRoot();
	bool IsEmpty();
	void Travel();
	void Insert(int);
	void Delete(Node*);
	void Successor(int);
	void Predecessor(int);
	Node* Search(int);
	void Max();
	void Min();
};

