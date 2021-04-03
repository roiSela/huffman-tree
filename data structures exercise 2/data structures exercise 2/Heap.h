#pragma once
#include "Node.h"

//typedef struct
//{
//	int priority;
//	int data;
//}Pair;

class Heap
{
private:
	Node* data; //Points to data array
	int maxSize; //max size of heap
	int heapSize;//current size of heap (logic size)
	int allocated;//1 if heap allocated memory
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
public:
	Heap(int max);//allocate memory
	Heap(Node A[],int n); // turn A[] into heap
	~Heap();
	Node Min();
	Node DeleteMin();
	void Insert(Node item);

};

