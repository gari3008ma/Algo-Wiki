 #include <iostream>
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
#define M 3
#define N 3
 
// Let the given dictionary be following
string dic[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dic)/sizeof(dic[0]);
bool ispresent(string & str)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(str.compare(dic[i])==0)
			return true;
	}
	return false;
}
void dfsutil(char boggle[M][N],bool visited[M][N],int row,int col,string & str)
{
	visited[row][col]=true;
	str=str+boggle[row][col];
	if(ispresent(str))
		cout<<str<<"\n";
	for(int i=row-1;i<=row+1 && i<M ;i++)
	{
		for(int j=col-1;j<=col+1 && j<N ;j++)
		{
			if(i>=0 && j>=0 && !visited[i][j])
				dfsutil(boggle,visited,i,j,str);
		}
	}
	str.erase(str.length()-1);
	visited[row][col]=false;
}
void boggledfs(char boggle[M][N])
{
	bool visited[M][N]={{false}};
	int i,j;
	string str="";
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			dfsutil(boggle,visited,i,j,str);
		}
	}
}
int main()
{
	
 char boggle[M][N] = {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};
 
    cout << "Following words of dictionary are present\n";
    boggledfs(boggle);
    return 0;
}
