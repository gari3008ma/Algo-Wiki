 #include <iostream>
using namespace std;
void printsort(int mat[100][100],int n,int s)
{
            int i,j,k=s,l,sum=0,l1=n-s+1,l3=n-s+1;
            if(k>n)
            	return ;
            for(i=0;i<l3;i++)
            {
            	for(j=0;j<l1;j++)
            	{
            	     sum=0;
            	     cout<<i<<" "<<j;
            		for(k=i;k<i+s;k++)
            		{
            			for(l=j;l<j+s;l++)
            				sum+=mat[k][l];
            		}
            		cout<<sum<<" ";
            	}
            	cout<<endl;
            }
}
int main()
{
	int t,n,i,j,m,mat[100][100],s;
	cin>>t;
	while(t--)
	{
	   cin>>n>>s;
	   for(i=0;i<n;i++)
	   {
	   		for(j=0;j<n;j++)
	   		    cin>>mat[i][j];
	   }
	   printsort(mat,n,s);
	}
}