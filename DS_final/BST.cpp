#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#include <stdlib.h>
#include "BST.h"


int Tree::search(string id)
{
	if (Empty()) return -1;
	TreeNode*ptr = root;
	while (ptr != nullptr)
	{
		string temp = ptr->getID();
		if (temp == id)
			return ptr->getindex();
		else if (temp < id)
		{
			ptr = ptr->getright();
		}
		else
		{ 
			ptr = ptr->getleft(); 
		}
	}
	return -1;
}

bool Tree::insert(string id, int index)
{
	if (Tree::Empty())
	{
		root = new TreeNode(id, index);
		return true;
	}
	TreeNode *ptr = root;
	while (ptr != nullptr)
	{

label:		string temp = ptr->getID();
		if (temp == id) { return false; } 
		if (temp < id)
		{
			if (ptr->getleft() == nullptr)
			{
				TreeNode* newnode = new TreeNode(id, index);
				ptr->setleft(newnode);
				return true;
			}
			else
			{
				ptr = ptr->getleft();
				goto label;
			}

		}
		else
		{
			if (ptr->getright() == nullptr)
			{
				TreeNode* newnode = new TreeNode(id, index);
				ptr->setright(newnode);
				return true;
			}
			else
			{
				ptr = ptr->getright();
				goto label;
			}
		}
	}
}

int Tree::remove(string id)
{
	if (Tree::Empty()) { return -1; }
	TreeNode*ptr = root;
	TreeNode*parent = nullptr;
	char child;
	while (ptr != nullptr)
	{
		string temp = ptr->getID();
		if (temp == id) break;
		else if (temp < id)
		{
			parent = ptr;
			child = 'l';
			ptr = ptr->getleft();

		}
		else
		{
			parent = ptr;
			child = 'r';
			ptr = ptr->getright();

		}
	}
	if (ptr->getleft() == nullptr && ptr->getright() == nullptr) //leaf
	{
		if (parent != nullptr)
			if (child == 'l')
			{
				return ptr->getindex();
				parent->setleft(nullptr);

			}
			else
			{
				return ptr->getindex();
				parent->setright(nullptr);

			}
		else
			root = nullptr;

	}
	else if (ptr->getleft() == nullptr) //node has only one right child
	{
		if (parent != nullptr)
			if (child == 'l')
			{
				return ptr->getindex();
				parent->setleft(ptr->getright());
			}
			else
			{
				return ptr->getindex();
				parent->setright(ptr->getright());
			}
		else
		{
			return ptr->getindex();
			root = ptr->getright();
		}
	}
	else if (ptr->getright() == nullptr) //node has only one left child
	{
		if (parent != nullptr)
			if (child == 'l')
			{
				return ptr->getindex();
				parent->setleft(ptr->getleft());
			}
			else
			{
				return ptr->getindex();
				parent->setright(ptr->getleft());
			}
		else
		{
			return ptr->getindex();
			root = ptr->getleft();
		}
	}
	else //node has two children
	{
		TreeNode*node = new TreeNode(*ptr);
		TreeNode*leftchild = ptr->getleft();
		if (leftchild->getright() == nullptr)
		{
			ptr->setID(leftchild->getID());
			ptr->setindex(leftchild->getindex());
			ptr->setleft(leftchild->getleft());
			delete leftchild;
			return node->getindex();
		}
		TreeNode*maxleft = leftchild->getright();
		TreeNode*parent2 = leftchild;
		while (maxleft->getright() != nullptr)
		{
			parent2 = maxleft;
			maxleft = maxleft->getright();
		}
		ptr->setID(maxleft->getID());
		ptr->setindex(maxleft->getindex());
		if (maxleft->getleft() == nullptr) parent2->setright(nullptr);
		else parent2->setright(maxleft->getleft());
		delete maxleft;
		return node->getindex();
	}
}

