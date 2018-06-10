#include<bits/stdc++.h>
using namespace std;
int main()
{
	
    unsigned int i,arr[100][100],row,col,j,m,n;
	cin>>row>>col;
	m=col;
	n=row;
	
    unsigned int *des=(unsigned int *)malloc(sizeof( unsigned int)*m*n);
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cin>>arr[i][j];
			}
		}
		
    unsigned int *source =(unsigned int *)arr;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cout<<(*(source+col*i+j))<<" ";
			}
			cout<<"\n";
		}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
				*(des+row*j+(row-i-1))=arr[i][j];
		}
	}
	for(i=0;i<col;i++)
		{
			for(j=0;j<row;j++)
			{
				cout<<*(des+row*i+j)<<" ";
			}
			cout<<"\n";
		}
		free(des);
	return 0;
}