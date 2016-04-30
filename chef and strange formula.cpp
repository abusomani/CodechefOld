#include<bits/stdc++.h>
using namespace std;
#define SIZE 10000007
long long factorialcomputewithmod(long long a[],long long m )
{	a[0]=1;
long long x,y;
	for(int i=1;i<SIZE;i++ )
		{
			a[i]=i*a[i-1]%m;
			a[i]=((i+1)*a[i]-1)%m;
			x=i*i%m;
			y=x*i%m;
			a[i]=(a[i]+(x+y)/2)%m;
			cout<<a[i];
		}
}
int main()
{
	int n,m;
	cin>>n>>m;
	long long a[SIZE],sum=0,p;
	factorialcomputewithmod(a,m);
	for(int i=0;i<n;i++)
	{
		cin>>p;
		//if(p>SIZE)
			
		
	}
	
}
