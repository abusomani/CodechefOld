#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
	return b;
	
	else if(b==0)
	return a;
	
	else
		gcd(b,a%b);
}
long long lcm(int a,int b)
{
	return (a*b/gcd(a,b));
}
int main()
{int n,x,max=-1;
cin>>n;
int a[1000007]={0};
for(int i=0;i<n;i++)
	{
	cin>>x;
	if(max<x)
	max=x;
	a[x]++;
	}
long long answer=n*(n-1)/2;
for(int i=0;i<max+1;i++)
	{
		if(a[i]>1)
			{
				answer=answer-(a[i]*(a[i]-1)/2);
			}
	}	
cout<<answer<<endl;


	return 0; 
}
