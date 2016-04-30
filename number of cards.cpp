#include<iostream>
#include<string.h>
#define m 1000007
using namespace std;
int main()
{
	long long i,t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long k=(n%m)*((n+1)%m) + (((n-1)%m)*(n%m))/2;
		cout<<k%m<<endl; 
	}
}
