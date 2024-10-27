 #include <iostream>
using namespace std;

int main()
{
	int t,i,j,n,m,mat[100][100],max_len;
	cin>>t;
	while(t--)
	{
			cin>>n>>m;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
					cin>>mat[i][j];
			}
			int row=0;
			int col=0;
			int lookup[100][100];
			max_len=INT_MIN;
			memset(lookup,0,sizeof(lookup));
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(i||j)
					{
						if(j>0 && mat[i][j]==mat[i][j-1]+1)
						{
							lookup[i][j]=max(lookup[i][j],lookup[i][j-1]+1);
							if(max_len < lookup[i][j])
							{
								max_len=lookup[i][j];
								row=i;
								col=j;
							}
						}
						if(i>0 && mat[i][j]==mat[i-1][j]+1)
						{
							lookup[i][j]=max(lookup[i][j],lookup[i-1][j]+1);
							if(max_len < lookup[i][j])
							{
								max_len=lookup[i][j];
								row=i;
								col=j;
							}
						}
					}
				}
			}
          cout << "Maximum length of Snake sequence is: "
         << max_len << endl;
 
    /*// find maximum length Snake sequence path
    list<Point> path = findPath(lookup, mat, row,col);
 
    cout << "Snake sequence is:";
    for (auto it = path.begin(); it != path.end(); it++)
        cout << endl << mat[it->x][it->y] << " ("
             << it->x << ", " << it->y << ")" ;
             */
	}
	return 0;
}