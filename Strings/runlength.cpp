#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j=0,len,count;
	string a;
	cin>>a;
	len=a.size();
	char *des=(char *)malloc(sizeof(char)*(2*len+1));
	for(i=0;i<len;i++)
	{
		des[j]=a[i];
		j++;
		count=1;
		while(i+1<len &&(a[i]==a[i+1]))
			{
				count++;
				i++;
		    }		
		des[j]=count+'0';
		j++;
	}
	for(i=0;i<j;i++)
		cout<<des[i];
}