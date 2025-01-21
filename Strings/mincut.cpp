 #include <iostream>
using namespace std;
#define m 50000
bool ispal(string str)
{
	int l=0,h=str.length(),i;
	while(l<h)
	{
	     if(str[l]!=str[h])
	     	return false;
	     	l++;
	     	h--;
	}
	return true;
}
int partition(string str,int start,int end)
{
	cout<<start<<" "<<end;
	if(start==end)
       return 0;
	if(start>end)
		return m;
	if(ispal(str.substr(start,end-start+1)))
	    return 0;
	if((end-start+1)==2)
	   return 1;
	 int mi=INT_MAX;
	 int count;
	   for(int i=start;i<=end;i++)
	   {
	   				count=1+partition(str,start,i)+partition(str,i+1,end);
	   				mi=min(mi,count);
	   }
	   return mi;
}
int main()
{
	string str;
	cin>>str;
	cout<<partition(str,0,str.length()-1);
	return 0;
}