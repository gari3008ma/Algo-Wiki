 #include <iostream>
#include<string>
using namespace std;
int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
int main()
{
	int t,n,arr[100],i,j;
	string p;
	vector<string> vi;
	cin>>t;
	while(t--)
	{
	     cin>>n;
	     for(i=0;i<n;i++)
	     {
	        cin>>arr[i];
	        stringstream convert; // stringstream used for the conversion

          convert << arr[i];//add the value of Number to the characters in the stream

           p = convert.str();
	        vi.push_back(p);
	     }
        sort(vi.begin(),vi.end(),myCompare);
        for(i=0;i<n;i++)
        {
        	cout<<vi[i];
        }
        cout<<"\n";
        vi.clear();
	}
}