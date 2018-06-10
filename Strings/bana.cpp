#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,count1=0,count=0,x=0,y=0;
	cin>>a>>b;
	while(a)
	{
	     if(a&1)
	     {
	        count1++;
	     }
	     else
	     count++;
	     a>>=2;
	}
	while(b)
	{
	     if(b&1)
	     {
	        x++;
	     }
	     else
	     y++;
	     b>>=2;
	}
	if(x==count1 && y==count)
	cout<<"yes\n";
	else
	cout<<"No\n";
  cout<<x<<" "<<count1<<"\n";
  cout<<y<<" "<<count<<"\n";

}