 #include <iostream>
using namespace std;
void printpath(vector<int> path,int mat[1000][1000],int u,int v,int i,int j)
{
        if(i<0 || i>=u || j>=v || j<0)
 		return ;
	path.push_back(mat[i][j]);
        if(i==u-1)
       {
		for(int k1=j+1;k1<v;k1++)
			path.push_back(mat[i][k1]);
		for(int k=0;k<path.size();k++)
			cout<<path[k]<<" ";
		cout<<"\n";
		return;
	}
	if(j==v-1)
       {
		for(int k1=i+1;k1<u;k1++)
			path.push_back(mat[k1][j]);
		for(int k=0;k<path.size();k++)
			cout<<path[k]<<" ";
		cout<<"\n";
		return;
	}
	
	printpath(path,mat,u,v,i+1,j);
	printpath(path,mat,u,v,i,j+1);
}
int main()
{
	int t,n,j,i,mat[1000][1000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>mat[i][j];	
		vector<int> path;
		printpath(path,mat,n,n,0,0);
	}
}
