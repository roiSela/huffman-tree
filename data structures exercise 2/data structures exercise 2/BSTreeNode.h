#pragma once
#include "Node.h"
class BSTreeNode
{
public:
	Node value;
	BSTreeNode* left, * right;

	BSTreeNode();
	BSTreeNode(Node item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();
	Node getValue() { return value; }
	BSTreeNode* getLeft() { return left; }
	BSTreeNode* getRight() { return right; }

	void setLeft(BSTreeNode* l) { left = l; }
    void setRight(BSTreeNode* r) { right = r; }

}; 

