 #include <iostream>
using namespace std;
#define MAX 256
int main()
{
	int t,i,j,wr,wl,maxwin,n;
	string str;
	cin>>t;
	while(t--)
	{
			cin>>str;
         int count[MAX+1]={-1};
         count[str[0]]=0;
         int curr=1,prev=0;
         n=str.length();
         maxwin=0;
        for(i=1;i<n;i++)
        {
        		prev = count[str[i]];
        		if(prev==-1  || (i-curr)>prev)
        			 curr++;
        	    else
        	    {
        	    	if(maxwin < curr)
        	    		maxwin=curr;
        	    	curr=i-prev;
        	    }	
        	    count[str[i]]=i;	
        }
         cout<<maxwin<<"\n";
         str.length();
	}
	return 0;
}
