#include<bits/stdc++.h>
using namespace std;
int isPalin(long long n)
{
	long long temp=0,x=n;
	while(x!=0)
		{
			temp=temp*10+x%10;
			x/=10;
		}
	if(n==temp)
	return 1;
	else
	return 0;
}
int main()
{int a[100007]={0};
for(int i=0;i<100007;i++)
	{
		if(isPalin(i))
		{
			a[i]=1;
		}
	}
int t;
cin>>t;
while(t--)
	{
		int n;
		cin>>n;
		for(int i=n+1;;i++)
			{
				if(a[i]==1)
					{
						cout<<i<<endl;
						break;
					}
			}
	}
	
	return 0;
}
