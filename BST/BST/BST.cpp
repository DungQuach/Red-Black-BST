#include "BST.h"
#include "Node.h"
#include <iostream>
#include "color.h"

//public method
BST::BST()
{
	NIL = nullptr;
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
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findSuccessor(root, value);
}
void BST::Predecessor(int value)
{
	if (this->IsEmpty())
		std::cout << "Tree has not been initialized";
	else
		findPredecessor(root, value);
}
void BST::Max()
{
	if (IsEmpty())
		std::cout << "Tree has not been initialized\n";
	else
		Node* a = findMax(root);
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
			root->right->right = NIL;
			root->right->left = NIL;
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
			root->left->right = NIL;
			root->left->left = NIL;
		}
		else
			insertNode(root->left, value);
	}

}
void BST::findSuccessor(Node* root, int value)
{
	Node*current = searchNode(root, value);
	if (!current)
		return;
	if (value == (findMax(root)->key))
	{
		std::cout << "This is the largest element" << std::endl;
		return;
	}
	else
	{
		if (!current->right)
		{
			Node *temp = current->parent;
			if (!temp)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NULL && current != temp->left)
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
	if (!current)
		return;
	if (value == (findMin(root)->key))
	{
		std::cout << "This is the smallest element" << std::endl;
		return;
	}
	else
	{
		if (!current->left)
		{
			Node *temp = current->parent;
			if (!temp)
				std::cout << "That is the only element" << std::endl;
			else
			{
				while (temp->parent != NULL && current != temp->right)
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
	if (root->right)
		findMax(root->right);
	else
	{
		return root;
	}
}
Node* BST::findMin(Node* root)
{
	if (root->left)
		findMin(root->left);
	else
	{
		return root;
	}
}