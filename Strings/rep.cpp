 #include <iostream>
using namespace std;
#define MAX 256
struct count
{
	int val;
	int index;
};
int print(string str)
{
  struct count *c=(struct count *)calloc(sizeof(struct count),MAX);
  int i,j,n;
  for(i=0;i<str.length();i++)
  {
  			c[str[i]].val++;

  }        
}
int main()
{
	int n;
	string str;
	cin>>str;
	cout<<print(str);
	return 0;
}