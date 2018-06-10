#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define reps(i,a,n) for(int i=a;i<n;i++)

int maxi(int a,int b)
{
    return a>b? a:b;
}
int main()
 {
	int t,i,n,a[10000],incl,excl,exclnew;
	cin>>t;
	while(t--)
	{
	       cin>>n;
	       for(i=0;i<n;i++)
	       {
	         cin>>a[i];
	       }
	       incl=a[0];
	       excl=0;
	       exclnew=0;
	       for(i=1;i<n;i++)
	       {
	              exclnew=maxi(incl,excl);
	              incl=excl+a[i];
	              excl=exclnew;
	       }
	       cout<<maxi(incl,excl)<<" \n";
	}
	return 0;
}