#pragma once
#include "Node.h"
class BST
{
private:
	void insertNode(Node*, int);
	void travel(Node*);
	Node* root;
	void findSuccessor(Node*,int);
	void findPredecessor(Node*,int);
	Node* searchNode(Node*, int);
	void deleteNode(Node*,int);
	void findMax(Node*);
	void findMin(Node*);
public:
	void ReturnRoot();
	bool IsEmpty();
	void Travel();
	void Insert(int);
	void Delete(int);
	void Successor(int);
	void Predecessor(int);
	void Search(int);
	void Max();
	void Min();
};

