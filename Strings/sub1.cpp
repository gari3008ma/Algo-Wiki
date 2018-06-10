#include<bits/stdc++.h>
using namespace std;
int count(string str,string ptr)
{
           int i,j=0,len=str.length(),len1=ptr.length(),count;
           	for(i=0;i<len1;i++)
           	{
                      if(str[j]==ptr[i])
                      	j++;
           	}
           	return j;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
         string str,ptr;
         cin>>str>>ptr;
        
         cout<<count(str,ptr)<<"\n";
	}
	return 0;
}