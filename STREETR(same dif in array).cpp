#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)  return a;
	return gcd(b,a%b);
}
int abs(int a)
{
	return  (a>0)?a:-a;
}
int main()
{
	int n,dif1,dif2,flag=0,max,min;
	cin>>n;
	int a[n];
	cin>>a[0];
	cin>>a[1];
	dif1=abs(a[1]-a[0]);
	for(int i=2;i<n;i++)
	{
		cin>>a[i];
		dif2=abs(a[i]-a[i-1]);
		dif1=gcd(dif1,dif2);
	}
	max=a[0],min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
//	cout<<dif1<<endl;
	cout<<(max-min)/dif1 - n +1 <<endl;
}
