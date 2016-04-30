#include<iostream>
using namespace std;
int abs(int a)
{
	return (a>0)?a:-a;
}
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
int main()
{
	int t,i,sum=0,temp;
	int n;
	cin>>n;
	int h[n],w[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i]>>w[i];
	}
	sum=w[0]+h[0];
	for(i=1;i<n;i++)
	{
		if(w[i]+h[i]+abs(h[i]-h[i-1]) >	h[i]+w[i]=abs(w[i]-h[i-1]))
			sum+=w[i]+h[i];
	}
}
