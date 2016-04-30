#include<iostream>
using namespace std;
int main()
{ios_base::sync_with_stdio(false);
int a=0,b=0;
cin>>a>>b;
int diff=a-b;
if(diff%10==1||diff%10==0)
cout<<diff+1;
else
cout<<diff-1;
return 0;
}
