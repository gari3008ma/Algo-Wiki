#include<bits/stdc++.h>
using namespace std;
#define N 8
bool  MATRIX[N][N] = {{0, 0, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 1, 0}};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}
int celeb(int n)
{
	stack<int> st;
	int a,b,c,i;
	for(i=0;i<n;i++)
		st.push(i);
	    a=st.top();
		st.pop();
		b=st.top();
		st.pop();
	while(st.size()>1)
	{
		
		if(knows(a,b))
		{
			a=st.top();
			st.pop();
		}
		else
		{
			b=st.top();
			st.pop();
		}
	}

	    c=st.top();
	    st.pop();
	    if(knows(c,b))
		{
			c=b;
		}
		if(knows(c,a))
		{
			c=a;
		}
		for(i=0;i<n;i++)
		{
			if(i!=c &&(knows(c,i) || !knows(i,c)))
				return -1;
		}
		return c;
}
int main()
{
	  
	  cout<<celeb(4);
	  return 0;
}