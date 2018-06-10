#include<bits/stdc++.h>

using namespace std;
int main()
{
	int t,row,col,i,j,arr[100][100],count;
			cin>>row>>col;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
					cin>>arr[i][j];
			}
			count=0;
			for(i=0;i<row;i++)
			{
				for(j=0;j<col;j++)
				{
					if(arr[i][j]<0)//Count elements which are negative
						count++;
				}
			}
			cout<<count;
	return 0;
}