#include<bits/stdc++.h>
using namespace std;
void swap(char * a,char *b)
{
	char tmp;
	tmp=(*a);
	(*a)=(*b);
	(*b)=tmp;
}
void print(string str,int low,int high)
{
	if(low==high)
		cout<<str<<"\n";
	for(int i=low;i<high;i++)
	{
		swap(&str[i],&str[low]);
		print(str,low+1,high);
		swap(&str[i],&str[low]);
	}
}
int main()
{

	string str;
	cin>>str;
	print(str,0,str.length());
	return 0;
}