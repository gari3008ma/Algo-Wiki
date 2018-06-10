#include<bits/stdc++.h>
using namespace std;
#define HASH_SIZE 128
void Print2DArray(int *A, int nr, int nc)
{
    for(int r = 0; r < nr; r++)
    {
        for(int c = 0; c < nc; c++)
            printf("%4d", *(A + r*nc + c));
 
        printf("\n");
    }
 
    printf("\n\n");
}
void *trans(int *a,int r,int c)
{
	int size= r*c-1;
	int t,next,cycle,i;
	bitset<HASH_SIZE> b;
	b.reset();
	b[0]=b[size]=1;
	i=1;
	while(i<size)
	{
			cycle=i;
			t=a[i];
			do
			{
				next=(i*r)%size;
				swap(a[next],t);
				b[i]=1;
				i=next;
			}while(i!=cycle);
			for(i=1;i<size && b[i];i++);
				
			cout<<endl;
	}
}
int main()
{
	int r = 5, c = 6;
    int size = r*c;
    int *A = new int[size];
 
    for(int i = 0; i < size; i++)
        A[i] = i+1;
 
    Print2DArray(A, r, c);
    trans(A, r, c);
    Print2DArray(A, c, r);
 
    delete[] A;
 
    return 0;
}