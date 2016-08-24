#include "BST.h"
#include "Node.h"
#include <iostream>
#include "color.h"

//public method
void BST::HeightofTree()
{
	if (IsEmpty())
		std::cout << "No tree init\n";
	else
	{
		std::cout <<"The height of tree is "<< heightofTree(root)<<std::endl;
	}
}
BST::BST()
{
	NIL = new Node();
	NIL->setColor(color::BLACK);
}
void BST::ClearTree()
{
	root = nullptr;
}
void BST::Insert(int value)
{
	if (root)
		insertNode(root, value);
	else
	{
		root = new Node(value);
		root->parent = NIL;
		root->left = NIL;
		root->right = NIL;
		root->setColor(color::BLACK);
	}
}
void BST::Travel()
{
	if (IsEmpty())
		std::cout << "No tree init";
	else
	{
		std::cout << "Tree: \n";
		travel(root);
	}
	std::cout << std::endl;
}
Node* BST::Search(int value)
{
	if (root)
		return searchNode(root, value);
	else
	{
		std::cout << "Tree has not been initialized yet\n";
		return root;
	}
}
bool BST::IsEmpty()
{
	return (!root);
}
void BST::Delete(Node* ref)
{
	deleteNode(ref);
}
void BST::Successor(int value)
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findSuccessor(root, value);
}
void BST::Predecessor(int value)
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findPredecessor(root, value);
}
void BST::Max()
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		Node* result = findMax(root);
}
void BST::Min()
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		Node* result = findMin(root);
}
Node* BST::ReturnRoot()
{
	return root;
}

