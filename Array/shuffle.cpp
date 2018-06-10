#include<bits/stdc++.h>
using namespace std;
void swap(int * a,int *b)
{
	int tmp;
	tmp=(*a);
	(*a)=(*b);
	(*b)= (tmp);
}
int main()
{
	int i,n,j,arr[1000];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	 srand ( time(NULL) );
	 // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
	for(j=(n-1);j>0;j--)
	{
		i = rand()%(j+1);
		swap(&arr[i],&arr[j]);
	}
   for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}