
 #include <iostream>
using namespace std;
bool ispal(char str[],int s,int e)
{
	if(s==e)
		return true;
	s++;
	e--;
	return (str[s]==str[e] && ispal(str,s,e));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char str[1000];
		cin>>str;
		if(ispal(str,0,strlen(str)-1))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}