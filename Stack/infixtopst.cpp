#include<bits/stdc++.h>
using namespace std;
bool isoperand(char c)
{
	if('a'<=c&& c<='z'  || ('A'<=c && c<='Z'))
		return true;
	else
		return false;
}
int valtype(char c)
{
	switch(c)
	{
		case '+':  return 1;
					
		case '-':  return 1;
						
	    case '*':  return 2;
						
		case '%':  return 2;
				
		case '^':  return 3;
							
		case '/':  return 2;																				
	}
	return -1;
}
int main()
{
	int t,n,i=0;
	char c;
	string arr;
	stack<char> q2;
	queue<char> q1;
	cin>>arr;
	while(arr[i])
	{
		c= arr[i];
		if(isoperand(c))
			{
				q1.push(c);
				if(!q2.empty()&&q2.top()=='^')
			{
				q1.push(q2.top());
				q2.pop();
			}
			}
		else
		{
			if(q2.empty())
				q2.push(c);
			else if(c=='(')
				q2.push(c);
			else if(c==')')
			{
				while(!q2.empty() && q2.top()!='(')
				{
						q1.push(q2.top());
						q2.pop();
				}
				q2.pop();
			}
			else if(!q2.empty() &&valtype(c)>valtype(q2.top()))
				q2.push(c);
			else if(!q2.empty() && valtype(c)<=valtype(q2.top()))
			{
				while(!q2.empty() && valtype(c)<=valtype(q2.top()))
				{
					q1.push(q2.top());
					q2.pop();
				}
				q2.push(c);
			}
			else
				q2.push(c);
		}
		i++;
	}
	while(!q2.empty())
	{
		q1.push(q2.top());
		q2.pop();
	}
      while(!q1.empty())
      {
      	cout<<q1.front();
      	q1.pop();
      }
}