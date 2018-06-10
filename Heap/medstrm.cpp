#include<bits/stdc++.h>
using namespace std;
int signum(int a,int b)
{
    if(a > b)
      return 1;
     else if(b > a)
       return -1;
     else
       return 0;
}
int getmedian(int val,int & median,priority_queue<int> &l,priority_queue<int ,vector<int>,greater<int> > &r)
{
    int s=signum(l.size(),r.size());
    switch(s)
    {
        case 1:
        if(val < median)
        {
            r.push(l.top());
            l.pop();
            l.push(val);
        }
        else
        {
            r.push(val);
        }
        median=(l.top()+r.top())/2;
        break;
        case 0:
        if(val < median)
        {
            l.push(val);
            median=l.top();
        }
        else
        {
            r.push(val);
            median =r.top();
        }
        break;
        case -1:
        if(val < median)
        {
            l.push(val);
        }
        else
        {
            l.push(r.top());
            r.pop();
            r.push(val);
        }
        median=(l.top()+r.top())/2;
        break;
    }
    return median;
}
int main()
 {
	int n,ele,m;
	priority_queue<int> *l;
	priority_queue<int ,vector<int>,greater<int> > *r;
		priority_queue<int> maxheap;
	priority_queue<int ,vector<int>,greater<int> > minheap;
	l=&maxheap;
	r=&minheap;
	cin>>n;
	m=0;
	while(n--)
	{
	    cin>>ele;
	    cout<<getmedian(ele,m,*l,*r)<<"\n";
	}
	return 0;
}