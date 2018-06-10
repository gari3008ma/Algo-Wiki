#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
	return (a>b)?b:a;
}
int main()
{
	int arr[1000],i,n,j,k,brr[1000],diff,x,y,dis;
	cin>>n>>x>>y;
	for(i=0;i<n;i++)
	  cin>>arr[i];
	diff=0;
	dis=INT_MAX;
    for(i=0;i<n;i++)
    {
             if(x==arr[i])
            {
            	diff = diff + i;
            }
            else if(arr[i]==y)
            {
            	diff=i-diff;
            	dis=min(diff,dis);
            }
    }
    cout<<dis<<" \n";
	return 0;
}	