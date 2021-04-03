#include "BSTree.h"

BSTree::~BSTree()
{
}

//return pointer to node containing key , return nullptr if item not in tree
BSTreeNode* BSTree::FIND(char key)
{
	BSTreeNode* temp = root;
	while (temp!=nullptr)
	{
		if (key==(temp->getValue()).getChar())
		{
			return temp;
		}
		else
		{
			if (key < (temp->getValue()).getChar())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}		
	}

	return nullptr;
}

void BSTree::Insert(Node item)
{
	if (FIND(item.getChar())!=nullptr)//check if key exist
	{
		cout << "the key already exist, we cant allow two pairs with the same key value" << endl;
	}
	else
	{
		numOfNodes++;
		BSTreeNode* temp=root; //current node in tree
		BSTreeNode* parent=nullptr;//parent of temp
		BSTreeNode* newNode;//new allocated node

		while (temp!=nullptr)//find parent of new node
		{
			parent = temp;
			if (item.getChar() < (temp->getValue()).getChar())
			{
				temp = temp->getLeft();
			}
			else
			{
				temp = temp->getRight();
			}
		}

		newNode = new BSTreeNode(item,nullptr,nullptr);//memory for new node
		if (parent==nullptr)//insert new node as root
		{
			root = newNode;
		}
		else
		{
			if ((item.getChar()) < (parent->getValue()).getChar())
			{
				parent->setLeft(newNode);//insert as left child
			}
			else
			{
				parent->setRight(newNode); // insert as right child
			}
		}

	}
}

void BSTree::Delete(char key)
{
}
