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

int DELETE,INSERT,REPLACE;
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j*INSERT;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i*DELETE; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = min(dp[i][j-1] + INSERT,  // Insert
                                   min(dp[i-1][j] + DELETE,  // Remove
                                   dp[i-1][j-1] + REPLACE)); // Replace
        }
    }
 
    return dp[m][n];
}

int main(){
    string str1,str2,new_str2 = "";
    cin>>str1>>str2;
    cin>>DELETE>>INSERT>>REPLACE;
    cout<<editDistDP(str1,str2,str1.size(),str2.size())<<endl;
    // cin>>str1>>str2;
    // int a[26],b[26];

    // rep(i,str1.size()){
    //     a[str1[i] - 'a'] ++; // increment char count for string a
    // }
    // rep(i,str2.size()){
    //     b[str2[i] - 'a'] ++;
    // }

    // rep(i,str2.size()){
    //     if(a[str2[i]-'a']){ // if this char is present in string1 , its count will be greater than 0
    //                         // remove this char from string2
    //     } 
    // }
    return 0;
}