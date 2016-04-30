#include<bits/stdc++.h>
using namespace std;
int main()
{int n,k;
cin>>n>>k;
int a[n+1],count=0;
for(int i=1;i<=n;i++)
a[i]=0;
while(k--)
	{
	string s;
	cin>>s;
	
		if(s[4]!='E')
			{
				int pos=s[5]-'0';
					if(a[pos]==1)
						count--;
					else
						{
							a[pos]++;
							count++;
						}
			}
		else
			{
				for(int i=1;i<=n;i++)
					a[i]=0;
				count=0;	
			}
		cout<<count<<endl;
	}

	
	return 0;
}
