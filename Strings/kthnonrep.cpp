#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cin>>k;
	    int length,count[300],index[300];
	    length = str.length();
	    for(i=0;i<300;i++)
	    {
	         count[i]=0;
	         index[i]=length;
	    }
	    for(i=0;i<length;i++)
	    {
	       count[str[i]]++;
	       if(count[str[i]]==1)
	          index[str[i]]=i;
	       if(count[str[i]]==2)
	          index[str[i]]=length;   
	    }
	    sort(index,index+300);
	    int res=index[k-1]==length?-1:index[k-1];
	    if(res== -1)
	    {
	            cout<<"Don't Exist\n";
	    } 
	    else
	        cout<<str[res]<<"\n";
	}
}