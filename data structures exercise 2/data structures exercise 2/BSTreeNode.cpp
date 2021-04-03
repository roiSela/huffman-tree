#include "BSTreeNode.h"

BSTreeNode::BSTreeNode()
{
	left = nullptr;
	right = nullptr;
}

BSTreeNode::BSTreeNode(Node item, BSTreeNode* left, BSTreeNode* right)
{
	value = item;
	this->left = left;
	this->right=right;
}

BSTreeNode::~BSTreeNode()
{
}
