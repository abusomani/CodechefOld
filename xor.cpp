#include<iostream>
#include<new>
using namespace std;
int main()
{
	long t,n,sum=0;
	int i,j,k;
	long long *a;
//	cin>>t;
	t=5;
	for(i=0;i<t;i++)
	{
	//	cin>>n;
	n=9;
		a=new long long[n];
		//for(j=0;j<n;j++)
	//	{
		//	cin>>a[j];
	//	}
		for(j=0;j<n;j++)
		{
			for(k=j+1;j<n;j++)
			{
				sum+=a[j]^a[k];
			}
		}
		cout<<sum;
		delete a;
	}
}
