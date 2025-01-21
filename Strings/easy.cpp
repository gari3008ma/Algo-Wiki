 #include <iostream>
using namespace std;
bool ispal(char str[])
{
	int len=strlen(str);
	char *s=str;
	char *l=str+len-1;
	while(s<l)
	{
		if((*s)!=(*l))
			return false;
		s++;
		l--;
	}
	return true;
}
int issub(char str[])
{
	if(ispal(str))
		return 0;
	str++;
	return 1+issub(str);
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		char str[1000];
		cin>>str;
		cout<<issub(str)<<"\n";
	}
}