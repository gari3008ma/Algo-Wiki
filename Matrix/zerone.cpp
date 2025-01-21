 #include <iostream>
using namespace std;
int main()
{
	int t,n,i,j,k,mat[100][100],val;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
		   for(j=0;j<n;j++)
		       cin>>mat[i][j];
		}
		i=0;
		j=n-1;
		val=0;
			while(i<n && j>=0)
			{
			   if(mat[i][j]==0)
			   {
			       while(j>=0 && (mat[i][j]==0 || i==j))
			        j--;
			        if(j==-1)
			        {
			            val=i;
			            break;
			        }
			        else
			        i++;
			   }
			   else
			   {
			          while(i<n &&(mat[i][j]==1 || i==j))
			             i++;
			          if(i==n)
			          {
			               val=j;
			               break;
			          }   
			          else
			          j--;
			   }
			}
			cout<<val<<"\n";
	}
	return 0;
}