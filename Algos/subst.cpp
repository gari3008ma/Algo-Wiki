#include<bits/stdc++.h>
using namespace std;
void print(vector<int> arr)
{
	int size=arr.size(),i,j,k;
    for(i=0;i<size;i++)
    	cout<<arr[i]<<" ";
    cout<<"\n";
}
void recprint(bool val[100][100],int* n,int k,vector<int> arr,int i,int j,int ary[])
{
	if(i<0 )
		return ;
	if(k==0)
	{
			print(arr);
		(*n)++;
		return ;
			//arr.empty();
	}
	if(val[i][j] && ary[i-1]<=j)
	{
		arr.push_back(ary[i-1]);
		recprint(val,n,k-ary[i-1],arr,i-1,j-ary[i-1],ary);
		arr.pop_back();
	}
	if(val[i][j])
	{
		recprint(val,n,k,arr,i-1,j,ary);
		arr.pop_back();
	}
	//arr.empty();
}
int main()
{
	       int t,n,k,arr[1000],i,j;
	       cin>>t;
	       while(t--)
	       {
	       	      cin>>n>>k;
	       	      for(i=0;i<n;i++)
	       	      {
	       	      	cin>>arr[i];
	       	      }
	       	      bool val[100][100];
	       	      memset(val,false,sizeof(val));
	       	      for(i=0;i<=n;i++)
	       	      {
	       	      	for(j=0;j<=k;j++)
	       	      	{
	       	      		if(i==0 && j==0)
	       	      			val[i][j]=true;
	       	      		else if(i==0)
	       	      			val[i][j]=false;
	       	      		else if(j==0)
	       	      			val[i][j]=true;
	       	      		else if(arr[i-1]<=j)
	       	      		{
	       	      				val[i][j] = val[i-1][j-arr[i-1]] || val[i-1][j];

	       	      		}
	       	      		else
	       	      			val[i][j]=val[i-1][j];
	       	      	}
	       	      }
	       	      vector<int> vec;
	       	      int count=0;
	       	      recprint(val,&count,k,vec,n,k,arr);
	       	      /*for(i=0;i<=n;i++)
	       	      {
	       	      	for(j=0;j<=k;j++)
	       	      		cout<<val[i][j]<<" ";
	       	      	cout<<"\n";
	       	      }
	       	      cout<<val[n][k]<<"\n";
	       	      */
	       	      cout<<count<<"\n";
	       }
}