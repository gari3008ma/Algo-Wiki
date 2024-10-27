 #include <iostream>
using namespace std;
int n,n1,size1=0,size2=0,arr[1000];
bool isfull1()
{
	if(size1==size2)
		return true;
	else
		return false;
}
bool isfull2()
{
	if(size2==size1)
		return true;
	else
		return false;
}
bool isempty1()
{
	if(size1==(-1))
		return true;
	else
		return false;
}
bool isempty2()
{
	if(size2==n)
		return true;
	else
		return false;
}
void push1(int key)
{
      if(isfull1())
      	return ;
       size1++;
      arr[size1]=key;
      //cout<<arr[size1]<<" ";
     
}
void push2(int key)
{
	   if(isfull2())
	   	   return ;
	   	size2++;
	   	arr[size2]=key;
	   	//cout<<arr[size2]<<" ";   	
}
int pop2()
{
	   if(isempty2())
	   	  return -1;
	   	int t=size2;
	   	size2=size2-1;
	   	return arr[t];
}
int pop1()
{
	   if(isempty1())
	   	  return -1;
	   	int t=size1;
	   	size1=size1-1;
	   	return arr[t];
}
int main()
{
    int i,j,arr[1000];
    cin>>n;
   n1=n/2;
   size1=-1;size2=n;
  push1(1);
  cout<<pop1()<<" \n";
  push2(4);
  cout<<pop2()<<" \n";
  push2(6);
  push2(9);
  cout<<pop2()<<" \n";
	return 0;
}