#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	int i;
	for(i=(a>b)?b:a;i>=1;i--)
	if(a%i==0  &&  b%i==0) return i;
}
int main()
{
	int t,i,j,acut,mins,minr,count=0;
	long int n;
	cin>>t;
	int rc[t],ac[t];
	for(i=0;i<t;i++)
	{
		cin>>n>>mins>>minr;
		long *s=new long[n];
		long *r=new long[n];
		for(j=0;j<n;j++)
		{
			cin>>s[j]>>r[j];
		}
		cin>>acut;
		for(j=0;j<n;j++)
		{
			if(s[j]>mins || r[j]>minr)
			count++; 
		}
		rc[i]=(count/gcd(count,acut));
		ac[i]=(acut/gcd(count,acut));
		delete[] s;
		delete[] r;
	}
	for(i=0;i<t;i++)
	cout<<rc[i]<<"/"<<ac[i]<<endl;
}
