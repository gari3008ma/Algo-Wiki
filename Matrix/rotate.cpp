 #include <iostream>
using namespace std;
int rotate(int mat[50][50],int n,int m,int k)
{
    int dup[50][50],i,j,row=0,col=0,curr,prev,n1,m1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            dup[i][j]=mat[i][j];
    }
    n1=n;
    m1=m;
    while(k--)
    {
        row=0;
        col=0;
        n=n1;
        m=m1;
    while(row<n && col <m)
    {
        if(row+1==n || col+1==m)
          break;
          prev=mat[row+1][col];
          for(i=col;i<m;i++)
            {
                curr=mat[row][i];
                mat[row][i]=prev;
                prev=curr;
            }
            row++;
          for(i=row;i<n;i++)
          {
              curr=mat[i][m-1];
              mat[i][m-1]=prev;
              prev=curr;
          }
            m--;
          if(row<n)
          {
              for(i=m-1;i>=col;i--)
              {
                  curr=mat[n-1][i];
                  mat[n-1][i]=prev;
                  prev=curr;
              }
              
          }
          n--;
          if(col<m)
          {
              for(i=n-1;i>=row;i--)
              {
                  curr=mat[i][col];
                  mat[i][col]=prev;
                  prev=curr;
              }
              
          }
          col++;
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
    }
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m1;j++)
            {
              if(dup[i][j]!=mat[i][j])
              return 0;

            }
    }
    return 1;
}
int main()
 {
	int t,n,m,i,j,mat[50][50],k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	          cin>>mat[i][j];
	    }
	    cin>>k;
	    cout<<rotate(mat,n,m,k)<<"\n";
	}
	return 0;
}