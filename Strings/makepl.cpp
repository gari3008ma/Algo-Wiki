

 #include <iostream>
using namespace std;
int main()
{
	int t,i,j=0;
	cin>>t;
	while(t--)
	{
		string str,ptr,ptr1;
	cin>>str;
	int count[300];
	char ch,l;
	memset(count,0,sizeof(count));
	for(i=0;i<str.length();i++)
	  count[str[i]]++;
	j=0;
	for(i=0;i<300;i++) 
	{
		if(count[i]%2!=0)
           j++;
	}
	if(j>1)
	{
		cout<<"Notpossible\n";
	}
	else
	{
		for(i=0;i<300;i++)
		{
                 if(count[i]%2==0)
                 {
                 	while(count[i])
                 	{
                 		ch=i;
                 		ptr=ptr+ch;
                 		count[i]--;
                 		ptr1=ptr1+ch;
                 		count[i]--;
                 	}
                 }
                 else
                 {
                 	l=i;
                 	while(count[i]>1)
                 	{
                 		ch=i;
                 		ptr=ptr+ch;
                 		count[i]--;
                 		ptr1=ptr1+ch;
                 		count[i]--;
                 		
                 	}
                 }
		}
			reverse(ptr1.begin(),ptr1.end());
			ptr=ptr+l;
			ptr=ptr+ptr1;
			cout<<ptr<<"\n";
	}
}
}