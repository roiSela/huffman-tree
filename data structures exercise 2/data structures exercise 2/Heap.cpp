#include "Heap.h"

int Heap::Left(int node)
{
	return (2*node +1 );
}

int Heap::Right(int node)
{
	return (2*node +2);
}

int Heap::Parent(int node)
{
	return (node-1)/2;
}

void Heap::FixHeap(int node)
{
	int min;
	int left = Left(node); //to find the position of left child
	int right = Right(node); // to find the postion of right child

	//Find minimum among node , left and right
	if ( (left<heapSize) && ((data[left].Frequency()) < data[node].Frequency()))
	{
		min = left;
	}
	else
	{
		min = node;
	}

	if ((right<heapSize) && (data[right].Frequency()<data[min].Frequency()))
	{
		min = right;
	}
	//swap values if necessary, and continue fixing the heap towards the leaves.
	if (min!=node)
	{
		//swap(data[node],data[min]);
		Node temp;
	
		temp = data[node];
		data[node] = data[min];
		data[min] = temp;

		FixHeap(min);
	}


}

//Constructir:allocate memory for the heap and make the heap empty.
Heap::Heap(int max)
{
	data = new Node[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;//we alloacted the memory and we must delete it when the time is right
}

Heap::Heap(Node A[], int n)
{
	heapSize = maxSize = n;
	data = A;//assign array A to data pointer
	allocated = 0;//memory not alloacted by heap

	for (int i = (n/2)-1; i >= 0; i--)
	{
		FixHeap(i);
	}
	

	//debug
	/*for (int i = 0; i < heapSize; i++)
	{
		cout << data[i].getChar();
	}*/


}

//destructor:delete memory,only if allocated by heap
Heap::~Heap()
{
	if (allocated)
	{
		delete[] data;
		
	}
	data = nullptr;
}

Node Heap::Min()
{
	return data[0];
}

//delete minimum which is found in the root of heap , and fix heap
Node Heap::DeleteMin()
{
	if (heapSize<1)
	{
		cout << "error,heapSize<1";
		exit(1);
	}
	else
	{
		Node min;
		min=data[0];
		heapSize--;
		data[0] = data[heapSize];
		FixHeap(0);
		return min;
	}
}

void Heap::Insert(Node item)
{
	if (heapSize==maxSize)
	{
		cout << "error,heapSize==maxSize";
		exit(1);
	}
	else
	{
		int i = heapSize;
		heapSize++;
		while ((i>0)&&(data[Parent(i)].Frequency())>item.Frequency())
		{
			data[i] = data[Parent(i)];
			i = Parent(i);
		}

		data[i] = item;
	}

	
}
