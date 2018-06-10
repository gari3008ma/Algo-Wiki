#include<bits/stdc++.h>
using namespace std;
struct pa
{
	int a;
	int b;
};
int main()
{
      struct pa arr[100];
      int i,t,curr,prev,start,end,n;
      cin>>t;
      while(t--)
      {
      	cin>>n;
      	for(i=0;i<n;i++)
      	{
      		cin>>arr[i].a>>arr[i].b;
      	}
      		start = 0;
      		end = 1;
      		curr = arr[0].a - arr[0].b;
      		while(start!=end || curr <0)
      		{
      			while(curr<0 && start!=end)
      			{
      					curr=curr-arr[start].a - arr[start].b;
      					start = (start+1)%n;
      					if(start==0)
      						 break;
      			}
      			curr= curr+arr[end].a - arr[end].b;
      			end = (end+1)%n;
      		}
      		cout<<start<<"\n";

      }
}