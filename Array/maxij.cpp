#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
	return a>b?b:a;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int arr[1000],i,j,lmin[1000],rmax[1000],diff,mini,n;
	cin>>n;
	for(i=0;i<n;i++)
	  cin>>arr[i];
     lmin[0] = arr[0];
  for(i=1;i<n;i++)
  {
  			lmin[i]=min(lmin[i-1],arr[i]);
  }
  rmax[n-1] = arr[n-1];
  for(i=(n-2);i>=0;i--)
  {
  	rmax[i]=max(rmax[i+1],arr[i]);
  }
  i=0;
  j=0;
  diff=-1;
  while(i<n && j<n)
  {
  	if(lmin[i]<rmax[j])
  	{
  			diff=max(diff,(j-i));
  			j++;
  	}
  	else
  	{
  		i++;
  	}
  }
  cout<<diff<<"\n";
    return 0;
}