#pragma once
#include <iostream>
using namespace std;
//A Node class for huffman Tree
class Node
{
private:
	char ch; //only relavant in leaves
	float frequency;
	Node* left;
	Node *right;
public:
	Node();
	Node(char ch,float f);
	//~Node();

	Node* Left();
	Node* Right();
	void SetLeft(Node* node);
	void SetRight(Node* node);
	float Frequency();
	void SetFrequency(float f);
	void setChar(char ch) { this->ch= ch; }
	char getChar() { return ch; }
	//Node& operator=(Node& other);
	Node& operator=(const Node& other)
	{
		this->ch = other.ch;
		this->frequency = other.frequency;
		this->left = other.left;
		this->right = other.right;

		return (*this);
	}

	
};

