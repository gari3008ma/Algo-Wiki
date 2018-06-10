#include<bits/stdc++.h>
using namespace std;
#define MAX 256
int main()
{
	int ip=0,rs=0,i=0;
	char src[1000];
	char des[1000];
	int count[MAX]={0};
	cin>>src;
	while(*(src+ip))
	{
		if(count[*(src+ip)]==0)
		{
			*(des+rs)=*(src+ip);
			count[*(src+ip)]++;
			rs++;
		}
		ip++;
	}
	cout<<des<<"\n";
}