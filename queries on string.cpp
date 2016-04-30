#include<bits/stdc++.h>
using namespace std;
int nc2(int a)
{if(a==0)
	return 0;
	else
	return (a*(a-1))/2;
}
void divisible(int a[100007],int p,int q)
	{
		int count1=0,count2=0,count0=0;
				int total[100007];
				total[0]=0;
				for(int i=1;i<=q-p+1;i++)
					{
					total[i]=(total[i-1]+a[p+i-1])%3;
					if(total[i]%3==0)
						count0++;
					else if(total[i]%3==1)
						count1++;
					else
						count2++;
					}
				long long sum=nc2(count0+1)+nc2(count1)+nc2(count2);
				
		cout<<sum<<endl;
	}
int main()
{ios_base::sync_with_stdio(false);
int n,m;
cin>>n>>m;
string s;
int a[100007];
a[0]=0;
for(int i=1;i<=n;i++)
{
cin>>s[i];
a[i]=s[i]-'0';
}
while(m--)
	{int z,p,q;
	cin>>z;
	if(z==1)
		{cin>>p>>q;
		a[p]=q;
		}
	else if(z==2)
		{	cin>>p>>q;
			divisible(a,p,q);
		}
	}
	return 0;
}
