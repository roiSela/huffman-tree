#include "Node.h"
//char ch; //only relavant in leaves
//float frequency;
//Node* left, * right;

Node::Node()
{
	ch = 0;
	frequency = 0;
	left = nullptr;
	right = nullptr;
}



Node::Node(char ch, float f)
{
	this->ch = ch;
	frequency = f;
	left = nullptr;
	right = nullptr;
}

//Node::~Node()
//{
//
//}

Node* Node::Left()
{
	return left;
}

Node* Node::Right()
{
	return right;
}

void Node::SetLeft(Node* node)
{
	left = node;
}

void Node::SetRight(Node* node)
{
	right = node;
}

float Node::Frequency()
{
	return frequency;
}

void Node::SetFrequency(float f)
{
	frequency = f;
}
