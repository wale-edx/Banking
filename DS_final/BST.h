#pragma once
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <queue>
#include <stack>
#include <fstream>
#include <stdlib.h>
//#include "operation.h"
//#include "CustomerAccount.h"
//#include "BST.h"

#define ull unsigned long long 
using namespace std;

class TreeNode {
private:
	string AccID;
	int index;
	TreeNode *right;
	TreeNode *left;
public:
	TreeNode(string ID = "", int i = 0, TreeNode*left = nullptr, TreeNode*right = nullptr)
	{
		AccID = ID; index = i;
		this->right = right; this->left = left;
	}

	string getID() { return AccID; }
	int getindex() { return index; }
	TreeNode *getright() { return right; }
	TreeNode *getleft() { return left; }
	void setID(string id) { AccID = id; }
	void setindex(int i) { index = i; }
	void setright(TreeNode*r) { right = r; }
	void setleft(TreeNode*l) { left = l; }
};

class Tree {

private:
	TreeNode*root;
public:
	Tree(TreeNode*root = nullptr) { this->root = root; }
	TreeNode*getroot() { return root; }
	bool Empty() { return root == nullptr; }
	int search(string id);
	bool insert(string id, int index);
	int remove(string id);
};
