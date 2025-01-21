 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,k,arr[1000],res;
	string frst,scnd,str,tm;
	char tmp;
	cin>>t;
	while(t--)
	{
		cin>>str;
		i=0;
		if(str.length()==1)
			cout<<"Yes\n";
		else
		{
			cout<<"Yes\n";
			frst=str[i];
			i++;
			scnd=str[i];
			i++;
			while(i<str.length())
			{
				tm=scnd;
				reverse(tm.begin(),tm.end()); 
				if(frst==tm)
					printf("Yes\n");
				else
					printf("No\n");
				//cout<<" "<<frst<<" "<<scnd<<"\n";
				if(i%2==0)
				{
					tmp=scnd[0];
					//cout<<scnd<<" ";
					scnd.erase(scnd.begin());
					//cout<<scnd<<"\n";
				}
				else
				{
					frst.insert(frst.end(),tmp);
				}
				scnd.insert(scnd.end(),str[i]);
				i++;
			}
			//cout<<" "<<frst<<" "<<scnd<<"\n";
			tm=scnd;
				reverse(tm.begin(),tm.end()); 
			if(frst==tm)
					printf("Yes\n");
				else
					printf("No\n");
		}
	}
	return 0;
}