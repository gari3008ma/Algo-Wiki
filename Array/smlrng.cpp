#include<bits/stdc++.h>
using namespace std;
#define N 100
struct MinHeapNode
{
    int element; // The element to be stored
    int i; // index of the list from which the element is taken
    int j; // index of the next element to be picked from list
};
void swap(MinHeapNode *x, MinHeapNode *y);
 
// A class for Min Heap
class MinHeap
{
    MinHeapNode *harr; // pointer to array of elements in heap
    int heap_size; // size of min heap
public:
    // Constructor: creates a min heap of given size
    MinHeap(MinHeapNode a[], int size);
 
    // to heapify a subtree with root at given index
    void MinHeapify(int );
 
    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }
 
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }
 
    // to get the root
    MinHeapNode getMin() { return harr[0]; }
 
    // to replace root with new node x and heapify() new root
    void replaceMin(MinHeapNode x) { harr[0] = x; MinHeapify(0); }
};
 
// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a; // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size &&
        harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size &&
        harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
 int callmin(int arr[][N],int n,int k)
 {
 	int i,j;
 	int range = INT_MAX;
    int min = INT_MAX, max = INT_MIN;
    int start, end;
 	MinHeapNode  *b=new MinHeapNode[k];
     for(int i=0;i<k;i++)
     {
     	b[i].element=arr[i][0];
     	b[i].i=i;
     	b[i].j=1;
     	if(max < b[i].element)
     		max=b[i].element;
     }
     MinHeap hp(b, k);
     while(1)
     {
     		MinHeapNode root = hp.getMin();
 
        // update min
        min = hp.getMin().element;
 
        // update range
        if (range > max - min + 1)
        {
            range = max - min + 1;
            start = min;
            end = max;
        }
 
        // Find the next element that will replace current
        // root of heap. The next element belongs to same
        // list as the current root.
        if (root.j < n)
        {
            root.element =arr[root.i][root.j];
            root.j += 1;
 
            // update max element
            if (root.element > max)
                max = root.element;
        }
 
        // break if we have reached end of any list
        else break;
 
        // Replace root with next element of list
        hp.replaceMin(root);
    }
 
    cout << "The smallest range is " << "["
         << start << " " << end << "]" << endl;;
     }
int main()
{
	    int k,arr[100][100],i,j,n;
	    cin>>k>>n;
	    for(i=0;i<k;i++)
		{
				for(j=0;j<n;j++)
				{
					cin>>arr[i][j];
				}
		}
		callmin(arr,n,k);
        
}