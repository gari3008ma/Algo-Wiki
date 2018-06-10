#include<bits/stdc++.h>

using namespace std;
int min(int x,int y)
{
    return (x>y)?y:x;
}
int getmid(int a,int b)
{
    int m=(b+a)/2;
    return m;
}
int constructutil(int arr[],int ss,int se,int st[],int ind)
{
    if(ss==se)
    {
        st[ind]=arr[ind];
        cout<<arr[ind]<<" ";
        return arr[ind];
    }
    int mid=getmid(ss,se);
    st[ind]=min(constructutil(arr,ss,mid,st,2*ind+1),constructutil(arr,mid+1,se,st,2*ind+2));
    cout<<st[ind]<<" ";
             return st[ind];
}
int *constructST(int arr[],int n)
{
         int h = (int)(ceil(log2(n)));
         int maxsize=2*(int)pow(2,h)-1;
         cout<<maxsize<<"\n";
         int *st =new int[maxsize];
         constructutil(arr,0,n-1,st,0);
         for(int i=0;i<maxsize;i++)
         	cout<<st[i]<<" ";
         cout<<"\n";
         return st;
}
/* The functions returns the
 min element in the range
 from a and b */
int rmqutil(int st[],int ss,int se,int a,int b,int ind)
{
    if(a<=ss && b>=se)
       return st[ind];
       
    if(se<a || ss>b)
       return INT_MAX;
    
    int mid=getmid(ss,se);
    cout<<mid<<" ";
     return min(rmqutil(st,ss,mid,a,b,2*ind+1),rmqutil(st,mid+1,se,a,b,2*ind+2));  
}
int RMQ(int st[] , int n, int a, int b)
{
      if(a<0 || b>=n|| a>b)
        return -1;
        int r=rmqutil(st,0,n-1,a,b,0);
        if(r==INT_MAX)
        return -1;
        return r;
}

int main()
{
	int t,n,i,arr[10000],a,b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		int *root = constructST(arr,n);
		cin>>a>>b;
		cout<<RMQ(root,n,a,b)<<"\n";

	}
	return 0;
}