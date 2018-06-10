#include<bits/stdc++.h>
using namespace std;
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}
  
int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;
  
    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}
  

void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}
  
int main()
{
	int arr[1000],i,n,m,brr[1000],j;
	cin>>n;
	for(i=0;i<n;i++)
	  cin>>arr[i];
	cin>>m;
	for(i=0;i<m;i++)
	  cin>>brr[i];
	quickSort(arr,0,n-1);
	quickSort(brr,0,m-1);
	for(i=0;i<n;i++)
	  cout<<arr[i]<<" ";
	i=0;j=0;
	while(i<n&& j<m)
	{
		if(arr[i]<brr[j])
			i++;
		else if(arr[i]==brr[j])
		{
			i++;
			j++;
		}
		else if(arr[i]>brr[j])
		{
			   cout<<" not subarray\n";
				break;
		}
	}
	if(j<m)
		cout<<" not a subarray\n";
	else
		cout<<"ffound subarry\n";
	return 0;
}