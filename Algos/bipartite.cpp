#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector < long long > vll;
typedef pair < long long, long long > pll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector<vi> vvi; 
typedef vector<pii> vpii;
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,a,n) for(int i = a; i < n; i++)
#define traverse(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define SIZE 5009
#define R 6
#define C 6
bool bipart(int mat[R][C],int u,bool seen[],int patner[])
{
	for(int i=0;i<C;i++)
	{
		if(mat[u][i] && !seen[i])
		{
			seen[i]=true;
			if(patner[i]<0 || bipart(mat,patner[i],seen,patner))
			{
				patner[i]=u;
				return true;
			}
		}
	}
	return false;
}
void match(int mat[R][C],int patner[])
{
           int total=4,count=0,i,j,current=0,spouse;
           bool seen[100];
           	       for(i=0;i<R;i++)
           	       {
           	       	     memset(seen,false,sizeof(seen));
           	       	     bipart(mat,i,seen,patner);
           	       }
           	       //cout<<"hello";
           
           for(i=0;i<R;i++)
           	cout<<patner[i]<<" ";
           cout<<"\n";
}
int main()
{
	int i,j,k;
    int bpGraph[R][C] = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };
 
    int patner[100];
    memset(patner,-1,sizeof(patner));
    match(bpGraph,patner);
 
    return 0;
}
