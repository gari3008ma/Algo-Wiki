#include<bits/stdc++.h>
using namespace std;
#define MAX 256
int main()
{
	int ip=0,i=0;
	char src[]="test string";
	char des;
	 int *count = (int *)calloc(MAX, sizeof(int));
	//cin>>src;
	//string::iterator it=src.begin();
	while(*(src+ip))
	{
			count[*(src+ip)]++;
		ip++;
	}
	for(i=0;i<=MAX;i++)
	{
		if(count[i]>1)
			{
					des=i;
					cout<<des;
			}
	}
	cout<<"\n";
}