#include <iostream>
#include <fstream>
#include "Heap.h"
#include "BSTree.h"
#include <stdlib.h>//for the use of the exit(1) function
#include <string>
using namespace std;

Node* Huffman(Node C[], int n);
BSTree makeSearchTreeFromFile(ifstream& file);
Node* makeArrayFromSearchTree(BSTree T, int* size_of_arr);
void makeArrayFromSearchTreeAux(Node* arr,int * i,int size, BSTreeNode* r);
void FindCodeForNode(int index, string* out,char ch, Node* r, string temp);
void freeHTree(Node* r);//we need to free the tree
bool isLeaf(Node* r);

int main(int  argc, char* argv[])
{
	Node* arr;
	int size;
	float weight=0;

	ifstream f;//opining the text file for reading 
	f.open(argv[1]);
	if (!f.is_open())
	{
		cout << "file is not found"<<endl;
		exit(1);
	}
	
	BSTree T = makeSearchTreeFromFile(f);
	arr = makeArrayFromSearchTree(T,&size);

	char* chArray;
	float* numberOfApperance;
	numberOfApperance = new float[size];
	chArray = new char[size];
	for (int i = 0; i < size; i++)
	{
		chArray[i] = arr[i].getChar();
		numberOfApperance[i] = arr[i].Frequency();
	}

	
	Node* rootP;
	rootP=Huffman(arr, size);//creating huffman tree
	string* out;
	out = new string[size];
	f.close();//closing the file

	ofstream fileOut("out.txt");//putting the output on a new file
	if (!fileOut)
	{
		cout << "file is not found" << endl;
		exit(1);
	}

	fileOut << "Character encoding:" << endl;

	for (int i = 0; i < size; i++)
	{	
		string temp;
		FindCodeForNode(i,out,chArray[i], rootP,temp);
		fileOut << chArray[i] <<":"<<out[i]<<endl;
		weight += (numberOfApperance[i])*(float(out[i].size()));
	}
	fileOut << "\n";
	fileOut << "Encoded file weight: " << weight << " bits" << endl;

	
	
	//we must free the memory
	freeHTree(rootP);
	delete[]arr;
	delete[]chArray;
	delete[]numberOfApperance;
	delete[] out;


	return 0;

}



//build and return an optimal huffman tree
//for the n characters and frequencies in the array c.
//use a minimum priority queue Q to store subtrees.
//the priority is by the frequency of the subtree.
Node* Huffman(Node C[], int n)
{
	Heap Q(C,n);//initialize Q to contain forest of leaves,we will actuallize this using an heap with floyd's alghoritem.
	Node* node;
	for (int i = 1; i < n; i++)//.................
	{
		node = new Node;

		Node t1;
		t1 = (Q.DeleteMin());
		Node* temp1 = new Node;

		temp1->setChar(t1.getChar());
		temp1->SetFrequency(t1.Frequency());
		temp1->SetLeft(t1.Left());
		temp1->SetRight(t1.Right());
	
		node->SetLeft(temp1);//delete min will bring out the tree with the lowest priorty
	
		Node t2;
		t2= (Q.DeleteMin());
		Node* temp2 = new Node;


		temp2->setChar(t2.getChar());
		temp2->SetFrequency(t2.Frequency());
		temp2->SetLeft(t2.Left());
		temp2->SetRight(t2.Right());

		node->SetRight(temp2);
	
		float f = ((node->Left())->Frequency()) + ((node->Right())->Frequency());
		
		node->SetFrequency(f);
	
		Node temp;
		temp= *(node);

		Q.Insert(temp);
	}
	/*Node* rootP;
	Node r;
	r= Q.DeleteMin();
	rootP = &r;*/

	
//if any trouble(change to root p and r):
	    Node r;
		r = (Q.DeleteMin());
		Node* rootP = new Node;

	
		rootP->setChar(r.getChar());
		rootP->SetFrequency(r.Frequency());
		rootP->SetLeft(r.Left());
		rootP->SetRight(r.Right());
	
	

	//print(rootP);//debug
	
	return (rootP);//we will return the root 
}

BSTree makeSearchTreeFromFile(ifstream& file)
{
	string line;
	BSTree Tree;
	Node p;
	char ch=0;
	int counter = 0; 

	while (getline(file,line))
	{
		for (int i = 0; i < line.size(); i++)
		{
			BSTreeNode* temp = Tree.FIND(line[i]);
			if (temp == nullptr)
			{
				p.setChar(line[i]);
				p.SetFrequency(1);//first apperance
				Tree.Insert(p);
			}
			else
			{
				temp->value.SetFrequency((temp->value.Frequency() + 1));
			}

		}
		counter++;
		line.clear();
	}
	for (int i = 0; i < counter-1; i++)
	{
		char ch = '\n';
		
			BSTreeNode* temp = Tree.FIND(ch);
			if (temp == nullptr)
			{
				p.setChar(ch);
				p.SetFrequency(1);//first apperance
				Tree.Insert(p);
			}
			else
			{
				temp->value.SetFrequency((temp->value.Frequency() + 1));
			}

		
	}
	

		
	return Tree;
}

Node* makeArrayFromSearchTree(BSTree T,int* size_of_arr)
{
	Node* arr;
	int size = T.getNumOfNodes();
	BSTreeNode* r = T.getRoot();
	arr = new Node[size];
	int i = 0;
	makeArrayFromSearchTreeAux(arr,&i,size,r);
	*(size_of_arr) = size;
	return arr;
}

void makeArrayFromSearchTreeAux(Node* arr, int* i, int size, BSTreeNode* r)
{
	if ((*i)==size || r==nullptr)
	{
		return;
	}
	else
	{
		arr[(*i)] = r->getValue();
		(*i) = (*i) + 1;
		makeArrayFromSearchTreeAux(arr, i, size, r->left);
		makeArrayFromSearchTreeAux(arr, i, size, r->right);
	}
}



void FindCodeForNode(int index, string* out, char ch,Node* r, string temp)
{
	static int i = 0;
	if (r==nullptr)
	{
		return;
	}
	else
	{
		i++;
		if (r->getChar() == ch)
		{
			if (i==1)
			{
				out[index]= to_string(1);
			}
			else
			{
				out[index] = temp;
				return;
			}
			
		}
		else
		{
			if (i==1)
			{
				string temp1 = to_string(1);
				FindCodeForNode(index, out, ch, r->Right(), temp1);
				string temp2 = to_string(0);
				FindCodeForNode(index, out, ch, r->Left(), temp2);
			}
			else {
				string temp1 = temp + to_string(1);
				FindCodeForNode(index, out, ch, r->Right(), temp1);
				string temp2 = temp + to_string(0);
				FindCodeForNode(index, out, ch, r->Left(), temp2);
			}
		
		}
	}
	
}

void freeHTree(Node* r)
{

	if (r == nullptr) {
		return;
	}
	else
	{
		if (r->Left() != nullptr)
		{
			freeHTree(r->Left());
		}


		if (r->Right() != nullptr)
		{
			freeHTree(r->Right());
		}

		delete[]r;
	}
	

}

bool isLeaf(Node* r)
{
	if (((r->Left()) == nullptr) && ((r->Right()) == nullptr))
	{
		return true;
	}
	else
	{
		return false;
	}
}