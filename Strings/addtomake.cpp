#include<bits/stdc++.h>
using namespace std;
bool ispal(string str)
{
	 string ptr=str;
	 reverse(ptr.bein(),ptr.end());
	 if(ptr==str)
	 	  return true;
	 else
	     return false;	
}
int main()
{
	int t,i,n,j;
	cin>>t;
	while(t--)
	{
		string str,ptr;
		cin>>str;
		n=str.length();
		ptr=str;
		reverse(ptr.begin(),ptr.end());
		for(i=n-1;i>=0;i--)
		{
				ptr = ptr + str[i];
				if(ispal(ptr))
				{
					cout<<(n-i)<<"\n";
					break;
				}
		}

	}
}