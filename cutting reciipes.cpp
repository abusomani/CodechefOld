#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define mod 100005
int gcd(int a,int b)
{
	if(a==0)
	return b;
	
	else if(b==0)
	return a;
	
	else 
	return gcd(b,a%b);
}
int main()
{ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		{
			int n;
			cin>>n;
			int a[n],common,flag=0,b[n];
			for(int i=0;i<n;i++)
				{
					cin>>a[i];
					b[i]=a[i];
					if(i==0)common=a[i];
					
					else
					common=gcd(a[i],common);
				}
			for(int i=0;i<n;i++)
				{
					if(a[i]%common!=0)
						{
							flag=1;
							break;
						}
					else
						{
							b[i]/=common;
						}
				}
			if(flag)
				{
					for(int i=0;i<n-1;i++)
						cout<<a[i]<<" ";
					cout<<a[n-1]<<endl;
				}
			else
				{for(int i=0;i<n-1;i++)
						cout<<b[i]<<" ";
					cout<<b[n-1]<<endl;
				
					
				}
		}
	return 0;
}
