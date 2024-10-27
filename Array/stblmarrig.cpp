 #include <iostream>
using namespace std;
#define n 4
bool isprei(int w,int prefer[2*n][n],int m,int m1)
{
	int i,ind1=-1,ind=-1;
	for(i=0;i<n;i++)
	{
		if(prefer[w][i]==m)
			{
				return true;
			}
		if(prefer[w][i]==m1)
			{
				return false;
			}
	}
}
void stableMarriage(int prefer[2*n][n])
{
    map<int,int> women;
    map<int,bool>men;
    int i;
    for(i=0;i<n;i++)
    {
    	men[i]=false;
    	women[i]=-1;
    }
    int freemen = n,w,j;
    while(freemen>0)
    {
    	for(i=0;i<n;i++)
    	{
    		if(men[i]==false)
    			break;
    	}
   			 for(j=0;j<n && men[i]==false;j++)
    		{
    			    w=prefer[i][j];
    				if(women[w-n]==(-1))
    				{
    						women[w-n]=i;
    						men[i]=true;
    			            freemen--;
    				}
    				else
    				{
    					if(isprei(w,prefer,i,women[w-n]))
    					{
    						women[w-n]=i;
    						men[i]=true;
    						men[women[w-n]]=false;
    					}
    				}
    		}
    }
    for(i=0;i<(n);i++)
    	cout<<i<<" has men "<<women[i]<<"\n";
}
int main()
{
	
	int prefer[2*n][n] = { {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };
    stableMarriage(prefer);
 
    return 0;
}