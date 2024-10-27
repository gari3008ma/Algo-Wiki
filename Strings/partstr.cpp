 #include <iostream>
using namespace std;
int main()
{
       int t,i,j,n;
       cin>>t;
       while(t--)
       {
       	     string str,str1,x,y,res;
       	     cin>>str>>str1;
       	     bool flag=false;
       	     n=str.length();
             res=str+str;    
       	     	     //res=y+x;
       	     	     if(strstr(res,str))
       	     	     	flag=true;
       	     	     res.clear();
       	     
       	     if(flag)
       	     	cout<<"Yes\n";
       	     else
       	     	cout<<"No\n";
       }
       return 0;
}