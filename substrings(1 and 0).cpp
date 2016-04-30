#include<iostream>
using namespace std;
int main()
{int t,len,count;
cin>>t;
while(t--)
{string s;
cin>>s; 
count=0;
for( len=0;s[len]!='\0';len++);
for(int i=0;i<len;i++)
{if(s[i]=='1')
count++;
}
}
int ans=((count)*(count+1))/2;
cout<<ans;
return 0;
}
