#include "BST.h"
#include "Node.h"
#include <iostream>
void BST::Insert(int value)
{
	if (root)
		this->insertNode(root, value);
	else
		root = new Node(value);
}
void BST::Travel()
{
	if (this->IsEmpty())
		std::cout << "No tree init";
	else
	{
		std::cout << "Tree: \n";
		this->travel(root);
	}
}
void BST::Search(int value)
{
	if (root)
		Node* result = this->searchNode(root, value);
	else
		std::cout << "No found matched\n";
}
bool BST::IsEmpty()
{
	return (!root);
}
void BST::Delete(int value)
{
	if (this->IsEmpty())
		std::cout << "No element for deletion\n";
	else
		this->deleteNode(root,value);
}
void BST::Successor(int value)
{
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		this->findSuccessor(root, value);
}
void BST::Predecessor(int value)
{
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		this->findPredecessor(root, value);
}
void BST::Max()
{
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		this->findMax(root);
}
void BST::Min()
{
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		this->findMin(root);
}
void BST::ReturnRoot()
{
	std::cout << root->key;
}
void BST::travel(Node*root) //travel inorder -> return sorted order
{
	if (!root)
		return;
	else
	{
		travel(root->left);
		std::cout << root->key << " ";
		travel(root->right);
	}
}
void BST::insertNode(Node* root, int value)
{
	if (value >= root->key)
	{
		if (!root->right)
		{
			root->right = new Node(value);
			root->right->parent = root;
		}
		else
			insertNode(root->right, value);
	}
	else
	{
		if (!root->left)
		{
			root->left = new Node(value);
			root->left->parent = root;
		}
		else
			insertNode(root->left, value);
	}

}
void BST::findSuccessor(Node* root, int value)
{
	Node*current = this->searchNode(root, value);
	if (!current)
		std::cout << "No found matched";
	else
	{
		if (!current->right)
			std::cout << "Successor: " + current->parent->key<<std::endl;
		Node temp = *(current->right);
		while (temp.left)
			temp = *(temp.left);
		std::cout << "Successor: " + temp.key << std::endl;
	}
}
void BST::findPredecessor(Node*, int)
{
}
Node* BST::searchNode(Node* root, int value)
{
	if (!root)
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
				this->searchNode(root->right, value);
			else
				this->searchNode(root->left, value);
		}
	}
}
void BST::deleteNode(Node* root, int value)
{

}
void BST::findMax(Node* root)
{
	if (root->right)
		findMax(root->right);
	else
	{
		std::cout << "Max is: " << root->key << std::endl;
		return;
	}
}
void BST::findMin(Node* root)
{
	if (root->left)
		findMin(root->left);
	else
	{
		std::cout << "Min is: " << root->key << std::endl;
		return;
	}
}