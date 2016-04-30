#include<bits/stdc++.h>
using namespace std;
int main()
{
long long a;
cin>>a;
if(a%3==0)
cout<<"yes";
else if(a%3==1&&a%2==1)
cout<<"yes";
else
cout<<"no";
return 0;
}
