#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--)
	{char str[1002];
	cin>>str;
	int i,flag=0;
	int a[26];
	for(i=0;i<26;i++)
	a[i]=0;
	for(i=0;i<strlen(str);i++)
		{int x=str[i]-97;
		a[x]++;
		}
	for(i=0;i<26;i++)
		{if(a[i]==i+1||a[i]==0)
			{
			}
		else
			flag=1;
		}
	if(!flag)
	cout<<"YES\n";
	else
	cout<<"NO\n";
	}
return 0;

}
