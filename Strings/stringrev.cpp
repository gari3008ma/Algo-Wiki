 #include <iostream>
using namespace std;
void reverse(char *start,char * end)
{
	char temp,*i;
	char *a=start,*b=end;
	while(start<end)
	{
		temp= (*start);
		(*start)=(*end);
		(*end )=temp;
		start++;
		end--;
	}
}
void rev(char * a)
{
	char *tmp=a,*start=a;
	while((*tmp)!=NULL)
	{
		tmp++;
		if((*tmp)=='\0')
		{
			reverse(start,tmp-1);
			cout<<a<<"\n";
		}
		else if((*tmp)==' ')
		{
			reverse(start,tmp-1);
			cout<<a<<"\n";
			start=tmp+1;
		}
		
	}
	
	reverse(a,tmp-1);
	
}
int main()
{
	char s[100];
	cin>>s;
	rev(s);
    cout<<s;
	return 0;
}