//private method
int BST::heightofTree(Node *current)
{
	if (current == NIL)
		return 0;
	else
	{
		int subtreeRight = heightofTree(current->right);
		int subtreeLeft = heightofTree(current->left);
		if(subtreeLeft > subtreeRight)
			return (1 + subtreeLeft);
		else
			return (1 + subtreeRight);
	}
}
void BST::travel(Node*root) //travel inorder -> return sorted order
{
	if (root == NIL)
		return;
	else
	{
		travel(root->left);
		if(root->getColor()==color::RED)
			std::cout << root->key << " Color: RED" <<std::endl;
		else
			std::cout << root->key << " Color: BLACK" << std::endl;
		travel(root->right);
	}
}
void BST::insertNode(Node* root, int value)
{
	Node *newNode = new Node(value);
	newNode->setColor(color::RED);
	newNode->right = NIL;
	newNode->left = NIL;
	if (value >= root->key)
	{
		if (root->right == NIL)
		{
			root->right = newNode;
			newNode->parent = root;
			insertFixUp(newNode);
		}
		else
			insertNode(root->right, value);
	}
	else
	{
		if (root->left == NIL)
		{
			root->left = newNode;
			newNode->parent = root;
			insertFixUp(newNode);
		}
		else
			insertNode(root->left, value);
	}
}
void BST::insertFixUp(Node* currentNode)
{
	while (currentNode->parent->getColor() == color::RED)
	{
		if (currentNode->parent == currentNode->parent->parent->left)
		{
			Node *uncle = currentNode->parent->parent->right;
			//Case 1: uncle is red
			if (uncle->getColor() == color::RED)
			{
				uncle->setColor(color::BLACK);
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				currentNode = currentNode->parent->parent;
			}
			else
			{
				//Case 2 : uncle is black and need-to-fix node is right child
				if (currentNode == currentNode->parent->right)
				{
					currentNode = currentNode->parent;
					leftRotate(currentNode);
				}
				//Case 3 : uncle is black and need-to-fix node is left child
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				rightRotate(currentNode->parent->parent);
			}
		}
		else
		{
			Node *uncle = currentNode->parent->parent->left;
			//Case 1: uncle is red
			if (uncle->getColor() == color::RED)
			{
				uncle->setColor(color::BLACK);
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				currentNode = currentNode->parent->parent;
			}
			else
			{
				//Case 2 : uncle is black and need-to-fix node is left child
				if (currentNode == currentNode->parent->left)
				{
					currentNode = currentNode->parent;
					rightRotate(currentNode);
				}
				//Case 3 : uncle is black and need-to-fix node is right child
				currentNode->parent->setColor(color::BLACK);
				currentNode->parent->parent->setColor(color::RED);
				leftRotate(currentNode->parent->parent);
			}
		}
		root->setColor(color::BLACK);
	}
}
void BST::findSuccessor(Node* root, int value)
{
	Node*current = searchNode(root, value);
	if (current == NIL)
		return;
	if (value == (findMax(root)->key))
	{
		std::cout << "This is the largest element" << std::endl;
		return;
	}
	else
	{
		if (current->right == NIL)
		{
			Node *temp = current->parent;
			if (temp == NIL)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NIL && current != temp->left)
				{
					current = temp;
					temp = temp->parent;
				}
				std::cout << "Successor: " << temp->key << std::endl;
			}
		}
		else
		{
			Node* result = findMin(current->right);
			std::cout << "Successor: " << result->key << std::endl;
		}
	}
}
void BST::findPredecessor(Node* root, int value)
{
	Node*current = searchNode(root, value);
	if (current == NIL)
		return;
	if (value == (findMin(root)->key))
	{
		std::cout << "This is the smallest element" << std::endl;
		return;
	}
	else
	{
		if (current->left == NIL)
		{
			Node *temp = current->parent;
			if (!temp)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NIL && current != temp->right)
				{
					current = temp;
					temp = temp->parent;
				}
				std::cout << "Predecessor: " << temp->key << std::endl;
			}
		}
		else
		{
			Node* result = findMax(current->left);
			std::cout << "Predecessor: " << result->key << std::endl;
		}
	}
}
Node* BST::searchNode(Node* root, int value)
{
	if (root == NIL)
	{
		std::cout << "No found matched\n";
		return root;
	}
	else
	{
		if (value == root->key)
		{
			std::cout << "Found it\n";
			return root;
		}
		else
		{
			if (value > root->key)
				searchNode(root->right, value);
			else
				searchNode(root->left, value);
		}
	}
}
void BST::deleteNode(Node* current)
{
	Node *parentCurrent = current->parent;
	if ((!current->right) && (!current->left)) //deleted node is child
	{
		if (!parentCurrent) //the tree has 1 element
			ClearTree();
		else
		{
			if (current == parentCurrent->left)
				parentCurrent->left = nullptr;
			else
				parentCurrent->right = nullptr;
		}
	}
	else
	{
		if ((!current->left) || (!current->right)) //deleted node has 1 child
		{
			Node *child = current->right;
			if (!child)
				child = current->left;
			if (parentCurrent) //check whether it is root or not
			{
				if (current == parentCurrent->left)
				{
					parentCurrent->left = child;
					child->parent = parentCurrent;
					return;
				}
				else
				{
					parentCurrent->right = child;
					child->parent = parentCurrent;
					return;
				}
			}
			else
			{
				int temp = child->key;
				child->key = root->key;
				root->key = temp;
				deleteNode(child);
			}

		}
		else //deleted node has 2 children
		{
			Node*suc = findMin(current->right);
			int temp = suc->key;
			suc->key = current->key;
			current->key = temp;
			deleteNode(suc);
		}
	}
}
Node* BST::findMax(Node* root)
{
	if (root->right != NIL)
		findMax(root->right);
	else
		return root;
}
Node* BST::findMin(Node* root)
{
	if (root->left != NIL)
		findMin(root->left);
	else
		return root;
}
void BST::leftRotate(Node* sample)
{
	Node *rightChild = sample->right;
	sample->right = rightChild->left;
	rightChild->left->parent = sample;
	if (sample->parent->left == sample)
		sample->parent->left = rightChild;
	else
		sample->parent->right = rightChild;
	rightChild->parent = sample->parent;
	sample->parent = rightChild;
	rightChild->left = sample;
}
void BST::rightRotate(Node* sample)
{
	Node *leftChild = sample->left;
	sample->left = leftChild->right;
	leftChild->right->parent = sample;
	if (sample->parent->right == sample)
		sample->parent->right = leftChild;
	else
		sample->parent->left = leftChild;
	leftChild->parent = sample->parent;
	sample->parent = leftChild;
	leftChild->right = sample;
}