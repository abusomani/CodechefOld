#include<iostream>
using namespace std;
int main()
{
	long long t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<((n*(n-1)*(n-1))*2 + n*(n-1)*(n-2) + 2*n*(n-1)*(n-2)*(n-2))<<endl;
	}
}
