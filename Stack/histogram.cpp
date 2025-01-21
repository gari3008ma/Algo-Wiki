 #include <iostream>
using namespace std;
int main()
{
	int t,n,arr[1000],i,j,max_area,curr_area;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>arr[i];
		stack<int> st;
		i=0;
		max_area=INT_MIN;
		while(i<n)
		{
				if(st.empty() || (arr[st.top()]<=arr[i]))
					st.push(i++);
				else
				{
					j=st.top();
					st.pop();
					curr_area=arr[j]*(st.empty()?i:(i-st.top()-1));
					if(curr_area >  max_area)
						  max_area=curr_area;
				}
		}
		while(!st.empty())
		{
			j=st.top();
					st.pop();
					curr_area=arr[j]*(st.empty()?i:(i-j-1));
					if(curr_area >  max_area)
						  max_area=curr_area;
		}
		cout<<max_area<<"\n";
	}
}