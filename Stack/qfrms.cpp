#include<bits/stdc++.h>
using namespace std;
void enque(int x,stack<int> s1)
{
	s1.push(x);
}
int deq(stack<int> s1)
{
		if(s1.empty())
			return -1;
		if(s1.size()==1)
			return s1.top();
		int x=s1.top();
		s1.pop();
         int res=deq(s1);
         s1.push(x);
         return res;
}
int main()
{
	stack<int> s1;
	for(int i=1;i<4;i++)
			enque(i,s1);
	cout<<deq(s1);
	return 0;
}