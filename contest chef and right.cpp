#include<iostream>
#include<string.h>
#include<math.h>
int mod=pow(10,9)+7;
using namespace std;
int main()
{int x ,i,j;
string s;
int n;
cin>>n;
while(n--)
{x=1;i=1;j=0;
cin>>s;
while(s[j]!='\0')
 {if(i%2!=0)
	{if(s[j]=='l')
		x=(2*x)%mod;
		else if(s[j]=='r')
		x=(2*(x+1))%mod;
	}
	else
	{if(s[j]=='l')
		x=(2*x-1)%mod;
		else if(s[j]=='r')
		x=(2*x+1)%mod;
	}
	i++;
	j++;
 }
 cout<<x<<endl;
}

return 0;
}
