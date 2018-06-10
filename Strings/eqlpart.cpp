#include<bits/stdc++.h>
using namespace std;
void print(string str,int n)
{
	if(str.length()<n  || (str.length()%n!=0))
		cout<<"INvalide input \n";
	else
	{
		int k =  str.length()/n;
		cout<<k<<"\n";
		int i=0;
		while(i  <  str.length())
		{
			cout<<str.substr(i,k)<<"\n ";
			i=i+k;
		}
	}
}
int main()
{
	int n;
	string str;
	cin>>str;
	cin>>n;
	print(str,n);
	return 0;
}