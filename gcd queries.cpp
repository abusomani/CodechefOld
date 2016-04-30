#include<bits/stdc++.h>
#include<stdio.h>
 
 
using namespace std;
int gcd(int n,int m)
	{ if(m<=n && n%m == 0)
	   return m;
	  if(n < m)
	   return gcd(m,n);
	  else
	   return gcd(m,n%m);
	 }
int main()
{ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--)
	{int n,q;
	int a[100007],g[100007],f[100007];
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	g[0]=1;f[n+1]=1;
	g[1]=a[1];
	f[n]=a[n];
	for(int i=2;i<=n;i++)
		{
		g[i]=gcd(g[i-1],a[i]);
		f[n-i+1]=gcd(f[n-i+2],a[n-i+1]);
		}
	
while(q--)
		{int l,r,tmp=1;
		cin>>l>>r;	
		if(l==1)
		cout<<f[r+1]<<endl;
		else if(r==n)
		cout<<g[l-1]<<endl;
		else
		{
		tmp=gcd(g[l-1],f[r+1]);
		 cout<<tmp<<endl;
		}
		}
	}
	return 0;
} 
