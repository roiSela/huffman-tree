#pragma once
#include "BSTreeNode.h"
class BSTree
{
private:
	BSTreeNode* root;
	int numOfNodes;
public:
	BSTree():root(nullptr),numOfNodes(0){}
	~BSTree();
	BSTreeNode* FIND(char key);
	void Insert(Node item);
	void Delete(char key);
	int getNumOfNodes() { return numOfNodes; }
	BSTreeNode* getRoot() { return root; }
};

