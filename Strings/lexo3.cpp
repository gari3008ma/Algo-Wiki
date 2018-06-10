#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
	long long int i,arr[10000];
	arr[0]=1;
	arr[1]=1;
	for(i=2;i<=n;i++)
		arr[i]=arr[i-1]*i;
	return arr[n];
}
int right(string str,char a)
{
	int i,c=0,j;
	for(i=0;i<str.length();i++)
	{
		if(str[i]==a)
			{
				for(j=i+1;j<str.length();j++)
				{
					if(str[j]<a)
						c++;
				}
				return c;
			}
	}
   return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	     string str;
	     cin>>str;
	     int rank=1,n,i;
	     	n=str.length();
	     for(i=0;i<str.length();i++)
	        	{
	        		rank=rank+right(str,str[i])*fact(n-i-1);
	        		cout<<str[i]<<" "<<rank<<"\n";
	        	}
	     cout<<rank<<"\n";   	
	}
}